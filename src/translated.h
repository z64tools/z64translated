#ifndef TRANSLATED_H
#define TRANSLATED_H

#include <ext_lib.h>

typedef struct {
    f32 max_len;
    f32 cur_width;
    int cur_len;
    
    f32  pos;
    bool newline;
    bool first_word;
    bool shift;
} BoxInfo;

typedef struct {
    int entry_index; // 'i' for the current entry processed
    u16 msg_index; // *OoT* ingame message index
    u8  msg_type_pos; // *OoT* message params, type / pos
    
    int item_index; // Current item index from 'entry_index'
    int item_num; // Maximum count of items for current 'entry_index'
    
    int nl_num;
    
    Toml*    toml;
    Memfile* tbl;
    Memfile* data;
    
    struct {
        bool marked_choice : 1;
    };
    
    f32 width_add;
} State;

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
} Item;

typedef struct StructBE {
    u16 text_index;
    struct StructBE {
        u8 type : 4;
        u8 pos  : 4;
    };
    u8  __pad;
    u32 segment;
} MsgEntryBE;

State* State_New(Memfile* tbl, Memfile* data, Toml* toml);
void State_Delete(State* this);
void Message_HandleItem(State* this, const char* msg);
void Message_End(State* this);
void Message_C(State* this, const char* file);

#ifdef TRANSLATED_C

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

#define MAX_WIDTH (64.0f * 5.0f)

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

f32 sFontWidths[144] = {
//crustify
    8.0f,  /* ' ' */ 8.0f,  /* '!' */ 6.0f,  /* '"' */ 9.0f,  /* '#' */
    9.0f,  /* '$' */ 14.0f, /* '%' */ 12.0f, /* '&' */ 3.0f,  /* ''' */
    7.0f,  /* '(' */ 7.0f,  /* ')' */ 7.0f,  /* '*' */ 9.0f,  /* '+' */
    4.0f,  /* ',' */ 6.0f,  /* '-' */ 4.0f,  /* '.' */ 9.0f,  /* '/' */
    10.0f, /* '0' */ 5.0f,  /* '1' */ 9.0f,  /* '2' */ 9.0f,  /* '3' */
    10.0f, /* '4' */ 9.0f,  /* '5' */ 9.0f,  /* '6' */ 9.0f,  /* '7' */
    9.0f,  /* '8' */ 9.0f,  /* '9' */ 6.0f,  /* ':' */ 6.0f,  /* ';' */
    9.0f,  /* '<' */ 11.0f, /* '=' */ 9.0f,  /* '>' */ 11.0f, /* '?' */
    13.0f, /* '@' */ 12.0f, /* 'A' */ 9.0f,  /* 'B' */ 11.0f, /* 'C' */
    11.0f, /* 'D' */ 8.0f,  /* 'E' */ 8.0f,  /* 'F' */ 12.0f, /* 'G' */
    10.0f, /* 'H' */ 4.0f,  /* 'I' */ 8.0f,  /* 'J' */ 10.0f, /* 'K' */
    8.0f,  /* 'L' */ 13.0f, /* 'M' */ 11.0f, /* 'N' */ 13.0f, /* 'O' */
    9.0f,  /* 'P' */ 13.0f, /* 'Q' */ 10.0f, /* 'R' */ 10.0f, /* 'S' */
    9.0f,  /* 'T' */ 10.0f, /* 'U' */ 11.0f, /* 'V' */ 15.0f, /* 'W' */
    11.0f, /* 'X' */ 10.0f, /* 'Y' */ 10.0f, /* 'Z' */ 7.0f,  /* '[' */
    10.0f, /* '\' */ 7.0f,  /* ']' */ 10.0f, /* '^' */ 9.0f,  /* '_' */
    5.0f,  /* '`' */ 8.0f,  /* 'a' */ 9.0f,  /* 'b' */ 8.0f,  /* 'c' */
    9.0f,  /* 'd' */ 9.0f,  /* 'e' */ 6.0f,  /* 'f' */ 9.0f,  /* 'g' */
    8.0f,  /* 'h' */ 4.0f,  /* 'i' */ 6.0f,  /* 'j' */ 8.0f,  /* 'k' */
    4.0f,  /* 'l' */ 12.0f, /* 'm' */ 9.0f,  /* 'n' */ 9.0f,  /* 'o' */
    9.0f,  /* 'p' */ 9.0f,  /* 'q' */ 7.0f,  /* 'r' */ 8.0f,  /* 's' */
    7.0f,  /* 't' */ 8.0f,  /* 'u' */ 9.0f,  /* 'v' */ 12.0f, /* 'w' */
    8.0f,  /* 'x' */ 9.0f,  /* 'y' */ 8.0f,  /* 'z' */ 7.0f,  /* '{' */
    5.0f,  /* '|' */ 7.0f,  /* '}' */ 10.0f, /* '~' */ 10.0f, /* '‾' */
    12.0f, /* 'À' */ 6.0f,  /* 'î' */ 12.0f, /* 'Â' */ 12.0f, /* 'Ä' */
    11.0f, /* 'Ç' */ 8.0f,  /* 'È' */ 8.0f,  /* 'É' */ 8.0f,  /* 'Ê' */
    6.0f,  /* 'Ë' */ 6.0f,  /* 'Ï' */ 13.0f, /* 'Ô' */ 13.0f, /* 'Ö' */
    10.0f, /* 'Ù' */ 10.0f, /* 'Û' */ 10.0f, /* 'Ü' */ 9.0f,  /* 'ß' */
    8.0f,  /* 'à' */ 8.0f,  /* 'á' */ 8.0f,  /* 'â' */ 8.0f,  /* 'ä' */
    8.0f,  /* 'ç' */ 9.0f,  /* 'è' */ 9.0f,  /* 'é' */ 9.0f,  /* 'ê' */
    9.0f,  /* 'ë' */ 6.0f,  /* 'ï' */ 9.0f,  /* 'ô' */ 9.0f,  /* 'ö' */
    9.0f,  /* 'ù' */ 9.0f,  /* 'û' */ 9.0f,  /* 'ü' */ 14.0f, /* '[A]' */
    14.0f, /* '[B]' */                14.0f, /* '[C]' */
    14.0f, /* '[L]' */                14.0f, /* '[R]' */
    14.0f, /* '[Z]' */                14.0f, /* '[C-Up]' */
    14.0f, /* '[C-Down]' */           14.0f, /* '[C-Left]' */
    14.0f, /* '[C-Right]' */          14.0f, /* '▼' */
    14.0f, /* '[Control-Pad]' */      14.0f, /* '[D-Pad]' */
    14.0f, /* ? */                    14.0f, /* ? */
    14.0f, /* ? */                    14.0f, /* ? */
//uncrustify
};

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

const char* sSpcCharMap[][2] = {
    { "À", "\x80" },
    { "î", "\x81" },
    { "Â", "\x82" },
    { "Ä", "\x83" },
    { "Ç", "\x84" },
    { "È", "\x85" },
    { "É", "\x86" },
    { "Ê", "\x87" },
    { "Ë", "\x88" },
    { "Ï", "\x89" },
    { "Ô", "\x8A" },
    { "Ö", "\x8B" },
    { "Ù", "\x8C" },
    { "Û", "\x8D" },
    { "Ü", "\x8E" },
    { "ß", "\x8F" },
    { "à", "\x90" },
    { "á", "\x91" },
    { "â", "\x92" },
    { "ä", "\x93" },
    { "ç", "\x94" },
    { "è", "\x95" },
    { "é", "\x96" },
    { "ê", "\x97" },
    { "ë", "\x98" },
    { "ï", "\x99" },
    { "ô", "\x9A" },
    { "ö", "\x9B" },
    { "ù", "\x9C" },
    { "û", "\x9D" },
    { "ü", "\x9E" },
};

#endif

#endif