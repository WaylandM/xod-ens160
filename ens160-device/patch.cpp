#pragma XOD require "https://github.com/adafruit/ENS160_driver"

#include <ScioSense_ENS160.h>

node {
    meta {
        using Type = ScioSense_ENS160*;
    }

    uint8_t mem[sizeof(ScioSense_ENS160)];

    void evaluate(Context ctx) {
        if (!isSettingUp())
            return;

        auto wire = getValue<input_I2C>(ctx);
        auto address = getValue<input_ADDR>(ctx);

        Type sensor = new (mem) ScioSense_ENS160(wire, address);

        emitValue<output_DEV>(ctx, &sensor);
    }
}
