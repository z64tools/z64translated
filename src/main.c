#include <ext_lib.h>

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

struct TranslateContext;

struct TranslateContext* NewContext();
static void ParseEntry(struct TranslateContext*, Toml*, const char*, Memfile*);

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

int main(int n, const char** arg) {
    struct TranslateContext* ctx = NewContext();
    Toml toml = Toml_New();
    const char* input = NULL;
    const char* output = NULL;
    int i = 0;
    
    if ((i = strarg(arg, "fmt")))
        Toml_Load(&toml, arg[i]);
    else return 0;
    
    if ((i = strarg(arg, "i")))
        input = arg[i];
    else return 0;
    
    if ((i = strarg(arg, "o")))
        output = arg[i];
    else return 0;
    
    Memfile msg_in = Memfile_New();
    Memfile msg_out = Memfile_New();
    int num = Toml_TabNum(&toml, "");
    
    Memfile_LoadStr(&msg_in, input);
    Memfile_Alloc(&msg_out, msg_in.size);
    
    const char* line = msg_in.str;
    
    for (var i = 0; i < num; i++, line = strline(line, 1))
        ParseEntry(ctx, &toml, line, &msg_out);
    
    // Memfile_SaveStr(&msg_out, output);
    //
    // Memfile_Free(&msg_in);
    // Memfile_Free(&msg_out);
    vfree(ctx);
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

#define TABLE_CONTROL(enum, val, str) enum = val
enum {
#include "tbl_ctrl.h"
    CTRL_MAX,
};

#define TABLE_CONTROL(enum, val, str) [enum] = str
const char* sControlName[] = {
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
    int pos;
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
    int entry;
    int box;
} TranslateContext;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

TranslateContext* NewContext() {
    return new(TranslateContext);
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

static Box* NewBox(TranslateContext* this, Toml* toml) {
    Box* box = new(Box);
    const char* type = Toml_GetStr(toml, "entry[%d].box[%d].type", this->entry, this->box);
    int num_ctrl = Toml_ArrItemNum(toml, "entry[%d].box[%d].ctrl_type", this->entry, this->box);
    int num_pos = Toml_ArrItemNum(toml, "entry[%d].box[%d].ctrl_pos", this->entry, this->box);
    int num_val = Toml_ArrItemNum(toml, "entry[%d].box[%d].ctrl_val", this->entry, this->box);
    
    _log("entry[%d].box[%d]", this->entry, this->box);
    _assert(num_pos == num_ctrl);
    
    for (; box->type < ArrCount(sBoxType); box->type++)
        if (!strcmp(type, sBoxType[box->type]))
            break;
    _assert(box->type < ArrCount(sBoxType));
    
    box->vlen = Toml_GetInt(toml, "entry[%d].box[%d].vanilla_strlen", this->entry, this->box);
    
    box->ctrl = new(Box[num_ctrl]);
    for (var i = 0; i < num_ctrl; i++) {
        for (; box->ctrl[i].type < CTRL_MAX; box->ctrl[i].type++)
            if (!strcmp(type, sBoxType[box->type]))
                break;
        _assert(box->ctrl[i].type < CTRL_MAX);
        
        if (i < num_val)
            box->ctrl[i].value = Toml_GetInt(toml, "entry[%d].box[%d].ctrl_val[%d]", this->entry, this->box, i);
        if (i < num_pos)
            box->ctrl[i].pos = Toml_GetInt(toml, "entry[%d].box[%d].ctrl_pos[%d]", this->entry, this->box, i);
    }
    
    if (box->type == BOX_SCROLL)
        box->delay = Toml_GetInt(toml, "entry[%d].box[%d].break_delay", this->entry, this->box);
    
    vfree(type);
    
    return box;
}

static void DeleteBox(Box* box) {
    vfree(box->ctrl, box);
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

void ParseEntry(TranslateContext* this, Toml* toml, const char* msg, Memfile* out) {
    Box* box = NewBox(this, toml);
    
    info("%d::%d", this->entry, this->box);
    
    DeleteBox(box);
}
