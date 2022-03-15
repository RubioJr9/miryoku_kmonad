;; Copyright 2021 Manna Harbour
;; github.com/manna-harbour/miryoku

#include "miryoku.h"

(defcfg
#if defined (MIRYOKU_KMONAD_OS_WIN)
  input  (low-level-hook)
  output (send-event-sink)
#elif defined (MIRYOKU_KMONAD_OS_MAC)
  input  (iokit-name MIRYOKU_KMONAD_KEYBOARD_MAC)
  output (kext)
#else
  input  (device-file MIRYOKU_KMONAD_KEYBOARD_LINUX)
  output (uinput-sink "Miryoku KMonad output")
#endif
#if defined (MIRYOKU_MAPPING_LITE)
  fallthrough true
#else
  fallthrough false
#endif
)

(defsrc
#if defined (MIRYOKU_MAPPING_NOREVERSEANGLE)
  grv    1      2      3      4           8      9      0      -      =
  tap    q      w      e      r           i      o      p      [      ]
  caps   a      s      d      f           k      l      ;      U_QUOT ent
                z      x      c           ,      .      /
#elif defined (MIRYOKU_MAPPING_LITE)
  q      w      e      r      t           y      u      i      o      p
  a      s      d      f      g           h      j      k      l      ;
  z      x      c      v      b           n      m      ,      .      /
  #if defined (MIRYOKU_LAYERS_FLIP)
  Missing255 Missing255 Missing255 Missing255 spc Missing255
  #else
                esc    spc    tab         ent    bspc   del
  #endif
  U_QUOT
#else
  1      2      3      4      5           8      9      0      -      =
  q      w      e      r      t           i      o      p      [      ]
  a      s      d      f      g           k      l      ;      U_QUOT ent
                x      c      v           m      ,      .
#endif
)

(deflayer BASE
U_MACRO_VA_ARGS(MIRYOKU_MAPPING, MIRYOKU_LAYER_BASE)
)

(deflayer BUTTON
U_MACRO_VA_ARGS(MIRYOKU_MAPPING, MIRYOKU_LAYER_BUTTON)
)

(deflayer NAV
U_MACRO_VA_ARGS(MIRYOKU_MAPPING, MIRYOKU_LAYER_NAV)
)

(deflayer MOUSE
U_MACRO_VA_ARGS(MIRYOKU_MAPPING, MIRYOKU_LAYER_MOUSE)
)

(deflayer MEDIA
U_MACRO_VA_ARGS(MIRYOKU_MAPPING, MIRYOKU_LAYER_MEDIA)
)

(deflayer NUM
U_MACRO_VA_ARGS(MIRYOKU_MAPPING, MIRYOKU_LAYER_NUM)
)

(deflayer SYM
U_MACRO_VA_ARGS(MIRYOKU_MAPPING, MIRYOKU_LAYER_SYM)
)

(deflayer FUN
U_MACRO_VA_ARGS(MIRYOKU_MAPPING, MIRYOKU_LAYER_FUN)
)

(deflayer NSYM
U_MACRO_VA_ARGS(MIRYOKU_MAPPING, MIRYOKU_LAYER_NSYM)
)

(deflayer BRAC
U_MACRO_VA_ARGS(MIRYOKU_MAPPING, MIRYOKU_LAYER_BRAC)
)

(deflayer PUNC
U_MACRO_VA_ARGS(MIRYOKU_MAPPING, MIRYOKU_LAYER_PUNC)
)
