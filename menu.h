#ifndef _MENU_H
#define _MENU_H
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>

void background_load(SDL_Surface *image,char nom[],SDL_Rect pos1);
void music_play(Mix_Music *music);
void play_but(SDL_Surface *play,char nom[],SDL_Rect playpos);
void credits_but(SDL_Surface *credits,char nom[],SDL_Rect creditspos);
void settings_but(SDL_Surface *settings,char nom[],SDL_Rect settingspos);
void quit_but(SDL_Surface *quit,char nom[],SDL_Rect quitpos);
void mute_but(SDL_Surface *mute,char nom[],SDL_Rect mutepos);
void titre(SDL_Surface *title,TTF_Font *fonttitle,SDL_Rect postitle);


#endif
