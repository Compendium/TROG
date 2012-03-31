#ifndef LEVEL_H
#define LEVEL_H

#include "tile.hpp"
#include "geometry.hpp"
#include "character.hpp"
#include "game.hpp"

#define MAP_W   100
#define MAP_H   50

typedef Rect Room;

class Game;

struct Corridor {
    Rect pos;
    Direction::Type direction;
};

class Level {
    public:
    Level(Level* parent);
    ~Level(void);
    void Draw(Game *g);
    void DrawObjectRelative(Point p, char c);
    bool IsOnScreen(Point p);
    bool TileIsVisible(Point p);
    void ConditionallyShowObject(Point p, char c);
    void RevealSight(Entity* e);
    void CentreCam(Point p);
    void DoSightBeam(Direction::Type d, int x, int y, float ttl);

    int     depth;
    Tile    tiles[MAP_W][MAP_H];
    Level*  prev;
    Level*  next;
    Point   stairs_up;
    Point   stairs_down;

    static Point        cam;
    static Character    *character;

    private:
    void ApplyRoom(Room *r);
    void ApplyCorridor(Corridor *c);
    bool CorridorFits(Corridor *c);
    bool RoomFits(Room *r);
    Corridor FindRoomCorridorChild(Room *r);
    Room RoomFromCorridor(Corridor *c);
};

#endif
