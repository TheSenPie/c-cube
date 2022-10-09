main: main.c scan_conversion.c
	cc -std=c89 -Wextra -pedantic-errors -o main main.c scan_conversion.o -lSDL2
scan_conversion.o: scan_conversion.c
	cc -std=c89 -Wextra -pedantic-errors scan_conversion.c -c -lSDL2
