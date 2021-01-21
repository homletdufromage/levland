#include "SFML/Graphics.hpp"
class Game {
    public:
        Game();
        void run();

    private:
        void processEvents();
        void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);
        void update(sf::Time);
        void render();
    
    private:
        sf::RenderWindow mWindow;
        sf::CircleShape mPlayer;
        const float PlayerSpeed = 100;
        sf::Time TIME_PER_FRAME = sf::seconds(1.0 / 60.0);

        bool mIsMovingUp = false, mIsMovingDown = false, mIsMovingLeft = false, mIsMovingRight = false;
};