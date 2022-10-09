#include <stdlib.h>

#include <SDL2/SDL.h>

#include "ccube.h"

#define WINDOW_WIDTH 640 
#define WINDOW_HEIGHT 640

void clearScreen (SDL_Renderer *renderer);
Cube newCube();
Polygon newPolygon(Point *points[]);
Point newPoint(float x, float y, float z, float w);

int main(void)
{
	SDL_Event event;
	SDL_Renderer *renderer;
	SDL_Window *window;
	int i;
	Point[4] p;

	p = newPoint(1, 1, 1, 1);
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

void clearScreen (SDL_Renderer *renderer)
{
	SDL_SetRenderDrawColor(renderer, 136, 204, 77, 255);
	SDL_RenderClear(renderer);
}
/*
Cube newCube ()
{
	Cube cube;
	Polygon face1;
	Polygon face2;
	Polygon face3;
	Polygon face4;

	Point p111 = (1, 1, 1, 1);
	Point p112 = (1, -1, 1, 1);
	Point p113 = (-1, 1, 1, 1);
	Point p114 = (-1, -1, 1, 1);
	Polygon p11 = newPolygon(&p111, &p112, &p113, &p114);

	face2.vertices = {
		{1, 1, 1, -1},
		{1, -1, 1, -1},
		{-1, 1, 1, -1},
		{-1, -1, 1, -1}
	};
	face3.vertices = {
		{1, 1, 1, 1},
		{1, 1, -1, 1},
		{-1, 1, -1, 1},
		{-1, 1, 1, 1}
	};
	face4.vertices = {
		{1, -1, 1, 1},
		{1, -1, -1, 1},
		{-1, -1, -1, 1},
		{-1, -1, 1, 1}
	};
	face5.vertices = {
		{1, 1, 1, 1},
		{1, 1, -1, 1},
		{1, -1, 1, 1},
		{1, -1, -1, 1}
	};
	face6.vertices = {
		{-1, 1, 1, 1},
		{-1, 1, -1, 1},
		{-1, -1, 1, 1},
		{-1, -1, -1, 1}
	};
	cube.faces[0] = face1;
	cube.faces[1] = face2;
	cube.faces[2] = face3;
	cube.faces[3] = face4;
	cube.faces[4] = face5;
	cube.faces[5] = face6;
	return cube;
}

Polygon newPolygon (Point *points[])
{
	Polygon polygon;

	polygon = { *points };
	return polygon;
}
*/
Point newPoint (float x, float y, float z, float w)
{
	Point point;

	point[0][0] = x;
	point[1][0] = y;
	point[2][0] = z;
	point[3][0] = w;
	return point;
}

