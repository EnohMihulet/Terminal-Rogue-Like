#include "player.h" 
#include <ncurses.h>
#include <utility>

namespace Rogue {

    Player::Player(const std::pair<int,  int> _startPos, const std::vector<std::vector<int>>& tileMapRef) 
    : _tileMapRef{tileMapRef} {
        _pos = _startPos;
    }

    void Player::handleEvent(const int ch) {
        handleInput(ch);
    }

    void Player::update() {
        std::pair<int, int> screenPos = GridHelper::tileMapToScreenCoors(_pos);

        mvaddch(screenPos.second, screenPos.first, 'X');
        // mvaddch(_pos.second, _pos.first, 'X');
    }
    
    void Player::handleInput(const int ch) {

        int newY = _pos.second;
        int newX = _pos.first;

        switch (ch) {
        case 'w':
            newY -= 1; break;
        case 'a':
            newX -= 1; break;
        case 's':
            newY += 1; break;
        case 'd':
            newX += 1; break;
        default:
            break;
        }

        if (newY >= (int) _tileMapRef.size() || newX >= (int) _tileMapRef[0].size()) return;
        if (newY < 0 || newX < 0) return;
        if (_tileMapRef[newY][newX] != 1) return;

        _pos = {newX, newY};
    }
}