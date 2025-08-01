#include <SFML/Window/Keyboard.hpp>
#include "player.h"
#include <cstddef>
#include <utility>
#include <vector>

namespace Rogue {

    class Dungeon {
    public:
        Dungeon();

        void handleEvent(const int ch);
        void update();
    
    private:
        Grid _grid;
        Player _player;
        int _maxY;
        int _maxX;
        std::pair<int, int> _pWorldPos;
        std::pair<int, int> _worldOffset = {0, 0};
    };
}


