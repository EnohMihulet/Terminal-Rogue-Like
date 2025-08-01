#include <ncurses.h>
#include "dungeon.h"

int main() {
    initscr();
    raw();
    noecho();
    // auto grid = Rogue::Grid();
    int ch;
    auto world = Rogue::Dungeon();

    while ((ch = getch()) != 'q') {
        clear();
        world.handleEvent(ch);
        world.update();
        refresh();
    } 

    endwin();

    return 0;
}
