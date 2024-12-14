#include "util.h"

bool js_subghz_txrx_get_context(
    struct mjs* mjs,
    JsSubghzTxRxInst** js_subghz_txrx,
    SubGhzTxRx** instance) {
    *js_subghz_txrx = JS_GET_CONTEXT(mjs);
    furi_check(*js_subghz_txrx);

    if((*js_subghz_txrx)->txrx == NULL) {
        mjs_prepend_errorf(mjs, MJS_INTERNAL_ERROR, "already called free, call alloc first");
        mjs_return(mjs, MJS_UNDEFINED);
        return false;
    }
    *instance = (*js_subghz_txrx)->txrx;

    furi_check(*instance);

    return true;
}
