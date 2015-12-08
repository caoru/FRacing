/*
 *  FRacing/test/fb_test.cpp
 *
 *  Copyright (C) 2015 Ikhyun Kim.
 *
 * This file is placed under the GPL.  Please see the file
 * COPYING for more details.
 *
 *
 * Test program for Frame buffer.
 */

#include "config.h"

#include <stdio.h>
#include <unistd.h>

#include "framebuffer.h"
#include "fbbutton.h"

int main(int argc, char **argv)
{

	if (open_framebuffer() < 0)
	{
		close_framebuffer();
		fprintf(stderr, "open framebuffer failed\n");
		return 1;
	}

	button_set_color();

	if (button_create("btn1", "btn1", 10, 10, 50, 25) < 0)
	{
		fprintf(stderr, "create button 'btn1' failed\n");
		close_framebuffer();
		return 1;
	}

	if (button_create("btn2", "btn2", 80, 10, 50, 25) < 0)
	{
		fprintf(stderr, "create button 'btn2' failed\n");
		close_framebuffer();
		return 1;
	}

	button_active("btn2");

	button_draw_all();

	sleep(2);

	close_framebuffer();

#if 0
	Configuration *config = Configuration::instance("frconfig.cfg");
	config->parse();

	FrameBuffer *fb = FrameBuffer::instance(
			config->get("framebuffer", "device"),
			config->get("console", "device"));

	if (!fb->open())
	{
		fprintf(stderr, "open frame buffer failed\n");
		return 1;
	}

	char msg[] = "Frame Buffer test program";

	fb->create_window("main");

	fb->window().set_color(0, 0x000000);
	fb->window().set_color(1, 0xffe080);
	fb->window().fill_rect(0, 0, fb->get_xres() - 1, fb->get_yres() - 1, 0);
	fb->window().put_string_center(fb->get_xres()/2, fb->get_yres()/2, msg, 1);

	getchar();

	fb->close();
#endif
	return 0;
}

