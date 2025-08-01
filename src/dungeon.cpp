#include "dungeon.h"
#include <cstdlib>
#include <iostream>
#include <ncurses.h>
#include <fstream>

namespace Rogue {

    Dungeon::Dungeon() : _grid(), _player({10,10}, _grid._tileMap)  {

        std::ifstream F("src/dungeon.txt");
        if (!F.is_open()) {
            std::cout << "err" << std::endl;
            return;
        }

        char ch;
        int y = 0;
        int x = 0;

        while (F.get(ch)) {
            if (std::isdigit(static_cast<unsigned char>(ch))) {
                _grid._tileMap[y][x] = ch - '0';
                x++;
            } else if (ch == '\n') {
                y++;
                x = 0;
            }
        }
    }

    void Dungeon::handleEvent(int ch) {

        _player.handleEvent(ch);
    }
    

    void Dungeon::update() {

        for (int y = 0; y < 50; y++) {
            for (int x = 0; x < 50; x++) {
                std::string c;
                if (_grid._tileMap[y][x] == 2) {
                    mvwaddstr(stdscr, y*3 - _worldOffset.second, x*6 - _worldOffset.first, "======");
                mvwaddstr(stdscr, y*3 + 1 - _worldOffset.second, x*6 - _worldOffset.first, "======");
                    mvwaddstr(stdscr, y*3 + 2 - _worldOffset.second, x*6 - _worldOffset.first, "======");
                }
                else if (_grid._tileMap[y][x] == 1) {
                    mvwaddstr(stdscr, y*3 - _worldOffset.second, x*6 - _worldOffset.first, "',,.',");
                    mvwaddstr(stdscr, y*3 + 1 - _worldOffset.second, x*6 - _worldOffset.first, ".','.'");
                    mvwaddstr(stdscr, y*3 + 2 - _worldOffset.second, x*6 - _worldOffset.first, ".,',.'");
                } else {
                    {
                    mvwaddstr(stdscr, y*3 - _worldOffset.second, x*6 - _worldOffset.first, "      ");
                    mvwaddstr(stdscr, y*3 + 1 - _worldOffset.second, x*6 - _worldOffset.first, "      ");
                    mvwaddstr(stdscr, y*3 + 2 - _worldOffset.second, x*6 - _worldOffset.first, "      ");
                }
                }
                
            }
        }

        _player.update();
    }
}