#include "grid.h"
#include <cstdlib>
#include <ncurses.h>

namespace Rogue {

    Grid::Grid() {
        return;
    }

    const std::pair<int, int> GridHelper::tileMapToScreenCoors(const std::pair<int, int> pos) {
        return {pos.first * 6, pos.second * 3};
    }

    const std::pair<int, int> GridHelper::screenToTileMapCoors(const std::pair<int, int> pos) {
        return {{pos.first / 6}, {pos.second / 3}};
    }
}