#include "js_subghz_txrx.h"

void js_subghz_txrx_hopper_get_state(struct mjs* mjs) {
    if(!js_subghz_txrx_check_arg_count(mjs, 0)) return;
    mjs_val_t obj_inst;
    JsSubghzTxRxInst* js_subghz_txrx;
    SubGhzTxRx* instance;
    if(!js_subghz_txrx_get_context(mjs, &obj_inst, &js_subghz_txrx, &instance)) return;

    SubGhzHopperState state = subghz_txrx_hopper_get_state(instance);

    mjs_return(mjs, mjs_mk_number(mjs, (double)state));
}