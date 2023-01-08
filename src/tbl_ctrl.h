#ifndef TABLE_CONTROL
#define PLEASE_THE_IDE
#define TABLE_CONTROL(name, value, str) 0

int wow[] = {
#endif

TABLE_CONTROL(CTRL_NEWLINE,            0x01, "newline"),
TABLE_CONTROL(CTRL_END,                0x02, "end"),
TABLE_CONTROL(CTRL_BOX_BREAK,          0x04, "box_break"),
TABLE_CONTROL(CTRL_COLOR,              0x05, "color"),
TABLE_CONTROL(CTRL_SHIFT,              0x06, "shift"),
TABLE_CONTROL(CTRL_TEXTID,             0x07, "textid"),
TABLE_CONTROL(CTRL_QUICKTEXT_ENABLE,   0x08, "quicktext_enable"),
TABLE_CONTROL(CTRL_QUICKTEXT_DISABLE,  0x09, "quicktext_disable"),
TABLE_CONTROL(CTRL_PERSISTENT,         0x0A, "persistent"),
TABLE_CONTROL(CTRL_EVENT,              0x0B, "event"),
TABLE_CONTROL(CTRL_BOX_BREAK_DELAYED,  0x0C, "box_break_delayed"),
TABLE_CONTROL(CTRL_AWAIT_BUTTON_PRESS, 0x0D, "await_button_press"),
TABLE_CONTROL(CTRL_FADE,               0x0E, "fade"),
TABLE_CONTROL(CTRL_NAME,               0x0F, "name"),
TABLE_CONTROL(CTRL_OCARINA,            0x10, "ocarina"),
TABLE_CONTROL(CTRL_FADE2,              0x11, "fade2"),
TABLE_CONTROL(CTRL_SFX,                0x12, "sfx"),
TABLE_CONTROL(CTRL_ITEM_ICON,          0x13, "item_icon"),
TABLE_CONTROL(CTRL_TEXT_SPEED,         0x14, "text_speed"),
TABLE_CONTROL(CTRL_BACKGROUND,         0x15, "background"),
TABLE_CONTROL(CTRL_MARATHON_TIME,      0x16, "marathon_time"),
TABLE_CONTROL(CTRL_RACE_TIME,          0x17, "race_time"),
TABLE_CONTROL(CTRL_POINTS,             0x18, "points"),
TABLE_CONTROL(CTRL_TOKENS,             0x19, "tokens"),
TABLE_CONTROL(CTRL_UNSKIPPABLE,        0x1A, "unskippable"),
TABLE_CONTROL(CTRL_TWO_CHOICE,         0x1B, "two_choice"),
TABLE_CONTROL(CTRL_THREE_CHOICE,       0x1C, "three_choice"),
TABLE_CONTROL(CTRL_FISH_INFO,          0x1D, "fish_info"),
TABLE_CONTROL(CTRL_HIGHSCORE,          0x1E, "highscore"),
TABLE_CONTROL(CTRL_TIME,               0x1F, "time"),

#ifdef PLEASE_THE_IDE
};
#endif
#undef TABLE_CONTROL