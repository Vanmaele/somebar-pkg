// somebar - dwl bar
// See LICENSE file for copyright and license details.

#pragma once
#include "common.hpp"

constexpr bool topbar = true;

constexpr int paddingX = 10;
constexpr int paddingY = 3;

// See https://docs.gtk.org/Pango/type_func.FontDescription.from_string.html
constexpr const char* font = "NotoSansMono Nerd Font Mono 14";
/* constexpr const char* font = "CousineNerdFont 14"; */

constexpr ColorScheme colorInactive = {Color(0xff, 0xff, 0xff), Color(0x44, 0x44, 0x44)};
constexpr ColorScheme colorActive = {Color(0xff, 0xff, 0xff), Color(0x22, 0x22, 0x22)};

constexpr const char* termcmd[] = {"foot", nullptr};

constexpr Button buttons[] = {
	{ ClkTagBar,       BTN_LEFT,   view,       {0} },
	{ ClkTagBar,       BTN_RIGHT,  tag,        {0} },
	{ ClkTagBar,       BTN_MIDDLE, toggletag,  {0} },
	{ ClkLayoutSymbol, BTN_LEFT,   setlayout,  {.ui = 0} },
	{ ClkLayoutSymbol, BTN_RIGHT,  setlayout,  {.ui = 2} },
	{ ClkStatusText,   BTN_RIGHT,  spawn,      {.v = termcmd} },
};
