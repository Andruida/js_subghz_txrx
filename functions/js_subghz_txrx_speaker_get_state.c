#include "js_subghz_txrx.h"

void js_subghz_txrx_speaker_get_state(struct mjs* mjs) {
    JS_FETCH_ARGS_OR_RETURN(mjs, JS_EXACTLY); // 0 args
    JsSubghzTxRxInst* js_subghz_txrx;
    SubGhzTxRx* instance;
    if(!js_subghz_txrx_get_context(mjs, &js_subghz_txrx, &instance)) return;

    SubGhzSpeakerState state = subghz_txrx_speaker_get_state(instance);

    mjs_return(mjs, mjs_mk_number(mjs, (double)state));
}