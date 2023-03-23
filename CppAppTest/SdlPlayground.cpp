#include "SdlPlayground.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <windows.h>
using namespace std;

const int WIDTH = 640;
const int HEIGHT = 480;
SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;
SDL_Surface* screenSurface = NULL; //The surface contained by the window
SDL_Surface* bird = NULL; //The image we will load and show on the screen
int step = 20;
int countSeeds = 0;
int indexSeeds = 0;
int eatenSeeds = 0;
int seedWidth = 0;
int seedHeight = 0;

SDL_Rect m_image_position;

bool quit = false; //Main loop flag

class Seed 
{
    public:
        int x;
        int y;
        int i;
};
Seed seeds[1] = { NULL };

void renderText() 
{
    ////this opens a font style and sets a size
    //TTF_Font* Sans = TTF_OpenFont("Sans.ttf", 24);

    //// this is the color in rgb format,
    //// maxing out all would give you the color white,
    //// and it will be your text's color
    //SDL_Color White = { 255, 255, 255 };

    //// as TTF_RenderText_Solid could only be used on
    //// SDL_Surface then you have to create the surface first
    //SDL_Surface* surfaceMessage =
    //    TTF_RenderText_Solid(Sans, "put your text here", White);

    //// now you can convert it into a texture
    //SDL_Texture* Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);

    //SDL_Rect Message_rect; //create a rect
    //Message_rect.x = 0;  //controls the rect's x coordinate 
    //Message_rect.y = 0; // controls the rect's y coordinte
    //Message_rect.w = 100; // controls the width of the rect
    //Message_rect.h = 100; // controls the height of the rect

    //// (0,0) is on the top left of the window/screen,
    //// think a rect as the text's box,
    //// that way it would be very simple to understand

    //// Now since it's a texture, you have to put RenderCopy
    //// in your game loop area, the area where the whole code executes

    //// you put the renderer's name first, the Message,
    //// the crop size (you can ignore this if you don't want
    //// to dabble with cropping), and the rect which is the size
    //// and coordinate of your texture
    //SDL_RenderCopy(renderer, Message, NULL, &Message_rect);
}

void updateSeeds(int i) 
{
    int x_new;
    int y_new;
    srand((unsigned)(WIDTH + seeds[i].x));
    x_new = (rand() % (WIDTH - 50)) + 1;
    srand((unsigned)(HEIGHT + seeds[i].y));
    y_new = (rand() % (HEIGHT - 50)) + 1;
    Seed seed;
    seed.x = x_new;
    seed.y = y_new;
    seed.i = i;
    seeds[i] = seed;
    countSeeds += 1;

    //Get window surface
    screenSurface = SDL_GetWindowSurface(window);

    //Load splash image
    SDL_Surface* seedImage = SDL_LoadBMP("images/seed.bmp");
    SDL_Rect seedPosition;
    seedPosition.x = seed.x;
    seedPosition.y = seed.y;

    SDL_BlitSurface(seedImage, NULL, screenSurface, &seedPosition);
    seedHeight = seedPosition.h;
    seedWidth = seedPosition.w;
    //Update the surface
    SDL_UpdateWindowSurface(window);
}

void checkEaten() 
{
    for (Seed s : seeds) 
    {
        if ((&s != NULL) && ((s.x - step*2 < m_image_position.x) && (m_image_position.x < s.x + step*2))
            && ((s.y - step*2 < m_image_position.y) && (m_image_position.y < s.y + step*2)))
        {
            eatenSeeds += 1;
            updateSeeds(s.i);

            SDL_Rect seed_position;
            seed_position.x = s.x;
            seed_position.y = s.y;
            seed_position.w = seedWidth;
            seed_position.h = seedHeight;

            SDL_FillRect(
                screenSurface,
                &seed_position,
                SDL_MapRGB(screenSurface->format, 0, 0, 0));
        }
    }
}

void getImageToScreen()
{
    //Get window surface
    screenSurface = SDL_GetWindowSurface(window);

    //Load splash image
    bird = SDL_LoadBMP("images/bitbird.bmp");

    SDL_BlitSurface(bird, NULL, screenSurface, &m_image_position);
    //Update the surface
    SDL_UpdateWindowSurface(window);

    checkEaten();
}

void fillBirdBlackBox() 
{
    SDL_FillRect(
        screenSurface,
        &m_image_position,
        SDL_MapRGB(screenSurface->format, 0, 0, 0));
}

void keyHandling() 
{
    m_image_position.x = 0;
    m_image_position.y = 0;

    getImageToScreen();
    //updateSeeds(0);

    //Event handler
    SDL_Event e;

    //While application is running
    while (!quit) 
    {
        //Handle events on queue
        while (SDL_PollEvent(&e) != 0)
        {
            //User requests quit
            if (e.type == SDL_QUIT)
            {
                quit = true;
            }
            //User presses a key
            else if (e.type == SDL_KEYDOWN)
            {
                //Select surfaces based on key press
                switch (e.key.keysym.sym)
                {
                case SDLK_UP:
                    fillBirdBlackBox();
                    m_image_position.y -= step;
                    getImageToScreen();
                    break;

                case SDLK_DOWN:
                    fillBirdBlackBox();
                    m_image_position.y += step;
                    getImageToScreen();
                    break;

                case SDLK_LEFT:
                    fillBirdBlackBox();
                    m_image_position.x -= step;
                    getImageToScreen();
                    break;

                case SDLK_RIGHT:
                    fillBirdBlackBox();
                    m_image_position.x += step;
                    getImageToScreen();
                    break;

                default:
                    break;
                }
            }
        }
    }
}



void quitFunc() 
{
    //Deallocate surface
    SDL_FreeSurface(screenSurface);
    SDL_FreeSurface(bird);
    bird = NULL;
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void initSdl() 
{
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow(
        "SDL2 Test", 
        SDL_WINDOWPOS_UNDEFINED, 
        SDL_WINDOWPOS_UNDEFINED, 
        WIDTH, 
        HEIGHT, 
        SDL_WINDOW_SHOWN);

    renderer = SDL_CreateRenderer(
        window, 
        -1, 
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    keyHandling();
    quitFunc();
}