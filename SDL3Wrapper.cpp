#include <iostream>
#include <SDL3/SDL.h>
#include "sdl3.h"

int main() {
    SDL3 sdl3(0x00000020);  // Видео подсистема

    std::cout << "✔ Video subsystem loaded successfully!" << std::endl;

    sdl3.createWindow("test", 800, 600, 0x0000000000000020);

    system("pause");

    sdl3.DestroyWindow();  // Функция из ДЗ
    return 0;
}

void SDL3::DestroyWindow() {
    if (window != nullptr) {
        SDL_DestroyWindow(window);
        window = nullptr;
    }
}