/*
 * fbutils.c
 *
 * Utility routines for framebuffer interaction
 *
 * Copyright 2002 Russell King and Doug Lowder
 *
 * This file is placed under the GPL.  Please see the
 * file COPYING for details.
 *
 */

#include "config.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"
#include "framebuffer.h"
#include "fbbutton.h"

static int palette [] =
{
	0x000000, 0xffe080, 0xffffff, 0xe0c0a0, 0x304050, 0x80b8c0
};
#define NR_COLORS (sizeof (palette) / sizeof (palette [0]))

static int button_palette [6] =
{
	1, 4, 2,
	1, 5, 0
};

static LIST_HEAD(fb_buttons);

void button_set_color(void)
{
	int i;

	for (i = 0; i < NR_COLORS; i++)
		setcolor (i, palette [i]);
}

int button_create(const char *name, const char *text, int x, int y, int w, int h)
{
	fbbutton_t *btn = NULL;

	if ((btn = calloc(1, sizeof(fbbutton_t))) == NULL)
		return -1;

	btn->x = x;
	btn->y = y;
	btn->w = w;
	btn->h = h;
	btn->flags = 0;

	if ((btn->name = strdup(name)) == NULL)
	{
		free(btn);
		return -1;
	}

	if ((btn->text = strdup(text)) == NULL)
	{
		free(btn->name);
		free(btn);
		return -1;
	}

	BTN_LIST_ADD(btn);

	return 0;
}

void button_delete(const char *name)
{
	fbbutton_t *btn = NULL;

	list_for_each_entry(btn, &fb_buttons, list)
	{
		if (strncmp(btn->name, name, strlen(name)) == 0)
		{
			list_del(&btn->list);
			free(btn->name);
			free(btn->text);
			free(btn);

			break;
		}
	}
}

void button_delete_all(void)
{
	fbbutton_t *btn = NULL;

	list_for_each_entry(btn, &fb_buttons, list)
	{
		list_del(&btn->list);
		free(btn->name);
		free(btn->text);
		free(btn);
	}
}

void button_active(const char *name)
{
	fbbutton_t *btn = NULL;

	list_for_each_entry(btn, &fb_buttons, list)
	{
		if (strncmp(btn->name, name, strlen(name)) == 0)
		{
			btn->flags |= BUTTON_ACTIVE;
			break;
		}
	}
}

void button_deactive(const char *name)
{
	fbbutton_t *btn = NULL;

	list_for_each_entry(btn, &fb_buttons, list)
	{
		if (strncmp(btn->name, name, strlen(name)) == 0)
		{
			btn->flags &= ~BUTTON_ACTIVE;
			break;
		}
	}
}

void button_draw(fbbutton_t *btn)
{
	int s = (btn->flags & BUTTON_ACTIVE) ? 3 : 0;
	rect (btn->x, btn->y, btn->x + btn->w,
	      btn->y + btn->h, button_palette [s]);
	fillrect (btn->x + 1, btn->y + 1,
		  btn->x + btn->w - 2,
		  btn->y + btn->h - 2, button_palette [s + 1]);
	put_string_center (btn->x + btn->w / 2,
			   btn->y + btn->h / 2,
			   btn->text, button_palette [s + 2]);
}

void button_draw_all(void)
{
	fbbutton_t *btn = NULL;

	list_for_each_entry(btn, &fb_buttons, list)
	{
		button_draw(btn);
	}
}

