void bresenham_line(int x1, int y1, int x2, int y2, SDL_Renderer *renderer);

typedef float Point[][1];

typedef struct polygon {
	Point *vertices;
} Polygon;

typedef struct cube {
	Polygon faces[6];
} Cube;

