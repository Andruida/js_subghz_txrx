#pragma once

#include "functions/js_subghz_txrx_i.h"
#include "lib/subghz_txrx_i.h"
#include "lib/js_modules.h"

bool js_subghz_txrx_get_context(
    struct mjs* mjs,
    mjs_val_t* obj_inst,
    JsSubghzTxRxInst** js_subghz_txrx,
    SubGhzTxRx** instance);

bool js_subghz_txrx_check_arg_count(struct mjs* mjs, size_t count);