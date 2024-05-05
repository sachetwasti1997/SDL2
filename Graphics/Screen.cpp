//
// Created by SACHET WASTI on 04/05/24.
//
#include <iostream>
#include "Screen.h"
#include <SDL2/SDL.h>
#include <vector>
#include <cassert>
using namespace std;

Screen::Screen(): mWidth(0), mHeight(0), mnoptrWindow(nullptr),
mnoptrSurface(nullptr){

}
Screen::~Screen(){
    if (mnoptrWindow) {
        SDL_FreeSurface(mnoptrSurface);
        SDL_DestroyWindow(mnoptrWindow);
        mnoptrWindow = nullptr;
        mnoptrSurface = nullptr;
    }
    SDL_Quit();
}

SDL_Window* Screen::Init(uint32_t w, uint32_t h, uint32_t mag){
    if (SDL_Init(SDL_INIT_VIDEO)) {
        cout<<"ERROR: "<<SDL_GetError()<<endl;
        return nullptr;
    }

    mWidth = w;
    mHeight = h;

    mnoptrWindow = SDL_CreateWindow(
            "Arcade",
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            mWidth * mag,
            mHeight * mag,
            0
    );

    if (mnoptrWindow) {
        //2D array of pixels
        //Acts like a canvas, will be using the surface to draw on
        mnoptrSurface = SDL_GetWindowSurface(mnoptrWindow);
        SDL_PixelFormat* pixelFormat = mnoptrSurface ->format;
        Color::InitColorFormat(pixelFormat);
        mClearColor = Color::Black();
        mBackBuffer.Init(pixelFormat->format, mWidth, mHeight);
        mBackBuffer.Clear();
        return mnoptrWindow;
    }

    cout<<"Could not create a window, got error"<<SDL_GetError()<<endl;
    return mnoptrWindow;
}
void Screen::SwapScreen(){
    assert(mnoptrWindow);
    ClearScreen();
    SDL_BlitScaled(mBackBuffer.GetSurface(), nullptr, mnoptrSurface, nullptr);
    SDL_UpdateWindowSurface(mnoptrWindow);
    mBackBuffer.Clear(mClearColor);
}

void Screen::Draw(int x, int y, const Color& color){
    assert(mnoptrWindow);
    mBackBuffer.SetPixel(color.GetPixelColor(), x, y);
}

void Screen::ClearScreen(){
    assert(mnoptrWindow);
    SDL_FillRect(mnoptrSurface, nullptr, mClearColor.GetPixelColor());
}