#pragma once

#include <ghudcpp/types.h>

namespace GHUD {
    namespace Utils {
        static inline fvec2 ConvertScreenCoordToGPUCoord(fvec2 coord) {
            return fvec2(coord.x - 0.5, -(coord.y - 0.5)) * 2.0f;
        }
        static inline fvec2 FlipYCoord(fvec2 coord) {
            return fvec2(coord.x, -coord.y);
        }
        static inline fvec4 ConvertHexColorToFloat4Color(RGBAColor color) {           
            return fvec4(
                float(color.r) / 255.0f,
                float(color.g) / 255.0f,
                float(color.b) / 255.0f,
                float(color.a) / 255.0f
            );
        }
        static inline fvec2 GetAbsoluteCoord(fvec2 coord, float aspectRatio) {
            return fvec2(((coord.x - 0.5) * 2.0 * aspectRatio) * 0.5 + 0.5, coord.y);
        }
    };
}