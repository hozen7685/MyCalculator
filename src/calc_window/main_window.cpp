/******************************************************************************
 *  Copyright 2024
 *
 *  @file    main_window.cpp
 *
 *  @brief   
 *
 *=============================================================================
 *  Revision History
 *  Version     Date        Author      Content
 *  -------     ----------  ---------   ---------------------------------------
 *  V1.00       2024/10/18  caohozen      Create.
 *
 *****************************************************************************/

/******************************************************************************
 *
 * INCLUDES
 *
 *****************************************************************************/
#include "main_window.hpp"
#include <unistd.h>
#include "../calc_backend/calculator.hpp"

static lv_display_t *m_display;
static lv_span_t *m_span_history;
static lv_span_t *m_span_current;
static lv_obj_t *m_button_sector;
static lv_obj_t *m_buttons[BTN_NUM];

static const wchar_t * title = L"MYCALC";
static lv_style_t cmn_style;
static const char *s_button_lable[BTN_NUM] = {
    "7",  "8",  "9",  "/",
    "4",  "5",  "6",  "*",
    "1",  "2",  "3",  "-",
    "C",  "0",  "=",  "+"
};

static void event_handler_b7(lv_event_t * e);
static void event_handler_b8(lv_event_t * e);
static void event_handler_b9(lv_event_t * e);
static void event_handler_dvi(lv_event_t * e);
static void event_handler_b4(lv_event_t * e);
static void event_handler_b5(lv_event_t * e);
static void event_handler_b6(lv_event_t * e);
static void event_handler_mp(lv_event_t * e);
static void event_handler_b1(lv_event_t * e);
static void event_handler_b2(lv_event_t * e);
static void event_handler_b3(lv_event_t * e);
static void event_handler_mi(lv_event_t * e);
static void event_handler_bc(lv_event_t * e);
static void event_handler_b0(lv_event_t * e);
static void event_handler_rs(lv_event_t * e);
static void event_handler_pl(lv_event_t * e);

static void (*btn_event_cb[BTN_NUM])(lv_event_t * e) = {
    event_handler_b7, event_handler_b8, event_handler_b9, event_handler_dvi,
    event_handler_b4, event_handler_b5, event_handler_b6, event_handler_mp,
    event_handler_b1, event_handler_b2, event_handler_b3, event_handler_mi,
    event_handler_bc, event_handler_b0, event_handler_rs, event_handler_pl
};

static void create_calc_layout(void);
/******************************************************************************
 *
 * FUNCTIONS
 *
 *****************************************************************************/
static void print_timer_cb(lv_timer_t * timer)
{
    lv_span_set_text(m_span_history, g_history_buffer);
    lv_span_set_text(m_span_current, g_current_buffer);
}

static void event_handler_b7(lv_event_t * e)
{
    calc_input_proc(7, NUMBER);
}
static void event_handler_b8(lv_event_t * e)
{
    calc_input_proc(8, NUMBER);
}
static void event_handler_b9(lv_event_t * e)
{
    calc_input_proc(9, NUMBER);
}
static void event_handler_dvi(lv_event_t * e){
    calc_input_proc(DIVIDE, OPERATOR);
}
static void event_handler_b4(lv_event_t * e){
    calc_input_proc(4, NUMBER);
}
static void event_handler_b5(lv_event_t * e){
    calc_input_proc(5, NUMBER);
}
static void event_handler_b6(lv_event_t * e){
    calc_input_proc(6, NUMBER);
}
static void event_handler_mp(lv_event_t * e){
    calc_input_proc(MULTIPLY, OPERATOR);
}
static void event_handler_b1(lv_event_t * e){
    calc_input_proc(1, NUMBER);
}
static void event_handler_b2(lv_event_t * e){
    calc_input_proc(2, NUMBER);
}
static void event_handler_b3(lv_event_t * e){
    calc_input_proc(3, NUMBER);
}
static void event_handler_mi(lv_event_t * e){
    calc_input_proc(MINUS, OPERATOR);
}
static void event_handler_bc(lv_event_t * e){
    calc_input_proc(CLEAR, OPERATOR);
}
static void event_handler_b0(lv_event_t * e){
    calc_input_proc(0, NUMBER);
}
static void event_handler_rs(lv_event_t * e){
    calc_input_proc(RESULT, OPERATOR);
}
static void event_handler_pl(lv_event_t * e){
    calc_input_proc(PLUS, OPERATOR);
}

main_window_c::main_window_c()
{
}
main_window_c::~main_window_c()
{
}

void main_window_c::create_calc_window(void)
{
    lv_init();
    m_display = lv_windows_create_display(title, 480, 640, 100, FALSE, FALSE);
    lv_windows_acquire_pointer_indev(m_display);
    LV_LOG_USER("LVGL initialization completed!");
    create_calc_layout();
    while(1) {
        /* Periodically call the lv_task handler.
         * It could be done in a timer interrupt or an OS task too.*/
        lv_task_handler();
        usleep(1000);       /*Just to let the system breath*/
    }
}

static void create_calc_layout(void)
{
    lv_obj_t *mainView = lv_obj_create(lv_screen_active());
    lv_obj_set_size(mainView, 360, 360);
    lv_obj_set_style_pad_all(mainView, 0, 0);
    lv_obj_set_style_border_width(mainView, 2, 0);
    lv_obj_set_style_outline_width(mainView, 0, 0);
    lv_obj_set_style_bg_color(mainView, lv_color_hex(0xf3f3f3), 0);
    lv_obj_center(mainView);
    lv_obj_set_style_radius(mainView, 7, 0);
    lv_obj_t *spans_sector = lv_spangroup_create(mainView);
    lv_obj_set_size(spans_sector, 350, 70);
    lv_obj_align(spans_sector, LV_ALIGN_TOP_LEFT, 0, 0);
    lv_obj_set_style_pad_all(spans_sector, 4, 0);
    lv_obj_set_style_bg_color(spans_sector, lv_color_hex(0xf3f3f3), 0);
    lv_obj_set_style_border_width(spans_sector, 0, 0);

    lv_spangroup_set_align(spans_sector, LV_TEXT_ALIGN_RIGHT);
    lv_spangroup_set_overflow(spans_sector, LV_SPAN_OVERFLOW_CLIP);
    lv_spangroup_set_mode(spans_sector, LV_SPAN_MODE_FIXED);

    m_span_history = lv_spangroup_new_span(spans_sector);
    
    lv_style_set_text_color(lv_span_get_style(m_span_history), lv_color_hex(0xa3a3a3));
    lv_style_set_text_font(lv_span_get_style(m_span_history),  &lv_font_montserrat_16);
    m_span_current = lv_spangroup_new_span(spans_sector);
    lv_style_set_text_color(lv_span_get_style(m_span_current), lv_color_hex(0x000000));
    lv_style_set_text_font(lv_span_get_style(m_span_current),  &lv_font_montserrat_36);

    m_button_sector = lv_obj_create(mainView);
    lv_obj_set_size(m_button_sector, 350, 250);
    lv_obj_align(m_button_sector, LV_ALIGN_BOTTOM_RIGHT, 0, 0);
    lv_obj_set_style_pad_all(m_button_sector, 4, 0);
    lv_obj_set_style_border_width(m_button_sector, 0, 0);
    lv_obj_set_flex_flow(m_button_sector, LV_FLEX_FLOW_ROW_WRAP);
    lv_obj_set_flex_align(m_button_sector, LV_FLEX_ALIGN_SPACE_EVENLY, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
    lv_obj_set_style_bg_color(m_button_sector, lv_color_hex(0xf3f3f3), 0);
    for (size_t i = 0; i < BTN_NUM; ++i)
    {
        m_buttons[i] = lv_button_create(m_button_sector);
        lv_obj_add_event_cb(m_buttons[i], btn_event_cb[i], LV_EVENT_CLICKED, NULL);
        lv_obj_set_size(m_buttons[i], 77, 51);
        lv_obj_set_style_bg_color(m_buttons[i], lv_color_hex(0xffffff), LV_PART_MAIN);
        lv_obj_t *lable = lv_label_create(m_buttons[i]);
        lv_label_set_text(lable, s_button_lable[i]);
        lv_obj_set_style_text_font(lable, &lv_font_montserrat_30, 0);
        lv_obj_set_style_text_color(lable, lv_color_hex(0x000000), 0);
        lv_obj_center(lable);
    }
    lv_timer_t *timer = lv_timer_create(print_timer_cb, 500, NULL);
}
/* - End Of File - */
