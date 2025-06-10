/* Taken from https://github.com/djpohly/dwl/issues/466 */
#define COLOR(hex)    { ((hex >> 24) & 0xFF) / 255.0f, \
                        ((hex >> 16) & 0xFF) / 255.0f, \
                        ((hex >> 8) & 0xFF) / 255.0f, \
                        (hex & 0xFF) / 255.0f }
/* appearance */
static const int sloppyfocus               = 1;  /* focus follows mouse */
static const int bypass_surface_visibility = 0;  /* 1 means idle inhibitors will disable idle tracking even if it's surface isn't visible  */
static const int smartgaps                 = 1;  /* 1 means no outer gap when there is only one window */
static int gaps                            = 1;  /* 1 means gaps between windows are added */
static const unsigned int gappx            = 7; /* gap pixel between windows */
static const unsigned int borderpx         = 4;  /* border pixel of windows */
static const float rootcolor[]             = COLOR(0x222222ff);
static const float bordercolor[]           = COLOR(0x444444ff);
static const float focuscolor[]            = COLOR(0x005577ff);
static const float urgentcolor[]           = COLOR(0xff0000ff);
/* This conforms to the xdg-protocol. Set the alpha to zero to restore the old behavior */
static const float fullscreen_bg[]         = {0.1f, 0.1f, 0.1f, 1.0f}; /* You can also use glsl colors */
static const char *cursor_theme            = "BreezeX-Black";
static const char cursor_size[]            = "24";

/* tagging - TAGCOUNT must be no greater than 31 */
#define TAGCOUNT (10)

/* logging */
static int log_level = WLR_ERROR;

static const char *const autostart[] = {
	"dwl-autostart", NULL,
	NULL
};

static const Rule rules[] = {
	{"EXAMPLE",NULL,0,1,-1},
};

/* layout(s) */
static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

static const MonitorRule monrules[] = {
	{ "DP-1", // Name
          0.5f,                        // mfact
          1, 1,                        // nmaster, scale
          &layouts[0],                 // layout
          WL_OUTPUT_TRANSFORM_NORMAL,  // rotate/reflect
          -1, -1,                      // x, y
          1920, 1080,                  // resx, resy
          164.917,                 // refresh rate
          0, 1 },                     // mode, adaptive
};

/* keyboard */
static const struct xkb_rule_names xkb_rules = {
	/* can specify fields: rules, model, layout, variant, options */
	/* example:
	.options = "ctrl:nocaps",
	*/
	.options = NULL,
};

static const int repeat_rate = 30;
static const int repeat_delay = 275;

/* Trackpad */
static const int tap_to_click = 1;
static const int tap_and_drag = 1;
static const int drag_lock = 1;
static const int natural_scrolling = 0;
static const int disable_while_typing = 1;
static const int left_handed = 0;
static const int middle_button_emulation = 0;
/* You can choose between:
LIBINPUT_CONFIG_SCROLL_NO_SCROLL
LIBINPUT_CONFIG_SCROLL_2FG
LIBINPUT_CONFIG_SCROLL_EDGE
LIBINPUT_CONFIG_SCROLL_ON_BUTTON_DOWN
*/
static const enum libinput_config_scroll_method scroll_method = LIBINPUT_CONFIG_SCROLL_2FG;

/* You can choose between:
LIBINPUT_CONFIG_CLICK_METHOD_NONE
LIBINPUT_CONFIG_CLICK_METHOD_BUTTON_AREAS
LIBINPUT_CONFIG_CLICK_METHOD_CLICKFINGER
*/
static const enum libinput_config_click_method click_method = LIBINPUT_CONFIG_CLICK_METHOD_BUTTON_AREAS;

/* You can choose between:
LIBINPUT_CONFIG_SEND_EVENTS_ENABLED
LIBINPUT_CONFIG_SEND_EVENTS_DISABLED
LIBINPUT_CONFIG_SEND_EVENTS_DISABLED_ON_EXTERNAL_MOUSE
*/
static const uint32_t send_events_mode = LIBINPUT_CONFIG_SEND_EVENTS_ENABLED;

/* You can choose between:
LIBINPUT_CONFIG_ACCEL_PROFILE_FLAT
LIBINPUT_CONFIG_ACCEL_PROFILE_ADAPTIVE
*/
static const enum libinput_config_accel_profile accel_profile = LIBINPUT_CONFIG_ACCEL_PROFILE_ADAPTIVE;
static const double accel_speed = 0.0;

/* You can choose between:
LIBINPUT_CONFIG_TAP_MAP_LRM -- 1/2/3 finger tap maps to left/right/middle
LIBINPUT_CONFIG_TAP_MAP_LMR -- 1/2/3 finger tap maps to left/middle/right
*/
static const enum libinput_config_tap_button_map button_map = LIBINPUT_CONFIG_TAP_MAP_LRM;

/* If you want to use the windows key for MODKEY, use WLR_MODIFIER_LOGO */
#define MODKEY WLR_MODIFIER_ALT

// Change workspaces and move windows to workspaces
// view changes workspace
// tag moves window to workspace
#define TAGKEYS(KEY,SKEY,TAG) \
	{ WLR_MODIFIER_LOGO,         KEY,  view, {.ui = 1 << TAG} }, \
	{ MODKEY|WLR_MODIFIER_SHIFT, SKEY, tag,  {.ui = 1 << TAG} }

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static const char *launcher[]       = { "dwl-launcher",     NULL };
static const char *term[]           = { "foot",             NULL };
static const char *firefox[]        = { "firefox",          NULL };
static const char *takescreenshot[] = { "take_screenshot",  NULL };

static const Key keys[] = {
  /* Note that Shift changes certain key codes: c -> C, 2 -> at, etc. */
  /* modifier                  key             function argument */
  { MODKEY|WLR_MODIFIER_CTRL,  XKB_KEY_minus,  spawn,      {.v = takescreenshot} },
  { WLR_MODIFIER_LOGO,         XKB_KEY_space,  spawn,      {.v = launcher} },
  { MODKEY|WLR_MODIFIER_SHIFT, XKB_KEY_Return, spawn,      {.v = term} },
  { MODKEY|WLR_MODIFIER_SHIFT, XKB_KEY_F,      spawn,      {.v = firefox } },
  { MODKEY|WLR_MODIFIER_SHIFT, XKB_KEY_C,      killclient, {0} },
  { WLR_MODIFIER_LOGO|WLR_MODIFIER_SHIFT, XKB_KEY_Q, quit, {0} },
  { WLR_MODIFIER_CTRL|WLR_MODIFIER_ALT,XKB_KEY_Terminate_Server, quit, {0} },

  TAGKEYS(          XKB_KEY_1, XKB_KEY_exclam,                     0),
  TAGKEYS(          XKB_KEY_2, XKB_KEY_at,                         1),
  TAGKEYS(          XKB_KEY_3, XKB_KEY_numbersign,                 2),
  TAGKEYS(          XKB_KEY_4, XKB_KEY_dollar,                     3),
  TAGKEYS(          XKB_KEY_5, XKB_KEY_percent,                    4),
  TAGKEYS(          XKB_KEY_6, XKB_KEY_asciicircum,                5),
  TAGKEYS(          XKB_KEY_7, XKB_KEY_ampersand,                  6),
  TAGKEYS(          XKB_KEY_8, XKB_KEY_asterisk,                   7),
  TAGKEYS(          XKB_KEY_9, XKB_KEY_parenleft,                  8),
  TAGKEYS(          XKB_KEY_0, XKB_KEY_parenleft,                  9),

#define CHVT(n) { WLR_MODIFIER_CTRL|WLR_MODIFIER_ALT,XKB_KEY_XF86Switch_VT_##n, chvt, {.ui = (n)} }
	CHVT(1), CHVT(2), CHVT(3), CHVT(4), CHVT(5), CHVT(6),
	CHVT(7), CHVT(8), CHVT(9), CHVT(10), CHVT(11), CHVT(12),
};
