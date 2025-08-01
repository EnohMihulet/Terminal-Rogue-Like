#include "grid.h"
#include <utility>
#include <vector>


namespace Rogue {

    class Player {
    public:
        Player(const std::pair<int, int> _startPos, const std::vector<std::vector<int>>& _tileMapRef);

        void handleEvent(int ch);
        void update();

    private:
        std::pair<int, int> _pos;
        const std::vector<std::vector<int>>& _tileMapRef;


        void handleInput(const int ch);
        void checkCollision();
    };
}
