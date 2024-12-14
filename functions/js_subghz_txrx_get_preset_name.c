#include "js_subghz_txrx.h"

void js_subghz_txrx_get_preset_name(struct mjs* mjs) {
    const char* preset;
    JS_FETCH_ARGS_OR_RETURN(mjs, JS_EXACTLY, JS_ARG_STR(&preset));
    JsSubghzTxRxInst* js_subghz_txrx;
    SubGhzTxRx* instance;
    if(!js_subghz_txrx_get_context(mjs, &js_subghz_txrx, &instance)) return;

    const char* preset_name = subghz_txrx_get_preset_name(instance, preset);

    mjs_return(mjs, mjs_mk_string(mjs, preset_name, ~0, true));
}
