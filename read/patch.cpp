#pragma XOD evaluate_on_pin disable
#pragma XOD evaluate_on_pin enable input_INIT

node {

    void evaluate(Context ctx) {

        // The node responds only if there is an input pulse
        if (!isInputDirty<input_INIT>(ctx))
            return;

        auto sensor = getValue<input_DEV>(ctx);

        if (!sensor->available()) {
            raiseError(ctx);
            return;
        }

        sensor->measure(true);

        emitValue<output_AQI>(ctx, sensor->getAQI());
        emitValue<output_TVOC>(ctx, sensor->getTVOC());
        emitValue<output_eCO2>(ctx, sensor->geteCO2());

        emitValue<output_OK>(ctx, 1);
    }
}
