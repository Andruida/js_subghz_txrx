#include "js_subghz_txrx.h"

void js_subghz_txrx_hopper_set_state(struct mjs* mjs) {
    if(!js_subghz_txrx_check_arg_count(mjs, 1)) return;
    mjs_val_t obj_inst;
    JsSubghzTxRxInst* js_subghz_txrx;
    SubGhzTxRx* instance;
    if(!js_subghz_txrx_get_context(mjs, &obj_inst, &js_subghz_txrx, &instance)) return;

    mjs_val_t state_arg = mjs_arg(mjs, 0);
    if(!mjs_is_number(state_arg)) {
        JS_THROW_BAD_TYPE("state has to be an integer");
    }
    int state = mjs_get_int(mjs, state_arg);
    if(state < 0 || state > 3) {
        JS_THROW_BAD_ARGS("States 0-3 are defined only (OFF,Running,Pause,RSSITimeOut)");
    }

    subghz_txrx_hopper_set_state(instance, (SubGhzHopperState)state);

    mjs_return(mjs, MJS_UNDEFINED);
}
