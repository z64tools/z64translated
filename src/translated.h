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
} WordsInfo;

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
} TranslateContext;

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
    u32 segment;
} MsgEntryBE;

void Dissassemble(TranslateContext* this, const char* file);

TranslateContext* Context_New(Memfile* tbl, Memfile* data, Toml* toml);
void Context_Delete(TranslateContext* this);
void Parse_Item(TranslateContext* this, const char* msg);
void Parse_End(TranslateContext* this);

#endif