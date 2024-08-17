#include "util.h"

bool js_subghz_txrx_get_context(
    struct mjs* mjs,
    mjs_val_t* obj_inst,
    JsSubghzTxRxInst** js_subghz_txrx,
    SubGhzTxRx** instance) {
    *obj_inst = mjs_get(mjs, mjs_get_this(mjs), INST_PROP_NAME, ~0);
    *js_subghz_txrx = (JsSubghzTxRxInst*)mjs_get_ptr(mjs, *obj_inst);
    furi_check(*js_subghz_txrx);

    if((*js_subghz_txrx)->txrx == NULL) {
        mjs_prepend_errorf(mjs, MJS_INTERNAL_ERROR, "already called free, call alloc first");
        mjs_return(mjs, MJS_UNDEFINED);
        return false;
    }
    *instance = (*js_subghz_txrx)->txrx;

    furi_check(*obj_inst);
    furi_check(*js_subghz_txrx);
    furi_check(*instance);

    return true;
}

bool js_subghz_txrx_check_arg_count(struct mjs* mjs, size_t count) {
    size_t num_args = mjs_nargs(mjs);
    if(num_args != count) {
        mjs_prepend_errorf(
            mjs, MJS_BAD_ARGS_ERROR, "expected %i arguments, got %i", count, num_args);
        mjs_return(mjs, MJS_UNDEFINED);
        return false;
    }
    return true;
}