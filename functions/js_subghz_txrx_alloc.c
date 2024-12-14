#include "js_subghz_txrx.h"

void js_subghz_txrx_alloc(struct mjs* mjs) {
    JS_FETCH_ARGS_OR_RETURN(mjs, JS_EXACTLY); // 0 args
    JsSubghzTxRxInst* js_subghz_txrx = JS_GET_CONTEXT(mjs);
    furi_check(js_subghz_txrx);

    if(js_subghz_txrx->txrx != NULL) JS_THROW("alloc already called, call free first");

    js_subghz_txrx->txrx = subghz_txrx_alloc();

    mjs_return(mjs, MJS_UNDEFINED);
}
