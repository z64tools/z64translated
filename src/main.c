#define TRANSLATED_C
#include "translated.h"

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

int main(int n, const char** arg) {
    const char* input = NULL;
    const char* output = NULL;
    const char* fm = NULL;
    int i = 0;
    const char* usage = "z64translated --i <msg.tsv> --o <message.h> --fmt base-msg.toml";
    
    if ((i = strarg(arg, "b")))
        fm = arg[i];
    else errr("no fmt file provided!\n%s", usage);
    
    if ((i = strarg(arg, "i")))
        input = arg[i];
    else errr("no input provided!\n%s", usage);
    
    if ((i = strarg(arg, "o")))
        output = arg[i];
    else errr("no output provided!\n%s", usage);
    
    info_title("z64translated", NULL);
    
    Toml toml = Toml_New();
    Memfile input_nsv = Memfile_New();
    Memfile output_tbl = Memfile_New();
    Memfile output_data = Memfile_New();
    State* ctx = State_New(&output_tbl, &output_data, &toml);
    
    Toml_Load(&toml, fm);
    Memfile_LoadStr(&input_nsv, input);
    Memfile_Alloc(&output_tbl, MbToBin(0.5f));
    Memfile_Alloc(&output_data, MbToBin(0.5f));
    
    const char* line = input_nsv.str;
    int num = Toml_ArrItemNum(&toml, "entry");
    
    time_start(2);
    
    for (var i = 0; i < num; i++) {
        ctx->entry_index = i;
        ctx->msg_index = Toml_GetInt(&toml, "entry[%d].index", i);
        ctx->msg_type_pos = Toml_GetInt(&toml, "entry[%d].type_pos", i);
        ctx->item_num = Toml_ArrItemNum(&toml, "entry[%d].item", i);
        
        if (ctx->msg_index == 0xFFFC)
            break;
        
        for (var k = 0; k < ctx->item_num; k++) {
            ctx->item_index = k;
            
            Message_HandleItem(ctx, x_cpyline(line, 0));
            line = strline(line, 1);
        }
    }
    Message_End(ctx);
    
    const char* raw_filename = x_fmt("%s%s", x_path(output), x_basename(output));
    
    if (striend(output, ".bin") || striend(output, ".tbl"))
        Memfile_SaveBin(&output_tbl, x_fmt("%s.tbl", raw_filename) ),
        Memfile_SaveBin(&output_data, x_fmt("%s.bin", raw_filename) );
    
    else if (striend(output, ".h") || striend(output, ".c"))
        Message_C(ctx, x_fmt("%s.h", raw_filename) );
    
    else
        Memfile_SaveBin(&output_tbl, x_fmt("%s.tbl", raw_filename) ),
        Memfile_SaveBin(&output_data, x_fmt("%s.bin", raw_filename) ),
        Message_C(ctx, x_fmt("%s.h", raw_filename) );
    
    State_Delete(ctx);
    Memfile_Free(&input_nsv);
    Memfile_Free(&output_tbl);
    Memfile_Free(&output_data);
    Toml_Free(&toml);
    
    info(
        "input:  %32s\n"
        "format: %32s\n"
        "output: %32s\n"
        "time:   %30.2fms",
        input, fm, output, time_get(2) * 1000.0f);
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

static int Message_WriteByte(State* this, u32 num, ...) {
    va_list va;
    
    va_start(va, num);
    for (var i = 0; i < num; i++) {
        u8 byte = va_arg(va, int);
        
        Memfile_Write(this->data, &byte, 1);
    }
    va_end(va);
    
    return num;
}

#ifndef __clang__
#define Message_WriteByte(ctx, ...) Message_WriteByte(ctx, NARGS(__VA_ARGS__), __VA_ARGS__)
#endif

static int Message_WriteStr(State* this, const char* str) {
    int len = 0;
    
    for (; *str; str++) {
        if (0xf0 == (0xf8 & *str))
            str += 4;
        else if (0xe0 == (0xf0 & *str))
            str += 3;
        else if (0xc0 == (0xe0 & *str)) {
            for (var i = 0; i < ArrCount(sSpcCharMap); i++) {
                if (!memcmp(sSpcCharMap[i][0], str, 2)) {
                    Message_WriteByte(this, *sSpcCharMap[i][1]);
                    len++;
                    
                    break;
                }
            }
            
            str += 2;
        } else {
            _assert(*str != '\n');
            
            Message_WriteByte(this, *str);
            len++;
        }
    }
    
    return len;
}

State* State_New(Memfile* tbl, Memfile* data, Toml* toml) {
    State* ctx = new(State);
    
    ctx->tbl = tbl;
    ctx->data = data;
    ctx->toml = toml;
    
    return ctx;
}

void State_Delete(State* this) {
    vfree(this);
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

static Item* Item_New(State* this) {
    Item* item = new(Item);
    const char* type = Toml_GetStr(this->toml, "entry[%d].item[%d].box_type", this->entry_index, this->item_index);
    int num_ctrl = Toml_ArrItemNum(this->toml, "entry[%d].item[%d].ctrl_type", this->entry_index, this->item_index);
    int num_pos = Toml_ArrItemNum(this->toml, "entry[%d].item[%d].ctrl_pos", this->entry_index, this->item_index);
    int num_val = Toml_ArrItemNum(this->toml, "entry[%d].item[%d].ctrl_val", this->entry_index, this->item_index);
    
    _log("%04X", this->msg_index);
    _log("entry[%d].item[%d]", this->entry_index, this->item_index);
    _assert(num_pos == num_ctrl);
    
    for (; item->type < ArrCount(sBoxType); item->type++)
        if (sBoxType[item->type])
            if (!strcmp(type, sBoxType[item->type]))
                break;
    
    _assert(item->type < ArrCount(sBoxType));
    _log("type:     %s", sBoxType[item->type]);
    vfree(type);
    
    item->vlen = Toml_GetInt(this->toml, "entry[%d].item[%d].vanilla_strlen", this->entry_index, this->item_index);
    _log("strlen:   %d", item->vlen);
    
    item->ctrl = new(Control[num_ctrl]);
    item->num_ctrl = num_ctrl;
    for (var i = 0; i < num_ctrl; i++) {
        type = Toml_GetStr(this->toml, "entry[%d].item[%d].ctrl_type[%d]", this->entry_index, this->item_index, i);
        item->ctrl[i].pos = Toml_GetInt(this->toml, "entry[%d].item[%d].ctrl_pos[%d]", this->entry_index, this->item_index, i);
        item->ctrl[i].pos /= item->vlen;
        
        for (; item->ctrl[i].type < CTRL_MAX; item->ctrl[i].type++)
            if (sCtrlType[item->ctrl[i].type])
                if (!strcmp(type, sCtrlType[item->ctrl[i].type]))
                    break;
        _assert(item->ctrl[i].type < CTRL_MAX);
        vfree(type);
        
        if (i < num_val)
            item->ctrl[i].value = Toml_GetInt(this->toml, "entry[%d].item[%d].ctrl_val[%d]", this->entry_index, this->item_index, i);
    }
    
    if (item->type == BOX_SCROLL) {
        item->delay = Toml_GetInt(this->toml, "entry[%d].item[%d].break_delay", this->entry_index, this->item_index);
        _log("delay:    %d", item->delay);
    }
    
    _log("item ok");
    
    return item;
}

static void Item_Delete(Item* item) {
    vfree(item->ctrl, item);
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

static f32 Message_GetWidth(const char* word) {
    f32 w = 0.0f;
    
    for (; *word; word++)
        w += sFontWidths[(u8)(*word)];
    return w;
}

static void Message_NewEntry(State* this) {
    MsgEntryBE entry = {};
    
    this->marked_choice = false;
    
    Memfile_Align(this->data, 4);
    entry.segment = this->data->seekPoint | 0x07000000;
    entry.text_index = this->msg_index;
    entry.pos = this->msg_type_pos & 0xF;
    entry.type = this->msg_type_pos >> 4;
    this->nl_num = 0;
    this->width_add = 0.0f;
    
    Memfile_Write(this->tbl, &entry, sizeof(entry));
}

static void Message_NewItem(State* this, Item* item) {
    switch (item->type) {
        case BOX_ENTRY:
            _assert("something has gone truly wrong" == NULL);
            break;
        case BOX_BREAK:
            Message_WriteByte(this, CTRL_BOX_BREAK);
            this->nl_num = 0;
            break;
        case BOX_CHOICE:
            if (!this->marked_choice) {
                this->marked_choice = true;
                
                if ((this->item_num - this->item_index) == 2) {
                    
                    if (this->nl_num == 0)
                        Message_WriteByte(this, CTRL_NEWLINE);
                    Message_WriteByte(this, CTRL_NEWLINE, CTRL_TWO_CHOICE);
                } else
                    Message_WriteByte(this, CTRL_NEWLINE, CTRL_THREE_CHOICE);
            }
            break;
        case BOX_SCROLL:
            Message_WriteByte(this, CTRL_BOX_BREAK_DELAYED, item->delay);
            break;
    }
}

static inline f32 BoxInfo_GetPos(BoxInfo* box) {
    if (!box) return 4096.0f;
    
    return box->cur_len / box->max_len;
}

/*
   ┌───────────────────────────────────────────────────────────────────────────┐
   │     Takes care care of handling width based newlining and handles         │
   │  spacing between words. Will also take care of not newlining when         │
   │  shift is used.                                                           │
   └───────────────────────────────────────────────────────────────────────────┘
 */
static void Message_Process_Glue(State* this, BoxInfo* box, const char* word) {
    f32 word_width = Message_GetWidth(word);
    
    if (box->shift) {
        box->cur_len += Message_WriteByte(this, ' ');
        box->cur_width += sFontWidths[' '];
        return;
    }
    
    if (!this->marked_choice && box->cur_width + word_width + sFontWidths[' '] >= MAX_WIDTH) {
        Message_WriteByte(this, CTRL_NEWLINE);
        this->nl_num++;
        box->cur_width = this->width_add;
        box->newline = true;
    } else if (!box->newline) {
        box->cur_len += Message_WriteByte(this, ' ');
        box->cur_width += sFontWidths[' '];
    }
}

static void Message_Process_Controls(State* this, Item* item, BoxInfo* box) {
    for (var i = 0; i < item->num_ctrl; i++) {
        Control* ctrl = &item->ctrl[i];
        
        if (BoxInfo_GetPos(box) >= ctrl->pos) {
            ctrl->pos = FLT_MAX;
            
            _log ("write_control(%*d/%*d): %s::%08X",
                digint(item->num_ctrl), i + 1, digint(item->num_ctrl), item->num_ctrl,
                sCtrlType[ctrl->type], ctrl->value);
            switch (ctrl->type) {
                case CTRL_TOKENS:
                case CTRL_TIME:
                    Message_Process_Glue(this, box, " xx:xx");
                    box->cur_width += Message_GetWidth(" xx:xx");
                    Message_WriteByte(this, ' ', ctrl->type);
                    break;
                case CTRL_BOX_BREAK:
                case CTRL_QUICKTEXT_ENABLE:
                case CTRL_QUICKTEXT_DISABLE:
                case CTRL_PERSISTENT:
                case CTRL_EVENT:
                case CTRL_AWAIT_BUTTON_PRESS:
                case CTRL_NAME:
                case CTRL_OCARINA:
                case CTRL_MARATHON_TIME:
                case CTRL_RACE_TIME:
                case CTRL_POINTS:
                case CTRL_UNSKIPPABLE:
                case CTRL_TWO_CHOICE:
                case CTRL_THREE_CHOICE:
                case CTRL_FISH_INFO:
                    Message_WriteByte(this, ctrl->type);
                    break;
                    
                // Arg 1
                case CTRL_SHIFT:
                    if (box) {
                        if (!box->first_word)
                            Message_WriteByte(this, CTRL_NEWLINE);
                        box->cur_width = ((ctrl->value / 180.0f) * MAX_WIDTH) * 0.5f;
                        box->shift = true;
                    }
                case CTRL_COLOR:
                case CTRL_BOX_BREAK_DELAYED:
                case CTRL_FADE:
                case CTRL_TEXT_SPEED:
                    Message_WriteByte(this, ctrl->type, ctrl->value);
                    break;
                case CTRL_HIGHSCORE:
                    Message_WriteByte(this, ' ', ctrl->type, ctrl->value);
                    break;
                case CTRL_ITEM_ICON:
                    this->width_add = MAX_WIDTH * 0.12f;
                    box->cur_width += this->width_add;
                    Message_WriteByte(this, ctrl->type, ctrl->value);
                    break;
                    
                // Arg 2
                case CTRL_TEXTID:
                case CTRL_FADE2:
                case CTRL_SFX:
                    Message_WriteByte(this, ctrl->type, (ctrl->value >> 8) & 0xFF, ctrl->value & 0xFF);
                    break;
                    
                // Arg 3
                case CTRL_BACKGROUND:
                    Message_WriteByte(this, ctrl->type, (ctrl->value >> 16) & 0xFF, (ctrl->value >> 8) & 0xFF, ctrl->value & 0xFF);
                    break;
            }
        }
    }
}

static void Message_Process(State* this, Item* item, const char* msg) {
    BoxInfo box = {
        .max_len    = strlen(msg),
        .cur_width  = this->width_add,
        .newline    = true,
        .first_word = true,
    };
    
    for (const char* __word = msg; __word && *__word; __word = strword(__word, 1)) {
        const char* word = x_cpyword(__word, 0);
        
        Message_Process_Controls(this, item, &box);
        
        {
            const char* a = x_strndup(msg, __word - msg);
            const char* b = word;
            const char* c = x_strdup(msg + (a ? str8len(a) : 0) + str8len(word));
            
            _log("" PRNT_GRAY "%s" PRNT_RSET "%s" PRNT_GRAY "%s",
                a ? a : "",
                b ? b : "",
                c ? c : "");
        }
        
        Message_Process_Glue(this, &box, word);
        box.cur_width += Message_GetWidth(word);
        box.cur_len += Message_WriteStr(this, word);
        box.newline = false;
        box.first_word = false;
    }
    
    box.cur_width = 4069.0f;
    
    // All except last index after a 'choice' item
    if (this->marked_choice && this->item_index + 1 < this->item_num)
        Message_WriteByte(this, CTRL_NEWLINE);
    
    // Flush rest of controllers in
    if (this->item_index + 1 == this->item_num)
        Message_Process_Controls(this, item, &box);
}

void Message_HandleItem(State* this, const char* msg) {
    Item* item = Item_New(this);
    u8 box_type_id = this->msg_type_pos >> 4;
    u8 box_pos_id = this->msg_type_pos & 0xF;
    
    if (!msg)
        msg = "";
    else {
        msg = x_strndup(msg, str8len(msg) * 4 + 16);
        strrep((void*)msg, "…", "...");
        strrep((void*)msg, "’", "'");
    }
    
    _log("type:%X pos:%X", box_type_id, box_pos_id);
    
    if (this->item_index == 0)
        Message_NewEntry(this);
    else
        Message_NewItem(this, item);
    
    Message_Process(this, item, msg);
    
    if (box_type_id == 3 /* TEXTBOX_TYPE_OCARINA */)
        Message_WriteByte(this, CTRL_NEWLINE, CTRL_NEWLINE, CTRL_NEWLINE);
    
    Item_Delete(item);
    
    if (this->item_index + 1 == this->item_num)
        Message_WriteByte(this, CTRL_END);
}

void Message_End(State* this) {
    this->msg_index = 0xFFFC;
    this->msg_type_pos = 0x00;
    Message_NewEntry(this);
    Message_WriteStr(this, "0123456789");
    Message_WriteByte(this, CTRL_NEWLINE);
    Message_WriteStr(this, "ABCDEFGHIJKLMN");
    Message_WriteByte(this, CTRL_NEWLINE);
    Message_WriteStr(this, "OPQRSTUVWXYZ");
    Message_WriteByte(this, CTRL_NEWLINE);
    Message_WriteStr(this, "abcdefghijklmn");
    Message_WriteByte(this, CTRL_NEWLINE);
    Message_WriteStr(this, "opqrstuvwxyz");
    Message_WriteByte(this, CTRL_NEWLINE);
    Message_WriteStr(this, " -.");
    Message_WriteByte(this, CTRL_NEWLINE, CTRL_END);
    
    this->msg_index = 0xFFFD;
    Message_NewEntry(this);
    Message_WriteByte(this, CTRL_END);
    Memfile_Align(this->data, 16);
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

void Message_C(State* this, const char* file) {
    MsgEntryBE* tbl = this->tbl->data;
    Memfile* out = new(Memfile);
    
    *out = Memfile_New();
    SegmentSet(0, this->data->str);
    
    for (;; tbl++) {
        const u8* msg = SegmentToVirtual(0, tbl->segment & 0xFFFFFF);
        _log("entry: %04X", tbl->text_index);
        Memfile_Fmt(out,
            "DEFINE_MESSAGE(0x%04X, %s, %s,\n\"",
            tbl->text_index, sMsgBoxTypeName[tbl->type], sMsgBoxPosName[tbl->pos]);
        
        for (; *msg != CTRL_END; msg++) {
            switch (*msg) {
                case 'a' ... 'z':
                case 'A' ... 'Z':
                case '0' ... '9':
                case ' ':
                case '.':
                case '!':
                case '-':
                case '\'':
                    Memfile_Write(out, msg, 1);
                    break;
                case '\"':
                    Memfile_Cat(out, "\\\"");
                    break;
                    
                case CTRL_A ... CTRL_CRIGHT:
                    Memfile_Fmt(out, "\\x%02X", *msg);
                    break;
                    
                case CTRL_NEWLINE:
                    Memfile_Cat(out, "\\n\"\n\"");
                    break;
                    
                case CTRL_BOX_BREAK:
                    Memfile_Cat(out, "\"\n\"");
                case CTRL_TOKENS:
                case CTRL_TIME:
                case CTRL_QUICKTEXT_ENABLE:
                case CTRL_QUICKTEXT_DISABLE:
                case CTRL_PERSISTENT:
                case CTRL_EVENT:
                case CTRL_AWAIT_BUTTON_PRESS:
                case CTRL_NAME:
                case CTRL_OCARINA:
                case CTRL_MARATHON_TIME:
                case CTRL_RACE_TIME:
                case CTRL_POINTS:
                case CTRL_UNSKIPPABLE:
                case CTRL_TWO_CHOICE:
                case CTRL_THREE_CHOICE:
                case CTRL_FISH_INFO:
                    Memfile_Fmt(out, "\" %s \"", x_enumify(sCtrlType[*msg]));
                    break;
                    
                // Arg 1
                case CTRL_BOX_BREAK_DELAYED:
                    Memfile_Fmt(out, "\"\nBOX_BREAK_DELAYED(\"\\x%02X\")\n\"", *msg, *(msg + 1));
                    break;
                case CTRL_SHIFT:
                case CTRL_COLOR:
                case CTRL_FADE:
                case CTRL_TEXT_SPEED:
                case CTRL_HIGHSCORE:
                case CTRL_ITEM_ICON:
                    Memfile_Fmt(out, "\\x%02X\\x%02X", *msg,
                        *(msg + 1));
                    msg++;
                    break;
                    
                // Arg 2
                case CTRL_TEXTID:
                case CTRL_FADE2:
                case CTRL_SFX:
                    Memfile_Fmt(out, "\\x%02X\\x%02X\\x%02X", *msg,
                        *(msg + 1), *(msg + 2));
                    
                    msg += 2;
                    break;
                    
                // Arg 3
                case CTRL_BACKGROUND:
                    Memfile_Fmt(out, "\\x%02X\\x%02X\\x%02X\\x%02X", *msg,
                        *(msg + 1), *(msg + 2), *(msg + 3));
                    msg += 3;
                    break;
                    
                case 0x80 ... 0x9E:
                    for (var i = 0; i < ArrCount(sSpcCharMap); i++) {
                        if ((u8)(*sSpcCharMap[i][1]) == *msg) {
                            Memfile_Fmt(out, "%s", sSpcCharMap[i][0]);
                            
                            break;
                        }
                    }
                    break;
            }
        }
        
        Memfile_Fmt(out,
            "\",\n\"\",\n\"\"\n)\n");
        
        if (tbl->text_index == 0xFFFD)
            break;
    }
    
    Memfile_SaveBin(out, file);
    Memfile_Free(out);
    vfree(out);
}
