#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <assert.h>
#include "menu.h"

void background_load(SDL_Surface *image,char nom [] ,SDL_Rect pos1)
{
image  = IMG_Load(nom);
pos1.x = 0 ;
pos1.y=0;
pos1.h=image->h ;
pos1.w=image->w ;

}
void music_play(Mix_Music *music)
{music=Mix_LoadMUS("gladiator.mp3");
Mix_VolumeMusic(0);
Mix_PlayMusic(music,-1);
}
void play_but(SDL_Surface *play,char nom[],SDL_Rect playpos)
{play= IMG_Load(nom);
playpos.x=700;
playpos.y=159;
playpos.h=play->h ;
playpos.w=play->w ;

}
void credits_but(SDL_Surface *credits,char nom[],SDL_Rect creditspos)
{
credits= IMG_Load(nom);
creditspos.x=700;
creditspos.y=270;
creditspos.h=credits->h ;
creditspos.w=credits->w ;



}
void settings_but(SDL_Surface *settings,char nom[],SDL_Rect settingspos)
{
settings= IMG_Load(nom);
settingspos.x=700;   //+205
settingspos.y=215;  //+34
settingspos.h=settings->h ;
settingspos.w=settings->w ;




}
void quit_but(SDL_Surface *quit,char nom[],SDL_Rect quitpos)
{

quit= IMG_Load(nom);
quitpos.x=700;
quitpos.y=336;
quitpos.h=quit->h ;
quitpos.w=quit->w ;

}
void mute_but(SDL_Surface *mute,char nom[],SDL_Rect mutepos)
{
mute= IMG_Load(nom);
mutepos.x=0;
mutepos.y=10;
mutepos.h=mute->h ;
mutepos.w=mute->w ;



}




void titre(SDL_Surface *title,TTF_Font *fonttitle,SDL_Rect postitle)
{ SDL_Color blanc ={0,0,0};
title = TTF_RenderText_Solid(fonttitle, "The Rise Of Great Carthage", blanc);
    postitle.x =  400;
    postitle.y = 0;
}
