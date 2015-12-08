/*
 *  FRacing/test/config_test.cpp
 *
 *  Copyright (C) 2015 Ikhyun Kim.
 *
 * This file is placed under the GPL.  Please see the file
 * COPYING for more details.
 *
 *
 * Test program for Configuration.
 */

#include "config.h"

#include "configini.h"

#define LOG_ERR(fmt, ...)	\
	fprintf(stderr, "[ERROR] <%s:%d> : " fmt "\n", __FUNCTION__, __LINE__, __VA_ARGS__)

#define LOG_INFO(fmt, ...)	\
	fprintf(stderr, "[INFO] : " fmt "\n", __VA_ARGS__)

#define CONFIGREADFILE		"./fracing.cfg"

#define ENTER_TEST_FUNC														\
	do {																	\
		LOG_INFO("%s", "\n-----------------------------------------------");\
		LOG_INFO("<TEST: %s>\n", __FUNCTION__);								\
	} while (0)

int main(int argc, char **argv)
{
	char s[256];
	Config *cfg = NULL;

	ENTER_TEST_FUNC;

	/* set settings */
	cfg = ConfigNew();
	ConfigSetBoolString(cfg, "yes", "no");
	if (ConfigReadFile(CONFIGREADFILE, &cfg) != CONFIG_OK) {
		LOG_ERR("ConfigOpenFile failed for %s", CONFIGREADFILE);
		return 1;
	}

	ConfigPrintSettings(cfg, stdout);
	ConfigPrint(cfg, stdout);

	ConfigReadString(cfg, "framebuffer", "device", s, sizeof(s), "/dev/fb0");
	LOG_INFO("framebuffer:device = <%s>", s);

	ConfigFree(cfg);

	return 0;
}

