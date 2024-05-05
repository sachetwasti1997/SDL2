//
// Created by SACHET WASTI on 04/05/24.
//

#ifndef SDLINTRO_SCREENBUFFER_H
#define SDLINTRO_SCREENBUFFER_H
#include <cstdint>
#include "Color.h"

struct SDL_Surface;

class ScreenBuffer {
public:
    ScreenBuffer();
    ScreenBuffer(const ScreenBuffer& screenBuffer);
    ~ScreenBuffer();

    ScreenBuffer& operator=(const ScreenBuffer& screenBuffer);
    void Init(uint32_t format, uint32_t width, uint32_t height);
    void Clear(const Color& c = Color::Black());
    inline SDL_Surface* GetSurface() {return mSurface;}
    void SetPixel(const Color& color, int x, int y);
private:
    SDL_Surface *mSurface;
    uint32_t GetIndex(int r, int c);
};


#endif //SDLINTRO_SCREENBUFFER_H
