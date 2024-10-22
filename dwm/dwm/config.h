#include <X11/XF86keysym.h>
/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 4;        /* border pixel of windows */
static const unsigned int gappx     = 7;        /* gap pixel between windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 0;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "Cascadia Code:size=10" };
static const char dmenufont[]       = "Cascadia Code:size=10";
static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_cyan[]        = "#22d5b8";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray4, col_cyan,  col_cyan  },
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[1]; /* = {
	// xprop(1):
	// 	WM_CLASS(STRING) = instance, class
	// 	WM_NAME(STRING) = title
	// 
	// class      instance    title       tags mask     isfloating   monitor
	
	//{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
	//{ "Firefox",  NULL,       NULL,       1 << 8,       0,           -1 },
	
}; */

/* layout(s) */
static const float mfact     = 0.45; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static int attachbelow = 1;    /* 1 means attach after the currently active window */
static const int lockfullscreen = 0; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod1Mask
#define SUPER Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ SUPER,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ SUPER|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ SUPER|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} }, \
	{ SUPER|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static const char *launcher[] = { "dwm-rofi", NULL };
static const char *term[]  = { "st", NULL };
static const char *firefox[] = { "firefox", NULL };
static const char *steam[] = { "steam", NULL };
static const char *audioup[] = { "dwm-audio-up", NULL };
static const char *audiodown[] = { "dwm-audio-down", NULL };
static const char *brightnessup[] = { "dwm-brightness-up", NULL };
static const char *brightnessdown[] = { "dwm-brightness-down", NULL };
static const char *takescreenshot[] = { "dwm-takescreenshot", NULL };
static const char *startrecording[] = { "dwm-startrecording", NULL };
static const char *startstream[] = { "dwm-startstream", NULL };
static const char *endrecording[] = { "dwm-endrecording", NULL };



static const Key keys[] = {
	/* modifier                     key        function        argument */
	{ 0,		XF86XK_AudioRaiseVolume,  spawn,   {.v = audioup} },
	{ 0,		XF86XK_AudioLowerVolume,  spawn,   {.v = audiodown} },
	{ 0,		XF86XK_MonBrightnessUp,   spawn,   {.v = brightnessup} },
	{ 0,		XF86XK_MonBrightnessDown, spawn,   {.v = brightnessdown} },
	{ MODKEY|ControlMask,       XK_minus,     spawn,   {.v = takescreenshot} },
	{ MODKEY|ControlMask,       XK_equal,     spawn,   {.v = startrecording} },
	{ MODKEY|ControlMask,       XK_space,     spawn,   {.v = startstream} },
	{ MODKEY|ControlMask,       XK_BackSpace, spawn,   {.v = endrecording} },
	{ SUPER,			XK_Tab,    toggleAttachBelow, {0} },
	{ SUPER,                        XK_space,  spawn,          {.v = launcher } },
	{ MODKEY|ShiftMask,		XK_f,	   spawn,	   {.v = firefox } },
	{ MODKEY|ShiftMask,             XK_Return, spawn,          {.v = term } },
	{ MODKEY|ShiftMask,             XK_s, 	   spawn,          {.v = steam } },
	{ MODKEY|ShiftMask,             XK_c,      killclient,     {0} },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ SUPER|ShiftMask,	        XK_q,      quit,           {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = term } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
};

