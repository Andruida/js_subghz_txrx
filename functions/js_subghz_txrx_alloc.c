#include "js_subghz_txrx.h"

void js_subghz_txrx_alloc(struct mjs* mjs) {
    if(!js_subghz_txrx_check_arg_count(mjs, 0)) return;
    mjs_val_t obj_inst = mjs_get(mjs, mjs_get_this(mjs), INST_PROP_NAME, ~0);
    JsSubghzTxRxInst* js_subghz_txrx = mjs_get_ptr(mjs, obj_inst);
    furi_check(js_subghz_txrx);

    if(js_subghz_txrx->txrx != NULL) JS_THROW("alloc already called, call free first");

    js_subghz_txrx->txrx = subghz_txrx_alloc();

    mjs_return(mjs, MJS_UNDEFINED);
}
