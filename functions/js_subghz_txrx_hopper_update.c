#include "js_subghz_txrx.h"

void js_subghz_txrx_hopper_update(struct mjs* mjs) {
    mjs_val_t stay_threshold_arg;
    JS_FETCH_ARGS_OR_RETURN(mjs, JS_EXACTLY, JS_ARG_ANY(&stay_threshold_arg));
    JsSubghzTxRxInst* js_subghz_txrx;
    SubGhzTxRx* instance;
    if(!js_subghz_txrx_get_context(mjs, &js_subghz_txrx, &instance)) return;

    if(!mjs_is_number(stay_threshold_arg)) {
        JS_THROW_BAD_TYPE("stay_threshold has to be a number");
    }
    float stay_threshold = (float)mjs_get_double(mjs, stay_threshold_arg);

    subghz_txrx_hopper_update(instance, stay_threshold);

    mjs_return(mjs, MJS_UNDEFINED);
}