#ifndef GAME_UI_HPP
#define GAME_UI_HPP

#include "game/game.hpp"

#ifdef _WIN32
#include <ncurses/ncurses.h>
#else
#include <ncurses.h>
#endif

namespace Graphics {

class GameUI {
  private:
    WINDOW *window;
    Snake::Game *game;

  public:
    GameUI(Snake::Game *game);
    ~GameUI();

    void update_game_window(int32_t remaining_time);
    void close_window();
    WINDOW *getWindow();
    void render_score(uint32_t score);
};
} // namespace Graphics

#endif