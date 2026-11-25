#pragma once
#include <cstdint>

namespace loki_patches_universal_build {
inline constexpr const char* kModuleName = "loki-patches-universal-build";
inline constexpr const char* kBuildSalt = "2f21812c6cf10b07";
struct RuntimeConfig {
    uint32_t target_fps = 144;
    float fov_radius = 65.0f;
    float smooth_factor = 1.45f;
    bool draw_bounds = true;
};
} // namespace loki_patches_universal_build
