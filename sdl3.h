#pragma once
#include <string>
#include <Windows.h>
#include <SDL3/SDL.h>

class SDL3 {
private:
    HMODULE lib;
    SDL_Window* window = nullptr;

public:
    SDL3(uint32_t init_flags) {
        if (SDL_Init(init_flags) != 0) {
            std::cerr << "❌ SDL_Init failed: " << SDL_GetError() << std::endl;
            exit(1);
        }
    }

    ~SDL3() {
        DestroyWindow();  // Автоматический вызов
        SDL_Quit();
    }

    void createWindow(const std::string& title, int w, int h, uint64_t flags) {
        window = SDL_CreateWindow(title.c_str(), w, h, static_cast<uint32_t>(flags));
        if (!window) {
            std::cerr << "❌ Failed to create window: " << SDL_GetError() << std::endl;
            exit(1);
        }
    }

    void DestroyWindow();  // Функция из ДЗ
};