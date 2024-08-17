#include "js_subghz_txrx.h"

void js_subghz_txrx_add(struct mjs* mjs) {
    mjs_val_t obj_inst = mjs_get(mjs, mjs_get_this(mjs), INST_PROP_NAME, ~0);
    JsSubghzTxRxInst* js_subghz_txrx = mjs_get_ptr(mjs, obj_inst);
    furi_check(js_subghz_txrx);

    mjs_val_t num_arg = mjs_arg(mjs, 0);
    if(!mjs_is_number(num_arg)) {
        JS_THROW("Argument must be a number");
    }
    int num = mjs_get_int(mjs, num_arg);

    js_subghz_txrx->counter += num;

    // FURI_LOG_I(TAG, "js_subghz_txrx_test current: %d (+%d)", js_subghz_txrx->counter, num);

    mjs_return(mjs, mjs_mk_number(mjs, (double)js_subghz_txrx->counter));
}