#pragma once

#include "functions/js_subghz_txrx_i.h"
#include "lib/subghz_txrx_i.h"
#include <applications/system/js_app/js_modules.h>

bool js_subghz_txrx_get_context(
    struct mjs* mjs,
    JsSubghzTxRxInst** js_subghz_txrx,
    SubGhzTxRx** instance);