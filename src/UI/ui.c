// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.1.0
// LVGL VERSION: 8.2
// PROJECT: SquareLine_Project

#include "ui.h"
#include "ui_helpers.h"

///////////////////// VARIABLES ////////////////////
lv_obj_t * ui_Screen1;
lv_obj_t * ui_BAT;
lv_obj_t * ui_Label3;
lv_obj_t * ui_Panel1;
lv_obj_t * ui_Hour;
lv_obj_t * ui_Panel2;
lv_obj_t * ui_Min;
lv_obj_t * ui_Bar1;
lv_obj_t * ui_Label4;
void ui_event_Button1(lv_event_t * e);
lv_obj_t * ui_Button1;
lv_obj_t * ui_Label5;
void ui_event_Slider1(lv_event_t * e);
lv_obj_t * ui_Slider1;

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 16
    #error "LV_COLOR_DEPTH should be 16bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP !=0
    #error "LV_COLOR_16_SWAP should be 0 to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////

///////////////////// FUNCTIONS ////////////////////
void ui_event_Button1(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_PRESSED) {
        _ui_bar_set_property(ui_Bar1, _UI_BAR_PROPERTY_VALUE_WITH_ANIM, 100);
    }
}
void ui_event_Slider1(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_VALUE_CHANGED) {
        _ui_bar_set_property(ui_Bar1, _UI_BAR_PROPERTY_VALUE_WITH_ANIM, 0);
    }
}

///////////////////// SCREENS ////////////////////
void ui_Screen1_screen_init(void)
{
    ui_Screen1 = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Screen1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Screen1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Screen1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_BAT = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_BAT, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_BAT, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_BAT, -89);
    lv_obj_set_y(ui_BAT, -128);
    lv_obj_set_align(ui_BAT, LV_ALIGN_CENTER);
    lv_label_set_text(ui_BAT, "100");
    lv_obj_set_style_text_color(ui_BAT, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_BAT, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label3 = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_Label3, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label3, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label3, 91);
    lv_obj_set_y(ui_Label3, -128);
    lv_obj_set_align(ui_Label3, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label3, "status");
    lv_obj_set_style_text_color(ui_Label3, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Panel1 = lv_obj_create(ui_Screen1);
    lv_obj_set_width(ui_Panel1, 100);
    lv_obj_set_height(ui_Panel1, 50);
    lv_obj_set_x(ui_Panel1, -60);
    lv_obj_set_y(ui_Panel1, -70);
    lv_obj_set_align(ui_Panel1, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Panel1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Hour = lv_label_create(ui_Panel1);
    lv_obj_set_width(ui_Hour, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Hour, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Hour, 0);
    lv_obj_set_y(ui_Hour, -1);
    lv_obj_set_align(ui_Hour, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Hour, "00");
    lv_obj_set_style_text_font(ui_Hour, &lv_font_montserrat_44, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Panel2 = lv_obj_create(ui_Screen1);
    lv_obj_set_width(ui_Panel2, 100);
    lv_obj_set_height(ui_Panel2, 50);
    lv_obj_set_x(ui_Panel2, 60);
    lv_obj_set_y(ui_Panel2, -70);
    lv_obj_set_align(ui_Panel2, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Panel2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Min = lv_label_create(ui_Panel2);
    lv_obj_set_width(ui_Min, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Min, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Min, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Min, "00");
    lv_obj_set_style_text_font(ui_Min, &lv_font_montserrat_44, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Bar1 = lv_bar_create(ui_Screen1);
    lv_obj_set_width(ui_Bar1, 150);
    lv_obj_set_height(ui_Bar1, 10);
    lv_obj_set_x(ui_Bar1, 0);
    lv_obj_set_y(ui_Bar1, -20);
    lv_obj_set_align(ui_Bar1, LV_ALIGN_CENTER);

    ui_Label4 = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_Label4, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label4, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label4, 0);
    lv_obj_set_y(ui_Label4, -75);
    lv_obj_set_align(ui_Label4, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label4, ":");
    lv_obj_set_style_text_color(ui_Label4, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label4, &lv_font_montserrat_42, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Button1 = lv_btn_create(ui_Screen1);
    lv_obj_set_width(ui_Button1, 100);
    lv_obj_set_height(ui_Button1, 50);
    lv_obj_set_x(ui_Button1, -1);
    lv_obj_set_y(ui_Button1, 34);
    lv_obj_set_align(ui_Button1, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Button1, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Button1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Label5 = lv_label_create(ui_Button1);
    lv_obj_set_width(ui_Label5, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label5, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label5, LV_ALIGN_CENTER);

    ui_Slider1 = lv_slider_create(ui_Screen1);
    lv_obj_set_width(ui_Slider1, 150);
    lv_obj_set_height(ui_Slider1, 10);
    lv_obj_set_x(ui_Slider1, 5);
    lv_obj_set_y(ui_Slider1, 99);
    // lv_bar_set_value(, val, LV_ANIM_ON)
    lv_obj_set_align(ui_Slider1, LV_ALIGN_CENTER);

    lv_obj_add_event_cb(ui_Button1, ui_event_Button1, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Slider1, ui_event_Slider1, LV_EVENT_ALL, NULL);

}

void ui_init(void)
{
    lv_disp_t * dispp = lv_disp_get_default();
    lv_theme_t * theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED),
                                               false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    ui_Screen1_screen_init();
    lv_disp_load_scr(ui_Screen1);
}
