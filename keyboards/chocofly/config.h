// Copyright 2022 Vitaly Volkov (@vlkv)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "config_common.h"

// how quickly all combo keys must be pressed in succession to trigger
#define COMBO_TERM 25
// if a combo triggers a modifier, only trigger when the combo is held
#define COMBO_MUST_HOLD_MODS
// how long at least one of the combo keys must be held to trigger
#define COMBO_HOLD_TERM 175