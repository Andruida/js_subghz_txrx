#include "js_subghz_txrx.h"

void js_subghz_txrx_is_database_loaded(struct mjs* mjs) {
    if(!js_subghz_txrx_check_arg_count(mjs, 0)) return;
    mjs_val_t obj_inst;
    JsSubghzTxRxInst* js_subghz_txrx;
    SubGhzTxRx* instance;
    if(!js_subghz_txrx_get_context(mjs, &obj_inst, &js_subghz_txrx, &instance)) return;

    bool is_loaded = subghz_txrx_is_database_loaded(instance);

    mjs_return(mjs, mjs_mk_boolean(mjs, is_loaded));
}
