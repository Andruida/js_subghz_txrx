#include "js_subghz_txrx.h"

void js_subghz_txrx_hopper_set_state(struct mjs* mjs) {
    SubGhzHopperState state;
    JS_ENUM_MAP(
        state,
        {"OFF", SubGhzHopperStateOFF},
        {"Running", SubGhzHopperStateRunning},
        {"Pause", SubGhzHopperStatePause},
        {"RSSITimeOut", SubGhzHopperStateRSSITimeOut});
    JS_FETCH_ARGS_OR_RETURN(mjs, JS_EXACTLY, JS_ARG_ENUM(state, "SubGhzHopperState"));
    JsSubghzTxRxInst* js_subghz_txrx;
    SubGhzTxRx* instance;
    if(!js_subghz_txrx_get_context(mjs, &js_subghz_txrx, &instance)) return;

    subghz_txrx_hopper_set_state(instance, state);

    mjs_return(mjs, MJS_UNDEFINED);
}
