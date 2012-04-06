#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <string>

#define NOISE_CHARACTER  '#'

#define MAX(x, y)   ((x > y) ? x : y )
#define MIN(x, y)   ((x < y) ? x : y )

namespace Direction {
    typedef enum {
        NORTH,
        SOUTH,
        EAST,
        WEST,
        NW,
        NE,
        SW,
        SE
    } Type;
}

struct Rect {
    int x;
    int y;
    int w;
    int h;
};

class Point {
    public:
    bool operator==(Point const& other);
    int x;
    int y;
};

enum Color {
    COL_WHITE = 0,
    COL_RED = 1,
    COL_GREEN = 2,
    COL_YELLOW = 3,
    COL_BLUE = 4,
    COL_PURPLE = 5,
    COL_CYAN = 6
};

void ScreenNoise(void);
bool IsOnScreen(Point p);
void Alert(std::string str);
bool BinaryChoice(std::string str, char a, char b);

#endif
