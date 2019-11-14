/*
 * Copyright (c) 2018 Milan Suk
 *
 * Use of this software is governed by the Business Source License included
 * in the LICENSE file and at www.mariadb.com/bsl11.
 *
 * Change Date: 2024-11-01
 *
 * On the date above, in accordance with the Business Source License, use
 * of this software will be governed by version 2 or later of the General
 * Public License.
 */

typedef struct GuiItemTheme_s
{
	Rgba background;
	Rgba main;

	Rgba black;
	Rgba white;

	Rgba select;
	Rgba selectFormula;
	Rgba warning;

	Rgba selectEdit;
}GuiItemTheme;

GuiItemTheme g_theme;

void GuiItemTheme_init(void)
{
	g_theme.background = Rgba_init4(220, 220, 220, 255);
	g_theme.main = Rgba_init4(90, 110, 210, 255);

	g_theme.black = Rgba_init4(35, 35, 35, 255);
	g_theme.white = Rgba_init4(255, 255, 255, 255);

	g_theme.select = Rgba_init4(240, 240, 120, 255);
	g_theme.selectFormula = Rgba_init4(240, 240, 120, 255);//Rgba_init4(240, 70, 40, 255);
	g_theme.warning = Rgba_init4(200, 20, 20, 255);

	g_theme.selectEdit = Rgba_init4(90, 110, 210, 255);
}

void GuiItemTheme_goRed(void)
{
	GuiItemTheme_init();
	g_theme.main = Rgba_init4(200, 100, 80, 255);
}

void GuiItemTheme_goBlue(void)
{
	GuiItemTheme_init();
	g_theme.main = Rgba_init4(100, 110, 210, 255);
}

void GuiItemTheme_goGreen(void)
{
	GuiItemTheme_init();
	g_theme.main = Rgba_init4(90, 180, 90, 255);
}

void GuiItemTheme_goOcean(void)
{
	GuiItemTheme_init();
	g_theme.main = Rgba_init4(90, 180, 180, 255);
}

void GuiItemTheme_goGrey(void)
{
	GuiItemTheme_init();
	g_theme.main = Rgba_init4(120, 120, 120, 255);
}


Rgba GuiItemTheme_getWhite_Background(void)
{
	return Rgba_aprox(g_theme.white, g_theme.background, 0.35f);
}