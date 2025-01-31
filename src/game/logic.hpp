#ifndef LOGIC_HPP
#define LOGIC_HPP

#include <cstdint>

namespace Snake {

#define SNAKE_MINIMUM_BODY_SIZE 4

typedef enum : int8_t {
    DIRECTION_UP = 1,
    DIRECTION_DOWN = ~1,
    DIRECTION_LEFT = 2,
    DIRECTION_RIGHT = ~2,
    DIRECTION_NONE = 0,
    EXIT = 3,
} Direction;

typedef enum {
    GAME_UNFINISHED,
    GAME_WON,
    GAME_LOST
} GameResult;

typedef enum {
    DIFFICULTY_EASY = 1,
    DIFFICULTY_NORMAL = 5,
    DIFFICULTY_HARD = 8, // additional snake body length tied to difficulty
} GameDifficulty;

struct GameTable {
    uint16_t height;
    uint16_t width;
};

struct Coordinates {
    uint16_t x;
    uint16_t y;
};

struct LevelInfo {
    uint32_t high_score;
    uint32_t level;
    GameDifficulty difficulty;
    LevelInfo(uint32_t s = 0, uint32_t l = 0, GameDifficulty d = DIFFICULTY_EASY)
        : high_score(s), level(l), difficulty(d) {
    }
};

GameTable get_playable_dimensions(GameDifficulty difficulty);
bool coordinates_are_equal(Coordinates a, Coordinates b);

} // namespace Snake

#endif