//
// Created by SACHET WASTI on 04/05/24.
//

#ifndef SDLINTRO_SCREEN_H
#define SDLINTRO_SCREEN_H
#include <cstdint>
#include "Color.h"
#include "ScreenBuffer.h"

struct SDL_Window;
struct SDL_Surface;

class Screen {
public:
    static const int SCREEN_WIDTH=224;
    static const int SCREEN_HEIGHT = 288;
    Screen();
    ~Screen();

    SDL_Window* Init(uint32_t w, uint32_t h, uint32_t mag);
    void SwapScreen();

    inline void SetClearColor(const Color& clearColor){mClearColor = clearColor;}
    inline uint32_t Width() const {return mWidth;}
    inline uint32_t Height() const {return mHeight;}

    //Draw Methods
    void Draw(int x, int y, const Color& color);

private:

    Screen(const Screen& screen);
    Screen& operator=(const Screen& screen);

    void ClearScreen();

    uint32_t mWidth;
    uint32_t mHeight;

    Color mClearColor;
    ScreenBuffer mBackBuffer;

    SDL_Window* mnoptrWindow;
    SDL_Surface* mnoptrSurface;
};


#endif //SDLINTRO_SCREEN_H
