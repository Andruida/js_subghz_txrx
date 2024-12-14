#include "js_subghz_txrx.h"

void js_subghz_txrx_speaker_set_state(struct mjs* mjs) {
    SubGhzSpeakerState state;
    JS_ENUM_MAP(
        state,
        {"disable", SubGhzSpeakerStateDisable},
        {"shutdown", SubGhzSpeakerStateShutdown},
        {"enable", SubGhzSpeakerStateEnable});
    JS_FETCH_ARGS_OR_RETURN(mjs, JS_EXACTLY, JS_ARG_ENUM(state, "SubGhzSpeakerState")); // 1 args
    JsSubghzTxRxInst* js_subghz_txrx;
    SubGhzTxRx* instance;
    if(!js_subghz_txrx_get_context(mjs, &js_subghz_txrx, &instance)) return;

    subghz_txrx_speaker_set_state(instance, (SubGhzSpeakerState)state);

    mjs_return(mjs, MJS_UNDEFINED);
}
