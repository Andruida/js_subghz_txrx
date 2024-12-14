#include "js_subghz_txrx.h"

void js_subghz_txrx_load_decoder_by_name_protocol(struct mjs* mjs) {
    char* name_protocol;
    JS_FETCH_ARGS_OR_RETURN(mjs, JS_EXACTLY, JS_ARG_STR(&name_protocol));
    JsSubghzTxRxInst* js_subghz_txrx;
    SubGhzTxRx* instance;
    if(!js_subghz_txrx_get_context(mjs, &js_subghz_txrx, &instance)) return;

    bool result = subghz_txrx_load_decoder_by_name_protocol(instance, name_protocol);

    mjs_return(mjs, mjs_mk_boolean(mjs, result));
}