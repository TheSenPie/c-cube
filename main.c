#include <stdlib.h>

#include <SDL2/SDL.h>

#include "ccube.h"

#define WINDOW_WIDTH 640 
#define WINDOW_HEIGHT 640

void clearScreen (SDL_Renderer *renderer);

int main(void)
{
	SDL_Event event;
	SDL_Renderer *renderer;
	SDL_Window *window;
	int i;

	SDL_Init(SDL_INIT_VIDEO);	
	SDL_CreateWindowAndRenderer(WINDOW_WIDTH, WINDOW_HEIGHT, 0, &window, &renderer);
	clearScreen(renderer);	

	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	bresenham_line(10, 10, 200, 200, renderer);
	SDL_RenderPresent(renderer);
	while (1)
	{
		SDL_PollEvent(&event);

		if (event.type == SDL_QUIT)
		{
			break;
		}
		else if (event.type == SDL_KEYDOWN)
		{
			switch (event.key.keysym.sym) {
				case SDLK_DOWN:
					printf("Down key pressed");
					break;
			}
		}
	}
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return EXIT_SUCCESS;
}

void clearScreen (SDL_Renderer *renderer) {
	SDL_SetRenderDrawColor(renderer, 136, 204, 77, 255);
	SDL_RenderClear(renderer);
}

