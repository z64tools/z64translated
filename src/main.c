#include "translated.h"

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

#define TABLE_CONTROL(enum, val, str) enum = val
enum {
#include "tbl_ctrl.h"
    CTRL_MAX,
};

#define TABLE_CONTROL(enum, val, str) [enum] = str
const char* sCtrlType[] = {
#include "tbl_ctrl.h"
};

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

f32 sFontWidths[144] = {
    8.0f,                      // ' '
    8.0f,                      // '!'
    6.0f,                      // '"'
    9.0f,                      // '#'
    9.0f,                      // '$'
    14.0f,                     // '%'
    12.0f,                     // '&'
    3.0f,                      // '''
    7.0f,                      // '('
    7.0f,                      // ')'
    7.0f,                      // '*'
    9.0f,                      // '+'
    4.0f,                      // ','
    6.0f,                      // '-'
    4.0f,                      // '.'
    9.0f,                      // '/'
    10.0f,                     // '0'
    5.0f,                      // '1'
    9.0f,                      // '2'
    9.0f,                      // '3'
    10.0f,                     // '4'
    9.0f,                      // '5'
    9.0f,                      // '6'
    9.0f,                      // '7'
    9.0f,                      // '8'
    9.0f,                      // '9'
    6.0f,                      // ':'
    6.0f,                      // ';'
    9.0f,                      // '<'
    11.0f,                     // '='
    9.0f,                      // '>'
    11.0f,                     // '?'
    13.0f,                     // '@'
    12.0f,                     // 'A'
    9.0f,                      // 'B'
    11.0f,                     // 'C'
    11.0f,                     // 'D'
    8.0f,                      // 'E'
    8.0f,                      // 'F'
    12.0f,                     // 'G'
    10.0f,                     // 'H'
    4.0f,                      // 'I'
    8.0f,                      // 'J'
    10.0f,                     // 'K'
    8.0f,                      // 'L'
    13.0f,                     // 'M'
    11.0f,                     // 'N'
    13.0f,                     // 'O'
    9.0f,                      // 'P'
    13.0f,                     // 'Q'
    10.0f,                     // 'R'
    10.0f,                     // 'S'
    9.0f,                      // 'T'
    10.0f,                     // 'U'
    11.0f,                     // 'V'
    15.0f,                     // 'W'
    11.0f,                     // 'X'
    10.0f,                     // 'Y'
    10.0f,                     // 'Z'
    7.0f,                      // '['
    10.0f,                     // '\'
    7.0f,                      // ']'
    10.0f,                     // '^'
    9.0f,                      // '_'
    5.0f,                      // '`'
    8.0f,                      // 'a'
    9.0f,                      // 'b'
    8.0f,                      // 'c'
    9.0f,                      // 'd'
    9.0f,                      // 'e'
    6.0f,                      // 'f'
    9.0f,                      // 'g'
    8.0f,                      // 'h'
    4.0f,                      // 'i'
    6.0f,                      // 'j'
    8.0f,                      // 'k'
    4.0f,                      // 'l'
    12.0f,                     // 'm'
    9.0f,                      // 'n'
    9.0f,                      // 'o'
    9.0f,                      // 'p'
    9.0f,                      // 'q'
    7.0f,                      // 'r'
    8.0f,                      // 's'
    7.0f,                      // 't'
    8.0f,                      // 'u'
    9.0f,                      // 'v'
    12.0f,                     // 'w'
    8.0f,                      // 'x'
    9.0f,                      // 'y'
    8.0f,                      // 'z'
    7.0f,                      // '{'
    5.0f,                      // '|'
    7.0f,                      // '}'
    10.0f,                     // '~'
    10.0f,                     // '‾'
    12.0f,                     // 'À'
    6.0f,                      // 'î'
    12.0f,                     // 'Â'
    12.0f,                     // 'Ä'
    11.0f,                     // 'Ç'
    8.0f,                      // 'È'
    8.0f,                      // 'É'
    8.0f,                      // 'Ê'
    6.0f,                      // 'Ë'
    6.0f,                      // 'Ï'
    13.0f,                     // 'Ô'
    13.0f,                     // 'Ö'
    10.0f,                     // 'Ù'
    10.0f,                     // 'Û'
    10.0f,                     // 'Ü'
    9.0f,                      // 'ß'
    8.0f,                      // 'à'
    8.0f,                      // 'á'
    8.0f,                      // 'â'
    8.0f,                      // 'ä'
    8.0f,                      // 'ç'
    9.0f,                      // 'è'
    9.0f,                      // 'é'
    9.0f,                      // 'ê'
    9.0f,                      // 'ë'
    6.0f,                      // 'ï'
    9.0f,                      // 'ô'
    9.0f,                      // 'ö'
    9.0f,                      // 'ù'
    9.0f,                      // 'û'
    9.0f,                      // 'ü'
    14.0f,                     // '[A]'
    14.0f,                     // '[B]'
    14.0f,                     // '[C]'
    14.0f,                     // '[L]'
    14.0f,                     // '[R]'
    14.0f,                     // '[Z]'
    14.0f,                     // '[C-Up]'
    14.0f,                     // '[C-Down]'
    14.0f,                     // '[C-Left]'
    14.0f,                     // '[C-Right]'
    14.0f,                     // '▼'
    14.0f,                     // '[Control-Pad]'
    14.0f,                     // '[D-Pad]'
    14.0f,                     // ?
    14.0f,                     // ?
    14.0f,                     // ?
    14.0f,                     // ?
};
enum {
    OUTPUT_DECOMP,
    OUTPUT_BINARY,
} sOutputType;
const char* sMsgBoxTypeName[] = {
    "TEXTBOX_TYPE_BLACK",
    "TEXTBOX_TYPE_WOODEN",
    "TEXTBOX_TYPE_BLUE",
    "TEXTBOX_TYPE_OCARINA",
    "TEXTBOX_TYPE_NONE_BOTTOM",
    "TEXTBOX_TYPE_NONE_NO_SHADOW",
};
const char* sMsgBoxPosName[] = {
    "TEXTBOX_POS_VARIABLE",
    "TEXTBOX_POS_TOP",
    "TEXTBOX_POS_MIDDLE",
    "TEXTBOX_POS_BOTTOM",
};

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
    TranslateContext* ctx = Context_New(&output_tbl, &output_data, &toml);
    
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
            
            Parse_Item(ctx, x_cpyline(line, 0));
            line = strline(line, 1);
        }
    }
    Parse_End(ctx);
    
    Memfile_SaveBin(&output_tbl, x_fmt("%s%s.tbl", x_path(output), x_filename(output)) );
    Memfile_SaveBin(&output_data, x_fmt("%s%s.bin", x_path(output), x_filename(output)) );
    // Dissassemble(ctx, x_fmt("%s%s.h", x_path(output), x_filename(output)));
    
    Toml_Free(&toml);
    Memfile_Free(&input_nsv);
    Memfile_Free(&output_tbl);
    Memfile_Free(&output_data);
    Context_Delete(ctx);
    
    info(
        "input:  %32s\n"
        "format: %32s\n"
        "output: %32s\n"
        "time:   %30.2fms",
        input, fm, output, time_get(2) * 1000.0f
    );
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

void Dissassemble(TranslateContext* this, const char* file) {
    MsgEntryBE* tbl = this->tbl->data;
    Memfile* out = new(Memfile);
    
    *out = Memfile_New();
    SegmentSet(0, this->data->str);
    
    for (; tbl->text_index < 0xFFFF; tbl++) {
        // const char* msg = SegmentToVirtual(0, tbl->segment & 0xFFFFFF);
        _log("entry: %04X", tbl->text_index);
        Memfile_Fmt(out,
            "DEFINE_MESSAGE(0x%04X, %s, %s,\n",
            sMsgBoxTypeName[tbl->type], sMsgBoxPosName[tbl->pos]);
        
        Memfile_Fmt(out,
            "\n\"\",\n\"\"\n)\n");
    }
    
    Memfile_SaveBin(out, file);
    Memfile_Free(out);
    vfree(out);
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

enum {
    BOX_ENTRY,
    BOX_BREAK,
    BOX_CHOICE,
    BOX_SCROLL,
};

const char* sBoxType[] = {
    [BOX_ENTRY] = "entry",
    [BOX_BREAK] = "break",
    [BOX_CHOICE] = "choice",
    [BOX_SCROLL] = "scroll",
};

#define MAX_WIDTH (64.0f * 5.0f)

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

static int MsgData_WriteBytes(TranslateContext* this, u32 num, ...) {
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
#define MsgData_WriteBytes(ctx, ...) MsgData_WriteBytes(ctx, NARGS(__VA_ARGS__), __VA_ARGS__)
#endif

static int MsgData_WriteStr(TranslateContext* this, const char* str) {
    int len = 0;
    const char* charmap[][2] = {
        [0] =  { "À", "\x80" },
        [1] =  { "î", "\x81" },
        [2] =  { "Â", "\x82" },
        [3] =  { "Ä", "\x83" },
        [4] =  { "Ç", "\x84" },
        [5] =  { "È", "\x85" },
        [6] =  { "É", "\x86" },
        [7] =  { "Ê", "\x87" },
        [8] =  { "Ë", "\x88" },
        [9] =  { "Ï", "\x89" },
        [10] = { "Ô", "\x8A" },
        [11] = { "Ö", "\x8B" },
        [12] = { "Ù", "\x8C" },
        [13] = { "Û", "\x8D" },
        [14] = { "Ü", "\x8E" },
        [15] = { "ß", "\x8F" },
        [16] = { "à", "\x90" },
        [17] = { "á", "\x91" },
        [18] = { "â", "\x92" },
        [19] = { "ä", "\x93" },
        [20] = { "ç", "\x94" },
        [21] = { "è", "\x95" },
        [22] = { "é", "\x96" },
        [23] = { "ê", "\x97" },
        [24] = { "ë", "\x98" },
        [25] = { "ï", "\x99" },
        [26] = { "ô", "\x9A" },
        [27] = { "ö", "\x9B" },
        [28] = { "ù", "\x9C" },
        [29] = { "û", "\x9D" },
        [30] = { "ü", "\x9E" },
    };
    
    for (; *str; str++) {
        if (0xf0 == (0xf8 & *str))
            str += 4;
        else if (0xe0 == (0xf0 & *str))
            str += 3;
        else if (0xc0 == (0xe0 & *str)) {
            for (var i = 0; i < ArrCount(charmap); i++) {
                if (!memcmp(charmap[i][0], str, 2)) {
                    MsgData_WriteBytes(this, *charmap[i][1]);
                    len++;
                    
                    break;
                }
            }
            
            str += 2;
        } else {
            _assert(*str != '\n');
            
            MsgData_WriteBytes(this, *str);
            len++;
        }
    }
    
    return len;
}

TranslateContext* Context_New(Memfile* tbl, Memfile* data, Toml* toml) {
    TranslateContext* ctx = new(TranslateContext);
    
    ctx->tbl = tbl;
    ctx->data = data;
    ctx->toml = toml;
    
    return ctx;
}

void Context_Delete(TranslateContext* this) {
    vfree(this);
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

static Item* Item_New(TranslateContext* this) {
    Item* item = new(Item);
    const char* type = Toml_GetStr(this->toml, "entry[%d].item[%d].box_type", this->entry_index, this->item_index);
    int num_ctrl = Toml_ArrItemNum(this->toml, "entry[%d].item[%d].ctrl_type", this->entry_index, this->item_index);
    int num_pos = Toml_ArrItemNum(this->toml, "entry[%d].item[%d].ctrl_pos", this->entry_index, this->item_index);
    int num_val = Toml_ArrItemNum(this->toml, "entry[%d].item[%d].ctrl_val", this->entry_index, this->item_index);
    
    _log("%04X", this->msg_index);
    _log("entry[%d].item[%d]", this->entry_index, this->item_index);
    _log("num_ctrl: %d", num_ctrl);
    _log("num_pos:  %d", num_pos);
    _log("num_val:  %d", num_val);
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

static f32 Msg_GetWidth(const char* word) {
    f32 w = 0.0f;
    
    for (; *word; word++)
        w += sFontWidths[(u8)(*word)];
    return w;
}

static void Parse_NewEntry(TranslateContext* this) {
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

static void Parse_NewItem(TranslateContext* this, Item* item) {
    switch (item->type) {
        case BOX_ENTRY:
            _assert("something has gone truly wrong" == NULL);
            break;
        case BOX_BREAK:
            MsgData_WriteBytes(this, CTRL_BOX_BREAK);
            this->nl_num = 0;
            break;
        case BOX_CHOICE:
            if (!this->marked_choice) {
                this->marked_choice = true;
                
                if ((this->item_num - this->item_index) == 2) {
                    
                    if (this->nl_num == 0)
                        MsgData_WriteBytes(this, CTRL_NEWLINE);
                    MsgData_WriteBytes(this, CTRL_NEWLINE, CTRL_TWO_CHOICE);
                } else
                    MsgData_WriteBytes(this, CTRL_NEWLINE, CTRL_THREE_CHOICE);
            }
            break;
        case BOX_SCROLL:
            MsgData_WriteBytes(this, CTRL_BOX_BREAK_DELAYED, item->delay);
            break;
    }
}

static inline f32 WordsInfo_GetPos(WordsInfo* info) {
    if (!info) return 4096.0f;
    
    return info->cur_len / info->max_len;
}

static void Parse_WriteControl(TranslateContext* this, Item* item, WordsInfo* info) {
    for (var i = 0; i < item->num_ctrl; i++) {
        Control* ctrl = &item->ctrl[i];
        
        if (WordsInfo_GetPos(info) >= ctrl->pos) {
            ctrl->pos = FLT_MAX;
            
            _log ("write_control(%*d/%*d): %s::%08X",
                digint(item->num_ctrl), i + 1, digint(item->num_ctrl), item->num_ctrl,
                sCtrlType[ctrl->type], ctrl->value);
            switch (ctrl->type) {
                case CTRL_TOKENS:
                    MsgData_WriteBytes(this, ' ', ctrl->type);
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
                case CTRL_TIME:
                    MsgData_WriteBytes(this, ctrl->type);
                    break;
                    
                // Arg 1
                case CTRL_SHIFT:
                    if (info) {
                        if (info->shift)
                            MsgData_WriteBytes(this, CTRL_NEWLINE);
                        info->cur_width = ((ctrl->value / 180.0f) * MAX_WIDTH) * 0.5f;
                        info->shift = true;
                    }
                case CTRL_COLOR:
                case CTRL_BOX_BREAK_DELAYED:
                case CTRL_FADE:
                case CTRL_TEXT_SPEED:
                    MsgData_WriteBytes(this, ctrl->type, ctrl->value);
                    break;
                case CTRL_HIGHSCORE:
                    MsgData_WriteBytes(this, ' ', ctrl->type, ctrl->value);
                    break;
                case CTRL_ITEM_ICON:
                    this->width_add = MAX_WIDTH * 0.12f;
                    info->cur_width += this->width_add;
                    MsgData_WriteBytes(this, ctrl->type, ctrl->value);
                    break;
                    
                // Arg 2
                case CTRL_TEXTID:
                case CTRL_FADE2:
                case CTRL_SFX:
                    MsgData_WriteBytes(this, ctrl->type, (ctrl->value >> 8) & 0xFF, ctrl->value & 0xFF);
                    break;
                    
                // Arg 3
                case CTRL_BACKGROUND:
                    MsgData_WriteBytes(this, ctrl->type, (ctrl->value >> 16) & 0xFF, (ctrl->value >> 8) & 0xFF, ctrl->value & 0xFF);
                    break;
            }
        }
    }
}

static void Parse_WriteWords(TranslateContext* this, Item* item, const char* msg) {
    WordsInfo info = {
        .max_len    = strlen(msg),
        .cur_width  = this->width_add,
        .newline    = true,
        .first_word = true,
    };
    
    for (const char* __word = msg; __word; __word = strword(__word, 1)) {
        const char* word = x_cpyword(__word, 0);
        f32 word_width = Msg_GetWidth(word);
        
        Parse_WriteControl(this, item, &info);
        
        {
            const char* a = x_strndup(msg, __word - msg);
            const char* b = word;
            const char* c = x_strdup(msg + (a ? strlen(a) : 0) + strlen(word));
            
            _log("" PRNT_GRAY "%s" PRNT_RSET "%s" PRNT_GRAY "%s",
                a ? a : "",
                b ? b : "",
                c ? c : "");
        }
        
        if (!this->marked_choice && info.cur_width + word_width + sFontWidths[' '] >= MAX_WIDTH) {
            MsgData_WriteBytes(this, CTRL_NEWLINE);
            this->nl_num++;
            info.cur_width = this->width_add;
            info.newline = true;
        } else if (!info.newline) {
            info.cur_len += MsgData_WriteBytes(this, ' ');
            info.cur_width += sFontWidths[' '];
        }
        
        info.cur_width += word_width;
        info.cur_len += MsgData_WriteStr(this, word);
        info.newline = false;
        info.first_word = false;
    }
}

void Parse_Item(TranslateContext* this, const char* msg) {
    Item* item = Item_New(this);
    u8 box_type_id = this->msg_type_pos >> 4;
    u8 box_pos_id = this->msg_type_pos & 0xF;
    
    if (!msg)
        msg = "";
    else {
        msg = x_strndup(msg, strlen(msg) * 4 + 2);
        strrep((void*)msg, "\"", "\\\"");
        strrep((void*)msg, "…", "...");
    }
    
    _log("type:%X pos:%X", box_type_id, box_pos_id);
    
    if (this->item_index == 0)
        Parse_NewEntry(this);
    else
        Parse_NewItem(this, item);
    
    Parse_WriteWords(this, item, msg);
    
    // All except last index after a 'choice' item
    if (this->marked_choice && this->item_index + 1 < this->item_num)
        MsgData_WriteBytes(this, CTRL_NEWLINE);
    
    // Flush rest of controllers in
    if (this->item_index + 1 == this->item_num)
        Parse_WriteControl(this, item, NULL);
    
    if (box_type_id == 3 /* TEXTBOX_TYPE_OCARINA */)
        MsgData_WriteBytes(this, CTRL_NEWLINE, CTRL_NEWLINE, CTRL_NEWLINE);
    
    Item_Delete(item);
    
    if (this->item_index + 1 == this->item_num)
        MsgData_WriteBytes(this, CTRL_END);
}

void Parse_End(TranslateContext* this) {
    this->msg_index = 0xFFFC;
    this->msg_type_pos = 0x00;
    Parse_NewEntry(this);
    MsgData_WriteStr(this, "0123456789");
    MsgData_WriteBytes(this, CTRL_NEWLINE);
    MsgData_WriteStr(this, "ABCDEFGHIJKLMN");
    MsgData_WriteBytes(this, CTRL_NEWLINE);
    MsgData_WriteStr(this, "OPQRSTUVWXYZ");
    MsgData_WriteBytes(this, CTRL_NEWLINE);
    MsgData_WriteStr(this, "abcdefghijklmn");
    MsgData_WriteBytes(this, CTRL_NEWLINE);
    MsgData_WriteStr(this, "opqrstuvwxyz");
    MsgData_WriteBytes(this, CTRL_NEWLINE);
    MsgData_WriteStr(this, " -.");
    MsgData_WriteBytes(this, CTRL_NEWLINE, CTRL_END);
    
    this->msg_index = 0xFFFD;
    Parse_NewEntry(this);
    MsgData_WriteBytes(this, CTRL_END);
    Memfile_Align(this->data, 16);
}
