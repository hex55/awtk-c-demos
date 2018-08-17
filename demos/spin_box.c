/**
 * File:   spin_box.c
 * Author: AWTK Develop Team
 * Brief:  spin_box demo
 *
 * Copyright (c) 2018 - 2018  Guangzhou ZHIYUAN Electronics Co.,Ltd.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * License file for more details.
 *
 */

/**
 * History:
 * ================================================================
 * 2018-08-17 Li XianJing <xianjimli@hotmail.com> created
 *
 */

#include "base/window.h"
#include "base/spin_box.h"

static ret_t on_changed(void* ctx, event_t* evt) {
  widget_t* target = WIDGET(evt->target);

  log_debug("%s changing\n", target->name);

  return RET_OK;
}

static ret_t on_changing(void* ctx, event_t* evt) {
  widget_t* target = WIDGET(evt->target);

  log_debug("%s changing\n", target->name);

  return RET_OK;
}

widget_t* create_spin_box(widget_t* win, int type, const char* name, const char* text, int x, int y,
                          int w, int h) {
  widget_t* spin_box = spin_box_create(win, x, y, w, h);

  widget_on(spin_box, EVT_VALUE_CHANGED, on_changed, NULL);
  widget_on(spin_box, EVT_VALUE_CHANGING, on_changing, NULL);

  widget_set_name(spin_box, name);
  widget_set_text_utf8(spin_box, text);

  edit_set_input_tips(spin_box, name);
  edit_set_input_type(spin_box, type);

  return spin_box;
}

void application_init() {
  widget_t* spin_box1 = NULL;
  widget_t* spin_box2 = NULL;
  widget_t* spin_box3 = NULL;
  widget_t* spin_box4 = NULL;

  widget_t* win = window_create(NULL, 0, 0, 0, 0);

  spin_box1 = create_spin_box(win, INPUT_INT, "int", "", 10, 10, 228, 30);
  edit_set_int_limit(spin_box1, 1, 100, 1);

  spin_box2 = create_spin_box(win, INPUT_UINT, "uint", "", 10, 50, 228, 30);
  edit_set_int_limit(spin_box2, 1, 100, 1);

  spin_box3 = create_spin_box(win, INPUT_FLOAT, "float", "1.23", 10, 90, 228, 30);
  edit_set_float_limit(spin_box3, 1, 10, 1);

  spin_box4 = create_spin_box(win, INPUT_UFLOAT, "ufloat", "", 10, 10 + 128, 228, 30);
  edit_set_float_limit(spin_box4, 1, 10, 0.1);

  widget_layout(win);
}

#include "demo_main.c"