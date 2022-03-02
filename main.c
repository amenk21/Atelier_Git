#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <assert.h>
#include "menu.h"
int main(void)
{
    // declaration de window
    int done = 0;
    float vol = 100;
    int width = 1024;
    int height = 768;
    int volume = 120;
    int i = 0;
    SDL_Event event;
    SDL_Rect pos1;
    SDL_Rect quitpos;
    SDL_Rect playpos;
    SDL_Rect settingspos;
    SDL_Rect creditspos;
    SDL_Rect quitbutpos;
    SDL_Rect postitle;
    SDL_Rect settings22pos;
    SDL_Rect soundpos;
    SDL_Rect mutepos;
    SDL_Rect mute2pos;
    SDL_Surface *mute2;
    SDL_Rect squitpos;
    SDL_Rect posback2;
    SDL_Rect credits22pos;
    SDL_Rect yes2pos ;
      SDL_Rect sound2pos ; 
      SDL_Rect  sound3pos ;
      SDL_Rect posvolume ;
      SDL_Rect returnpos ;
    
    bool test;
    // passive
    SDL_Rect play2pos;
    SDL_Rect settings2pos;
    SDL_Rect credits2pos;
    SDL_Rect quit2pos;
    Mix_Chunk *gMusic = NULL;
int j = 0 ;
    int a = 1;
    int b = 1;
    bool running;
    int over = 0;
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) > 0)
    {
        fprintf(stderr, "Unable to init SDL: %s\n", SDL_GetError());
        return EXIT_FAILURE;
        // make sure SDL cleans up before exit
    }
    atexit(SDL_Quit);

    SDL_Surface *screen;
    screen = SDL_SetVideoMode(width, height, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    if (!screen)
    {
        fprintf(stderr, "Unable to set video: %s\n", SDL_GetError());
        return EXIT_FAILURE;
    }

    // window Title
    SDL_WM_SetCaption("The Rise Of Great Carthage", NULL);

    // background load
    SDL_Surface *image = SDL_LoadBMP("final.bmp");
    pos1.x = 0;
    pos1.y = 0;
    pos1.h = image->h;
    pos1.w = image->w;
  
     // audio
    Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 1024);
    // DECLARE AND SET MUSIC
    Mix_Music *music;
    music = Mix_LoadMUS("gladiator.mp3");
    Mix_VolumeMusic(vol);
    Mix_PlayMusic(music, -1);
   
    
    // mute button
    SDL_Surface *mute = SDL_LoadBMP("m.bmp");
    mutepos.x = 0;
    mutepos.y = 10;
    mutepos.h = mute->h;
    mutepos.w = mute->w;

    // play button

    SDL_Surface *play = SDL_LoadBMP("playfinal.bmp");
    playpos.x = 700;
    playpos.y = 160;
    playpos.h = play->h;
    playpos.w = play->w;



    // settings button

    SDL_Surface *settings = IMG_Load("settings.png");
    settingspos.x = 700; //+205
    settingspos.y = 215; //+34 //+55 difference
    settingspos.h = settings->h;
    settingspos.w = settings->w;

    // credits button
    SDL_Surface *credits = SDL_LoadBMP("creditsfinal.bmp");
    creditspos.x = 700;
    creditspos.y = 270;//+55 difference
    creditspos.h = credits->h;
    creditspos.w = credits->w;

    // quit button
    SDL_Surface *quitbut = IMG_Load("quit.bmp");
    quitpos.x = 700;
    quitpos.y = 325;//+55 difference
    quitbutpos.h = quitbut->h;
    quitbutpos.w = quitbut->w;
    //sound def 
   
    // font
    TTF_Init();
    SDL_Surface *title;
    TTF_Font *fonttitle;
    fonttitle = TTF_OpenFont("MORPHEUS.TTF", 50);
    SDL_Color blanc = {0, 0, 0};
    if (TTF_Init() < 0)
    { // init ttf pour l'écriture
        fprintf(stderr, "Erreur à l'initialisation de la SDL : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    else
    {
        title = TTF_RenderText_Solid(fonttitle, "The Rise Of Great Carthage", blanc);
        postitle.x = 400; //340
        postitle.y = 0;
    }
    
    while (!over)
    {
        SDL_BlitSurface(image, NULL, screen, &pos1);
        
        SDL_BlitSurface(play, NULL, screen, &playpos);
        SDL_BlitSurface(settings, NULL, screen, &settingspos);
        SDL_BlitSurface(credits, NULL, screen, &creditspos);
        SDL_BlitSurface(quitbut, NULL, screen, &quitpos);
        SDL_BlitSurface(title, NULL, screen, &postitle);
        SDL_BlitSurface(mute, NULL, screen, &mutepos);
        SDL_Flip(screen);


        // evenntt
        //  message processing loop

        SDL_Event event;

        SDL_WaitEvent(&event);

        // check for messages
        switch (event.type)
        {
            // exit if the window is closed
        case SDL_QUIT:
            over = 1;
            break;
            // mouse motion

        case SDL_MOUSEMOTION:

            if (event.motion.x > 700 && event.motion.y > 159 && event.motion.x < 904 && event.motion.y < 193)
            {
                // cursor play
                gMusic = Mix_LoadWAV("scroll.wav");
                Mix_PlayChannel(-1, gMusic, 0);
                SDL_FreeSurface(play);
                SDL_Surface *play2 = SDL_LoadBMP("play2.bmp");
                play2pos.x = 700;
                play2pos.y = 160;
                play2pos.h = play2->h;
                play2pos.w = play2->w;
            }
            // rect

            // cursor settings
            else if (event.motion.x > 700 && event.motion.y > 215 && event.motion.x < 904 && event.motion.y < 249)
            {
                // ww
                test = false;
                gMusic = Mix_LoadWAV("scroll.wav");
                Mix_PlayChannel(-1, gMusic, 0);
                SDL_FreeSurface(settings);
                SDL_Surface *settings2 = SDL_LoadBMP("settings2.bmp");
                settingspos.x = 700; //+205
                settingspos.y = 215; //+34
                settings2pos.h = settings2->h;
                settings2pos.w = settings2->w;
            }
            // cursor credits
            else if (event.motion.x > 700 && event.motion.y > 270 && event.motion.x < 904 && event.motion.y < 304)
            {
                gMusic = Mix_LoadWAV("scroll.wav");
                Mix_PlayChannel(-1, gMusic, 0);
                SDL_FreeSurface(credits);
                SDL_Surface *credits2 = SDL_LoadBMP("credits2.bmp");
                credits2pos.x = 700;
                credits2pos.y = 270;
                credits2pos.h = credits2->h;
                credits2pos.w = credits2->w;
            }
            // cursor quit
            else if (event.motion.x > 700 && event.motion.y > 336 && event.motion.x < 904 && event.motion.y < 370)
            {
                gMusic = Mix_LoadWAV("scroll.wav");
                Mix_PlayChannel(-1, gMusic, 0);
                SDL_FreeSurface(quitbut);
                SDL_Surface *quit2 = SDL_LoadBMP("quit2.bmp");
                quit2pos.x = 700;
                quit2pos.y = 325;
                quit2pos.h = quit2->h;
                quit2pos.w = quit2->w;
            }

            else
            {
                SDL_FreeSurface(play);
                SDL_Surface *play = SDL_LoadBMP("playfinal.bmp");
                SDL_FreeSurface(settings);
                SDL_Surface *settings = IMG_Load("settings.png");
                SDL_FreeSurface(credits);
                SDL_Surface *credits = SDL_LoadBMP("creditsfinal.bmp");
                SDL_FreeSurface(quitbut);
                SDL_Surface *quit = IMG_Load("quit.bmp");
            }

            // check for keypresses
        case SDL_KEYDOWN:
        {
            if (event.key.keysym.sym == SDLK_DOWN)
            {
                gMusic = Mix_LoadWAV("scroll.wav");
                Mix_PlayChannel(-1, gMusic, 0);
                SDL_FreeSurface(play);
                SDL_Surface *play2 = SDL_LoadBMP("play2.bmp");
                play2pos.x = 700;
                play2pos.y = 160;
                play2pos.h = play2->h;
                play2pos.w = play2->w;
            }
            else if ((event.key.keysym.sym == SDLK_DOWN) && (event.motion.x > 700 && event.motion.y > 215 && event.motion.x < 904 && event.motion.y < 249))
            {

                SDL_Surface *settings = SDL_LoadBMP("backk.bmp");
                settingspos.x = 700; //+205
                settingspos.y = 215; //+34
                settingspos.h = settings->h;
                settingspos.w = settings->w;
            }
            // exit if ESCAPE is pressed
            if (event.key.keysym.sym == SDLK_ESCAPE)
                over = 1;

            else if (event.key.keysym.sym == SDLK_f)
                if (a > 0)
                    screen = SDL_SetVideoMode(width, height, 32, SDL_HWSURFACE | SDL_FULLSCREEN);
                else
                    screen = SDL_SetVideoMode(width, height, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
            a *= -1;
            break;
        }
 
        case SDL_MOUSEBUTTONDOWN:
            if (event.motion.x > 700 && event.motion.y > 215 && event.motion.x < 904 && event.motion.y < 249)
            {
                SDL_Surface *settings2 = SDL_LoadBMP("background2.bmp");
                settings22pos.x = 0; //+205
                settings22pos.y = 0; //+34
                settings22pos.h = settings2->h;
                settings22pos.w = settings2->w;
                SDL_BlitSurface(settings2, NULL, screen, &settings22pos);
                SDL_Flip(screen);
                if (j == 0){
            SDL_Surface *sound = IMG_Load("sound8.jpg");
                        soundpos.x=700;
                        soundpos.y=100;
                        
                       SDL_BlitSurface(sound,NULL, screen,&soundpos);
                       SDL_Flip(screen);
    }
    j =1 ;
                int isRunning =1;
                while(isRunning){
                
                SDL_WaitEvent(&event);
                        
                       SDL_Surface *returnbut = IMG_Load("ret.png");
    returnpos.x = 900;
    returnpos.y = 650;//+55 difference
    returnpos.h = returnbut->h;
    returnpos.w = returnbut->w;
     SDL_BlitSurface(returnbut, NULL, screen, &returnpos);
                         SDL_Flip(screen);
                
                SDL_Event event2;
                SDL_WaitEvent(&event2);
                switch (event2.type){
                //DOWN !!!!!!
  case SDL_MOUSEBUTTONUP:
             

                if (event2.button.button == SDL_BUTTON_LEFT)
         	{
            //return 
             if (j == 0){
            SDL_Surface *sound = IMG_Load("sound8.jpg");
                        soundpos.x=700;
                        soundpos.y=100;
                        
                       SDL_BlitSurface(sound,NULL, screen,&soundpos);
                       SDL_Flip(screen);
    }
    j =1 ;
 if(event2.button.x>908 && event2.button.x<969 && event2.button.y>655 && event2.button.y<712 )
	        	{//newwwwwwwwwwwwwwwwwwwww
	        	
                 isRunning = 0;
	        	}
	        	//^^
	        	
	        	//click on plus
	        	if(event2.button.x>861 && event2.button.x<893 && event2.button.y>115 && event2.button.y<134 )
	        	{
	        	
	        	//prev
	        		if((vol)<100)
	                {
	                  
	        	
	                	(vol)+=20;
	                	
	                }
                   
	                Mix_VolumeMusic(vol);
	               
                 printf("%f\n",vol);
                 //sound 100
	        	 if (vol == 100){
             
	        	 SDL_Surface *sound8 = IMG_Load("sound8.jpg");
                        sound2pos.x=700;
                        sound2pos.y=100;
                       SDL_BlitSurface(sound8,NULL, screen,&sound2pos);
                         SDL_Flip(screen); } 
               
                 //sound 80
	        	 if (vol == 80){
             
	        	 SDL_Surface *sound80 = IMG_Load("sound77.jpg");
                        sound2pos.x=700;
                        sound2pos.y=100;
                       SDL_BlitSurface(sound80,NULL, screen,&sound2pos);
                         SDL_Flip(screen); }
                 //sound 60
	        	 if (vol == 60){
               
	        	 SDL_Surface *sound60 = IMG_Load("sound60.jpg");
                        sound2pos.x=700;
                        sound2pos.y=100;
                       SDL_BlitSurface(sound60,NULL, screen,&sound2pos);
                         SDL_Flip(screen); }
                //sound 40
                          if (vol == 40){
              
	        	 SDL_Surface *sound4 = IMG_Load("sound4.jpg");
                        sound2pos.x=700;
                        sound2pos.y=100;
                       SDL_BlitSurface(sound4,NULL, screen,&sound2pos);
                         SDL_Flip(screen); }
                         //sound 20
                         if (vol == 20){
               
	        	 SDL_Surface *sound20 = IMG_Load("sound20.jpg");
                        sound2pos.x=700;
                        sound2pos.y=100;
                       SDL_BlitSurface(sound20,NULL, screen,&sound2pos);
                         SDL_Flip(screen); }
	        	
	        	//sound 00
	        	 if (vol == 00){
               
	        	 SDL_Surface *sound00 = IMG_Load("sound0.jpg");
                        sound2pos.x=700;
                        sound2pos.y=100;
                       SDL_BlitSurface(sound00,NULL, screen,&sound2pos);
                         SDL_Flip(screen); }}

	        	//click on moins
	        	if(event2.button.x>706 && event2.button.x<745 && event2.button.y>100 && event2.button.y<134 )
	        	
	        	{
	        		if((vol)>=20)
	                {
	                	(vol)-=20;
	                	
	                }
	                Mix_VolumeMusic(vol);
	                printf("%f\n",vol);
	                   //sound 100
	        	 if (vol == 100){
             
	        	 SDL_Surface *sound8 = IMG_Load("sound8.jpg");
                        sound2pos.x=700;
                        sound2pos.y=100;
                       SDL_BlitSurface(sound8,NULL, screen,&sound2pos);
                         SDL_Flip(screen); } 
	                 //sound 80
	        	 if (vol == 80){
              
	        	 SDL_Surface *sound80 = IMG_Load("sound77.jpg");
                        sound2pos.x=700;
                        sound2pos.y=100;
                       SDL_BlitSurface(sound80,NULL, screen,&sound2pos);
                         SDL_Flip(screen); 
                         }
                 //sound 60
	        	 if (vol == 60){
          
	        	 SDL_Surface *sound60 = IMG_Load("sound60.jpg");
                        sound2pos.x=700;
                        sound2pos.y=100;
                       SDL_BlitSurface(sound60,NULL, screen,&sound2pos);
                         SDL_Flip(screen); }
                        
                //sound 40
                          if (vol == 40){
              
	        	 SDL_Surface *sound4 = IMG_Load("sound4.jpg");
                        sound2pos.x=700;
                        sound2pos.y=100;
                       SDL_BlitSurface(sound4,NULL, screen,&sound2pos);
                         SDL_Flip(screen); }
                         //sound 20
                         if (vol == 20){
                
	        	 SDL_Surface *sound20 = IMG_Load("sound20.jpg");
                        sound2pos.x=700;
                        sound2pos.y=100;
                       SDL_BlitSurface(sound20,NULL, screen,&sound2pos);
                         SDL_Flip(screen); }
	        	
	        	//sound 00
	        	 if (vol == 00){
            
	        	 SDL_Surface *sound00 = IMG_Load("sound0.jpg");
                        sound2pos.x=700;
                        sound2pos.y=100;
                       SDL_BlitSurface(sound00,NULL, screen,&sound2pos);
                         SDL_Flip(screen); }
	        	 }
	        	}}
                
           
                        
                    if(event.type == SDL_QUIT){
                        isRunning = 0;
                    }
                    
                    else if (event.type == SDL_KEYDOWN){
                        if (event.key.keysym.sym == SDLK_ESCAPE)
                            isRunning=0;
                    }
              
      }
}
//newwwwww
               
else if (event.motion.x > 700 && event.motion.y > 270 && event.motion.x < 904 && event.motion.y < 304)
{//font volume
 

//pic
SDL_Surface *credits22 = SDL_LoadBMP("backgroundcredits2.bmp");
                credits22pos.x = 0; //+205
                credits22pos.y = 0; //+34
                credits22pos.h = credits22->h;
                credits22pos.w = credits22->w;
                SDL_BlitSurface(credits22, NULL, screen, &credits22pos);
               SDL_Flip(screen);
            int isRunning =1;
                while(isRunning){
 SDL_WaitEvent(&event);
                if(event.type == SDL_QUIT){
                        isRunning = 0;
                    }
                    else if (event.type == SDL_KEYDOWN){
                        if (event.key.keysym.sym == SDLK_ESCAPE)
                            isRunning=0;
                    }
              
      }

}

            
             else if (event.motion.x > 700 && event.motion.y > 336 && event.motion.x < 904 && event.motion.y < 370)
            {
                
                SDL_Surface *squit = SDL_LoadBMP("squittt.bmp"); // squit
                squitpos.x = 400;
                squitpos.y = 160;
                squitpos.h = squit->h;
                squitpos.w = squit->w;
                SDL_BlitSurface(squit, NULL, screen, &squitpos);
                SDL_Flip(screen);
                int isRunning =1;
                while (isRunning){
                    SDL_PollEvent(&event);
                    if (event.type == SDL_MOUSEBUTTONDOWN){
                       if (event.motion.x > 415 && event.motion.x < 539 && event.motion.y >221 && event.motion.y < 328 ) {
                           /*   SDL_FreeSurface(squit);
                             SDL_Surface *yes2 = IMG_Load("/home/mouda/Downloads/yes2.png"); // squit
                yes2pos.x = 400;
                yes2pos.y = 160;
                yes2pos.h = squit->h;
                yes2pos.w = squit->w;
                SDL_BlitSurface(squit, NULL, screen, &yes2pos);
                SDL_Flip(screen);*/
                            over =1;
                            isRunning =0;
                            printf("Yes");
                       }
                       else if (event.motion.x > 552 && event.motion.x < 798 && event.motion.y >221 && event.motion.y < 328) {
                           isRunning =0;
                           printf("No");
                       }
                    }
                    else if (event.type == SDL_QUIT)
                    SDL_Quit();
                }
            }
            else if (event.motion.x > 0 && event.motion.y > 10 && event.motion.x < 50 && event.motion.y < 60)
            {

                SDL_FreeSurface(mute);
                mute2 = SDL_LoadBMP("mute.bmp");
                mute2pos.x = 0;
                mute2pos.y = 10;
                mute2pos.h = mute2->h;
                mute2pos.w = mute2->w;
                SDL_BlitSurface(mute2, NULL, screen, &mute2pos);
                SDL_Flip(screen);
                Mix_VolumeMusic(0);
                
            }

            else
            {
                SDL_FreeSurface(mute);
                SDL_Surface *mute = SDL_LoadBMP("m.bmp");
                mutepos.x = 0;
                mutepos.y = 10;
                mutepos.h = mute->h;
                mutepos.w = mute->w;
                Mix_VolumeMusic(100);
            }
}
            // or buttondown
            switch (event.button.button)
            {
            case SDL_BUTTON_WHEELUP:
                puts("wheel up !");

                break;
            }
        }
        
    

    SDL_FreeSurface(image);
    SDL_FreeSurface(credits);
    SDL_FreeSurface(settings);
    SDL_FreeSurface(play);
    Mix_FreeMusic(music);
 

    SDL_Quit();
    return 0;
 }

