#include <ext_lib.h>

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

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

struct TranslateContext;

static struct TranslateContext* CtxNew();
static void CtxParams(struct TranslateContext* this, int entry, int box, int index, int pos);
static void ParseEntry(struct TranslateContext*, Toml*, const char*, Memfile*, int, int);

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

int main(int n, const char** arg) {
    struct TranslateContext* ctx = CtxNew();
    Toml toml = Toml_New();
    const char* input = NULL;
    const char* output = NULL;
    const char* fm = NULL;
    int i = 0;
    const char* usage = "z64translated --i <msg.tsv> --o <message.h> --fmt base-msg.toml";
    
    if ((i = strarg(arg, "fmt"))) {
        fm = arg[i];
        Toml_Load(&toml, arg[i]);
    } else errr("no fmt file provided!\n%s", usage);
    
    if ((i = strarg(arg, "i")))
        input = arg[i];
    else errr("no input provided!\n%s", usage);
    
    if ((i = strarg(arg, "o")))
        output = arg[i];
    else errr("no output provided!\n%s", usage);
    
    info_title("z64translated", NULL);
    
    Memfile msg_in = Memfile_New();
    Memfile msg_out = Memfile_New();
    int num = Toml_ArrItemNum(&toml, "entry");
    
    Memfile_LoadStr(&msg_in, input);
    Memfile_Alloc(&msg_out, MbToBin(4.0f));
    
    const char* line = msg_in.str;
    
    Memfile_Fmt(&msg_out,
        "#ifndef DEFINE_MESSAGE\n"
        "#define Z64TRANSLATED\n"
        "#define DEFINE_MESSAGE(a, b, c, d, e, f) 0,\n\n"
        
        "int z64translated[] = {\n"
        "#endif\n\n"
    );
    
    time_start(2);
    for (var i = 0; i < num; i++) {
        int box_num = Toml_ArrItemNum(&toml, "entry[%d].box", i);
        u16 index = Toml_GetInt(&toml, "entry[%d].index", i);
        int pos = Toml_GetInt(&toml, "entry[%d].type_pos", i);
        
        if (index == 0xFFFC)
            break;
        
        for (var k = 0; k < box_num; k++) {
            CtxParams(ctx, i, k, index, pos);
            ParseEntry(ctx, &toml, x_cpyline(line, 0), &msg_out, k, box_num);
            line = strline(line, 1);
        }
    }
    
    Memfile_Fmt(&msg_out,
        "\n"
        "#ifdef DEFINE_MESSAGE_FFFC\n"
        "DEFINE_MESSAGE(0xFFFC, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,\n"
        "\"0123456789\\n\"\n"
        "\"ABCDEFGHIJKLMN\\n\"\n"
        "\"OPQRSTUVWXYZ\\n\"\n"
        "\"abcdefghijklmn\\n\"\n"
        "\"opqrstuvwxyz\\n\"\n"
        "\" -.\\n\"\n"
        ",\n"
        ",\n"
        ")\n"
        "#endif\n"
        "\n"
        "DEFINE_MESSAGE(0xFFFD, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,\n"
        "\"\"\n"
        ",\n"
        "\"\"\n"
        ",\n"
        "\"\"\n"
        ")\n"
        "\n"
        "#ifdef Z64TRANSLATED\n"
        "};\n"
        "#undef DEFINE_MESSAGE\n"
        "#endif"
    );
    
    Memfile_SaveStr(&msg_out, output);
    
    Toml_Free(&toml);
    Memfile_Free(&msg_in);
    Memfile_Free(&msg_out);
    vfree(ctx);
    
    info(
        "input:  %32s\n"
        "format: %32s\n"
        "output: %32s\n"
        "time:   %30.2fms",
        input, fm, output, time_get(2) * 1000.0f
    );
}

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

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

typedef struct Control {
    f32 pos;
    int type;
    u32 value;
} Control;

typedef struct {
    Control* ctrl;
    int      num_ctrl;
    int      type;
    int      vlen;
    int      delay;
} Box;

typedef struct TranslateContext {
    u32 entry;
    u32 box;
    u32 index;
    u8  pos;
    
    bool marked_choice;
    bool shifted;
    f32  shift;
} TranslateContext;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

TranslateContext* CtxNew() {
    return new(TranslateContext);
}

void CtxParams(TranslateContext* this, int entry, int box, int index, int pos) {
    this->entry = entry;
    this->box = box;
    this->index = index;
    this->pos = pos;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

static Box* BoxNew(TranslateContext* this, Toml* toml) {
    Box* box = new(Box);
    const char* type = Toml_GetStr(toml, "entry[%d].box[%d].box_type", this->entry, this->box);
    int num_ctrl = Toml_ArrItemNum(toml, "entry[%d].box[%d].ctrl_type", this->entry, this->box);
    int num_pos = Toml_ArrItemNum(toml, "entry[%d].box[%d].ctrl_pos", this->entry, this->box);
    int num_val = Toml_ArrItemNum(toml, "entry[%d].box[%d].ctrl_val", this->entry, this->box);
    
    _log("entry[%d].box[%d]", this->entry, this->box);
    _log("num_ctrl: %d", num_ctrl);
    _log("num_pos:  %d", num_pos);
    _log("num_val:  %d", num_val);
    _assert(num_pos == num_ctrl);
    
    for (; box->type < ArrCount(sBoxType); box->type++)
        if (sBoxType[box->type])
            if (!strcmp(type, sBoxType[box->type]))
                break;
    
    _assert(box->type < ArrCount(sBoxType));
    _log("type:     %s", sBoxType[box->type]);
    vfree(type);
    
    box->vlen = Toml_GetInt(toml, "entry[%d].box[%d].vanilla_strlen", this->entry, this->box);
    _log("strlen:   %d", box->vlen);
    
    box->ctrl = new(Control[num_ctrl]);
    box->num_ctrl = num_ctrl;
    for (var i = 0; i < num_ctrl; i++) {
        type = Toml_GetStr(toml, "entry[%d].box[%d].ctrl_type[%d]", this->entry, this->box, i);
        box->ctrl[i].pos = Toml_GetInt(toml, "entry[%d].box[%d].ctrl_pos[%d]", this->entry, this->box, i);
        box->ctrl[i].pos /= box->vlen;
        
        for (; box->ctrl[i].type < CTRL_MAX; box->ctrl[i].type++)
            if (sCtrlType[box->ctrl[i].type])
                if (!strcmp(type, sCtrlType[box->ctrl[i].type]))
                    break;
        _assert(box->ctrl[i].type < CTRL_MAX);
        vfree(type);
        
        if (i < num_val)
            box->ctrl[i].value = Toml_GetInt(toml, "entry[%d].box[%d].ctrl_val[%d]", this->entry, this->box, i);
    }
    
    if (box->type == BOX_SCROLL) {
        box->delay = Toml_GetInt(toml, "entry[%d].box[%d].break_delay", this->entry, this->box);
        _log("delay:    %d", box->delay);
    }
    
    _log("box ok");
    
    return box;
}

static void BoxDelete(Box* box) {
    vfree(box->ctrl, box);
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

static void ControlWrite(TranslateContext* this, Control* ctrl, f32 pos, char* buffer, f32* cur_width) {
    _log("control: %s", sCtrlType[ctrl->type]);
    
    if (pos + 0.001f >= ctrl->pos) {
        ctrl->pos = FLT_MAX;
        
        strcat(buffer, "\" ");
        
        switch (ctrl->type) {
            case CTRL_BOX_BREAK:
                strcat(buffer, "\n");
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
            case CTRL_TOKENS:
            case CTRL_UNSKIPPABLE:
            case CTRL_TWO_CHOICE:
            case CTRL_THREE_CHOICE:
            case CTRL_FISH_INFO:
            case CTRL_TIME:
                catprintf(buffer, "%s", x_enumify(sCtrlType[ctrl->type]));
                break;
                
            // Arg 1
            case CTRL_SHIFT:
                if (this->shifted && cur_width) {
                    catprintf(buffer, "\"\\n\"\n");
                    *cur_width = 0.0f;
                }
                
                this->shift = invertf(ctrl->value / 180.0f);
                this->shifted = true;
            case CTRL_COLOR:
            case CTRL_BOX_BREAK_DELAYED:
            case CTRL_FADE:
            case CTRL_ITEM_ICON:
            case CTRL_TEXT_SPEED:
            case CTRL_HIGHSCORE:
                catprintf(buffer, "\"\\x%02X\\x%02X\"", ctrl->type,
                    ctrl->value);
                break;
                
            // Arg 2
            case CTRL_TEXTID:
            case CTRL_FADE2:
            case CTRL_SFX:
                catprintf(buffer, "\"\\x%02X\\x%02X\\x%02X\"", ctrl->type,
                    (ctrl->value >> 8) & 0xFF,
                    ctrl->value & 0xFF);
                break;
                
            // Arg 3
            case CTRL_BACKGROUND:
                catprintf(buffer, "\"\\x%02X\\x%02X\\x%02X\\x%02X\"", ctrl->type,
                    (ctrl->value >> 16) & 0xFF,
                    (ctrl->value >> 8) & 0xFF,
                    ctrl->value & 0xFF);
                break;
        }
        
        strcat(buffer, " \"");
    }
}

void ParseEntry(TranslateContext* this, Toml* toml, const char* msg, Memfile* out, int id, int max) {
    Box* box = BoxNew(this, toml);
    const char* box_type_name[] = {
        "TEXTBOX_TYPE_BLACK",
        "TEXTBOX_TYPE_WOODEN",
        "TEXTBOX_TYPE_BLUE",
        "TEXTBOX_TYPE_OCARINA",
        "TEXTBOX_TYPE_NONE_BOTTOM",
        "TEXTBOX_TYPE_NONE_NO_SHADOW",
    };
    const char* box_pos_name[] = {
        "TEXTBOX_POS_VARIABLE",
        "TEXTBOX_POS_TOP",
        "TEXTBOX_POS_MIDDLE",
        "TEXTBOX_POS_BOTTOM",
    };
    u8 box_type_id = this->pos >> 4;
    u8 box_pos_id = this->pos & 0xF;
    
    if (!msg)
        msg = "";
    else {
        msg = x_strndup(msg, strlen(msg) * 4 + 2);
        strrep((void*)msg, "\"", "\\\"");
        strrep((void*)msg, "…", "...");
    }
    
    this->shifted = false;
    this->shift = 1.0f;
    _log("type:%X pos:%X", box_type_id, box_pos_id);
    _assert(box_pos_id < ArrCount(box_pos_name));
    _assert(box_type_id < ArrCount(box_type_name));
    
    if (this->box == 0) {
        _log("init");
        
        this->marked_choice = false;
        if (this->entry != 0) {
            Memfile_Cat(out, "\n");
        }
        
        Memfile_Fmt(out,
            "DEFINE_MESSAGE(0x%04X, %s, %s,\n",
            this->index, box_type_name[box_type_id], box_pos_name[box_pos_id]
        );
    } else {
        switch (box->type) {
            case BOX_ENTRY:
                _assert("something has gone truly wrong" == NULL);
                break;
            case BOX_BREAK:
                Memfile_Cat(out, "BOX_BREAK\n");
                break;
            case BOX_CHOICE:
                if (!this->marked_choice) {
                    this->marked_choice = true;
                    
                    Memfile_Fmt(out, "%s_CHOICE \"\\n\"\n", (max - id) == 2 ? "TWO" : "THREE");
                }
                break;
            case BOX_SCROLL:
                Memfile_Fmt(out, "BOX_BREAK_DELAYED(\"\\x%02X\")\n", box->delay);
                break;
        }
        
    }
    
    nested(f32, GetMsgWidth, (const char* word)) {
        f32 w = 0.0f;
        
        for (; *word; word++)
            w += sFontWidths[(u8)(*word)];
        return w;
    };
    
    f32 len_msg = strlen(msg);
    char* buffer = calloc(4096);
    f32 cur_width = 0.0f;
    int len = 0;
    
    for (const char* __word = msg; __word; __word = strword(__word, 1)) {
        const char* word = x_cpyword(__word, 0);
        f32 w = GetMsgWidth(word) + sFontWidths[' '];
        f32 pos = len / len_msg;
        
        for (var i = 0; i < box->num_ctrl; i++)
            ControlWrite(this, &box->ctrl[i], pos, buffer, &cur_width);
        f32 max_width = (64 * 5.5f) * this->shift;
        
        if (cur_width + w >= max_width) {
            strcat(buffer, "\\n\"\n\"");
            cur_width = 0;
        } else if (cur_width != 0.0f) {
            strcat(buffer, " ");
            len++;
        }
        cur_width += w;
        
        strcat(buffer, word);
        len += strlen(word);
    }
    
    if (this->marked_choice && id + 1 < max)
        strcat(buffer, "\\n");
    
    if (id + 1 == max)
        for (var i = 0; i < box->num_ctrl; i++)
            ControlWrite(this, &box->ctrl[i], FLT_MAX - 10.0f, buffer, NULL);
    
    _log("buf:\n'%s'", buffer);
    Memfile_Fmt(out, "\"%s\"\n", buffer);
    
    BoxDelete(box);
    vfree(buffer);
    
    if (id + 1 != max)
        return;
    
    Memfile_Cat(out, ", \"\", \"\")\n");
}
