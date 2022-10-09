#include <SDL2/SDL.h>

void bresenham_line(int x1, int y1, int x2, int y2, SDL_Renderer *renderer) {
	int xStart, yStart, xEnd, yEnd;
	int sign, dx, dy;

	xStart = x1, yStart = y1, xEnd = x2, yEnd = y2;

	if (x1 > x2) {
		xStart = x2;
		yStart = y2;
		xEnd = x1;
		yEnd = y1;
	}
	sign = yEnd - yStart < 0 ? -1 : 1;

	dx = xEnd - xStart;
	dy = sign * (yEnd - yStart);

	if (dx > dy) {
		int d = 2 * dy - dx;
		int dE = 2 * dy;
		int dNE = 2 * (dy - dx);

		int i = xStart, j = yStart;
		SDL_RenderDrawPoint(renderer, i, j); 	

		while (i != xEnd) {
			if (d <= 0) {
				d += dE;
			} else {
				d += dNE;
				j += sign;
			}
			i++;
			SDL_RenderDrawPoint(renderer, i, j);
		}
	} else {
		int d = dy - 2 * dx;
		int dN = 2 * (-dx);
		int dNE = 2 * (dy - dx);

		int i = yStart, j = xStart;
		SDL_RenderDrawPoint(renderer, i, j);

		while (i != yEnd) {
			if (d > 0) {
				d += dN;
			} else {
				d += dNE;
				j++;
			}
			i += sign;
			SDL_RenderDrawPoint(renderer, i, j);
		}
	}
}

