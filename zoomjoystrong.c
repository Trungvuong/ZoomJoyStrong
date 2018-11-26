/**********************************************************************
 * This C program helps create drawings that can be made through our 
 * newly created language ZoomJoyStrong.
 *
 * @author Trung-Vuong Pham
 * @date November 26, 2018
 *********************************************************************/

#include "zoomjoystrong.h"
#include <math.h>
#include <SDL2/SDL.h>
#include <unistd.h>

struct color current;

/**********************************************************************
 * This function setups the windows and background for the drawing
 * created by the language.
 *********************************************************************/
void setup(){
	window = SDL_CreateWindow
		(
		 "ZoomJoyString", SDL_WINDOWPOS_UNDEFINED,
		 SDL_WINDOWPOS_UNDEFINED,
		 WIDTH,
		 HEIGHT,
		 SDL_WINDOW_ALLOW_HIGHDPI | SDL_WINDOW_SHOWN
		);

	renderer =  SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED);
	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
	texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, WIDTH, HEIGHT);
	SDL_SetRenderTarget(renderer, texture);
	SDL_RenderSetScale( renderer, 3.0, 3.0 );
	
	SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );
	SDL_RenderClear( renderer );
	SDL_SetRenderDrawColor( renderer, 0, 0, 0, 255);	
	current.r = 0;
	current.b = 0;
	current.g = 0;
}

/**********************************************************************
 * This function sets the color of an object in the language.
 *
 * @param r Sets the shade of color
 * @param g Sets the shade of color
 * @param b Sets another shade of color
 *********************************************************************/
void set_color( int r, int g, int b){
	current.r = r;
	current.b = g;
	current.g = b;
	SDL_SetRenderDrawColor( renderer, r, g, b, 255);
}

/**********************************************************************
 * Creates a point using the language.
 *
 * @param x The x-coordinate of the point
 * @param y The y-coordinate of the point
 *********************************************************************/
void point( int x, int y ){
	SDL_SetRenderTarget(renderer, texture);
	SDL_RenderDrawPoint(renderer, x, y);	
	SDL_SetRenderTarget(renderer, NULL);
	SDL_RenderCopy(renderer, texture, NULL, NULL);
	SDL_RenderPresent(renderer);
}

/**********************************************************************
 * This draws a line with our language.
 *
 * @param x1 The x-coordinate of the starting point of line
 * @param y1 The y-coordinate of the starting point of line
 * @param x2 x-coordinate to the endpoint of line
 * @param y2 y-coordinate to the endpoint of line
 *********************************************************************/
void line( int x1, int y1, int x2, int y2 ){
	SDL_SetRenderTarget(renderer, texture);
	SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
	SDL_SetRenderTarget(renderer, NULL);
	SDL_RenderCopy(renderer, texture, NULL, NULL);
	SDL_RenderPresent(renderer);
}

/**********************************************************************
 * This function just draws a circle based on the radius and 
 * coordinates.
 *
 * @param x The x-coordinate of the point
 * @param y The y-coordinate of the point
 * @param r The radius of the circle
 *********************************************************************/
void circle(int x, int y, int r){
	for(float i=0; i<2 * 3.14; i+=.01){
		float u = x + r * cos(i);
		float v = y + r * sin(i);
		point(u, v);
	}
} 

/**********************************************************************
 * This function draws a rectangle with the language we created.
 *
 * @param x x-coordinate of line
 * @param y y-coordinate of line
 * @param w The width of the rectangle
 * @param h The height of the rectangle
 *********************************************************************/
void rectangle(int x, int y, int w, int h){
	SDL_Rect rect;
	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;
	SDL_SetRenderTarget(renderer, texture);
        SDL_RenderDrawRect(renderer, &rect);
        SDL_SetRenderTarget(renderer, NULL);
        SDL_RenderCopy(renderer, texture, NULL, NULL);
        SDL_RenderPresent(renderer);
}

/********************************************************************** 
 * This function finishes the drawings.
 **********************************************************************/
void finish(){
	SDL_Delay(5000);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

