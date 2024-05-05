#include <iostream>
#include <vector>
#include <SDL2/SDL.h>
#include <random>
#include "Graphics/Color.h"
#include "Graphics/Screen.h"
using namespace std;

const int SCREEN_WIDTH=224;
const int SCREEN_HEIGHT = 288;
const int MAGNIFICATION = 3;

int main() {

    vector<pair<int, int>> v = {{100, 200},
                                {133, 230},
                                {SCREEN_WIDTH/2, SCREEN_HEIGHT/2},
                                {124, 222},
                                {213, 234}};

    Screen theScreen;
    theScreen.Init(SCREEN_WIDTH, SCREEN_HEIGHT, MAGNIFICATION);

    srandom(time(nullptr));
    for (auto i: v) {
        long r = random();
        long g = random();
        long b = random();
        long a = random();
        cout<<r<<" "<<g<<" "<<b<<" "<<a<<endl;
        Color color(r%256, g%256, b%256, a%256);
        theScreen.Draw(i.first, i.second, color);
    }
    theScreen.SwapScreen();

    SDL_Event sdlEvent;
    bool running = true;
    while (running) {
        while (SDL_PollEvent(&sdlEvent)) {
            switch (sdlEvent.type) {
                case SDL_QUIT:
                    running = false;
                    break;
            }
        }
    }

    return 0;
}