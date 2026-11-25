#include "../include/loki_patches_universal_build_runtime.hpp"
#include <windows.h>
#include <atomic>

namespace loki_patches_universal_build {
static std::atomic<bool> g_running{true};
void PollHotkeys(bool& menu_open) noexcept {
    if (GetAsyncKeyState(VK_INSERT) & 1) menu_open = !menu_open;
    if (GetAsyncKeyState(VK_END) & 1) g_running.store(false, std::memory_order_relaxed);
}
} // namespace loki_patches_universal_build

int main() {
    bool menu_open = true;
    while (loki_patches_universal_build::g_running.load(std::memory_order_relaxed)) {
        loki_patches_universal_build::PollHotkeys(menu_open);
        Sleep(6);
    }
    return 0;
}
