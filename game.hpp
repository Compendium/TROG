#ifndef GAME_H
#define GAME_H

#include "level.hpp"
#include "character.hpp"
#include "geometry.hpp"
#include "enemy.hpp"
#include <string>

class Level;

namespace GameMode {
    typedef enum {
        MAP_WALK,
        MAP_LOOK,
        INFO_SCREEN,
        CHARACTER_SCREEN,
        INVENTORY_SCREEN,
    } Type;
}

class Game {
    public:
    Game(Character *c);
    ~Game(void);
    bool Run(void);
    void HandleInput(int c);
    void GoUpALevel(void);
    void GoDownALevel(void);
    void SwitchGameMode(GameMode::Type gmt);
    void MoveCamera(Direction::Type d);
    void DoRedraw(void);
    void MoveCharacter(Direction::Type d);
    void CharacterStatusLine(void);
    void DrawLookTarget(void);
    void MoveLookTarget(Direction::Type d);
    void DrawAsOverlay(Point p, char c, int col);
    void DoPickup(void);
    void ShowCharacterScreen(void);
    void ShowInventoryScreen(void);
    void ShowInfoScreen(void);
    void HandleResize(int signal);
    void QuitDialogue(void);
    void DoAttack(Character *c, Enemy *e);
    void DoWait(void);

    int                 gold;
    Level*              levels;
    Level*              cur_level;
    Character*          character;
    int                 cur_floor;
    bool                running;
    GameMode::Type      game_mode;
    Point               target; //For examining things
};

#endif
