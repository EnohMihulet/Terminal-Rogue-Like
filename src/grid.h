#include <SFML/Window/Keyboard.hpp>
#include <cstddef>
#include <utility>
#include <vector>

namespace Rogue {

    namespace GridHelper {
        
        const std::pair<int, int> tileMapToScreenCoors(const std::pair<int, int> pos);
        const std::pair<int, int> screenToTileMapCoors(const std::pair<int, int> pos);
    }

    class Grid {
    public:
        Grid();

        const int WIDTH = 50;
        const int HEIGHT = 50;
        const int TILEHEIGHT = 3;
        const int TILEWIDTH = 6;
        const std::pair<int, int> _center = {{WIDTH / 2}, {HEIGHT / 2}};
        std::vector<std::vector<int>> _tileMap{(size_t) HEIGHT, std::vector<int>((size_t) WIDTH, 0)};

    private:
    };

    enum Tile {
        Empty, Floor, Wall, Door,
    };
}