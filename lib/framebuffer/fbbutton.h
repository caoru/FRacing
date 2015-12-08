/*
 * fbutils.h
 *
 * Headers for utility routines for framebuffer interaction
 *
 * Copyright 2002 Russell King and Doug Lowder
 *
 * This file is placed under the GPL.  Please see the
 * file COPYING for details.
 *
 */

#ifndef _FBBUTTON_H
#define _FBBUTTON_H

#include "config.h"

#include "list.h"

typedef struct __fbbutton
{
	int x, y, w, h;
	char *name;
	char *text;
	int flags;
	struct list_head list;
#define BUTTON_ACTIVE 0x00000001
} fbbutton_t;

void button_set_color(void);
int button_create(const char *name, const char *text, int x, int y, int w, int h);
void button_delete(const char *name);
void button_delete_all(void);
void button_active(const char *name);
void button_deactive(const char *name);
void button_draw(fbbutton_t *btn);
void button_draw_all(void);

#endif /* _FBBUTTON_H */
