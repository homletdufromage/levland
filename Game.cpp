#include "Game.hpp"

Game::Game(): mWindow(sf::VideoMode(640, 480), "Lev Land"), mPlayer() {
    mPlayer.setRadius(15);
    mPlayer.setPosition(100, 100);
    mPlayer.setFillColor(sf::Color::White);
}

void Game::run() {
    mWindow.setVerticalSyncEnabled(true);
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    while(mWindow.isOpen()) {
        timeSinceLastUpdate += clock.restart();

        // let's process the events every step of TIME_PER_FRAME seconds
        while(timeSinceLastUpdate > TIME_PER_FRAME) {
            timeSinceLastUpdate -= TIME_PER_FRAME;
            processEvents();
            update(TIME_PER_FRAME);
        }
        render();
    }
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed) {
    if (key == sf::Keyboard::Up)
        mIsMovingUp = isPressed;
    else if (key == sf::Keyboard::Down)
        mIsMovingDown = isPressed;
    else if (key == sf::Keyboard::Left)
        mIsMovingLeft = isPressed;
    else if (key == sf::Keyboard::Right)
        mIsMovingRight = isPressed;
}

void Game::processEvents() {
    sf::Event event;
    while (mWindow.pollEvent(event)) {
        switch(event.type) {
            case sf::Event::KeyPressed:
                handlePlayerInput(event.key.code, true);
                break;
            case sf::Event::KeyReleased:
                handlePlayerInput(event.key.code, false);
                break;
            case sf::Event::Closed:
                mWindow.close();
                break;
            default:
                break;
        }
    }
}

void Game::update(sf::Time delta) {
    sf::Vector2f movement(0, 0);
    if (mIsMovingUp)
        movement.y -= PlayerSpeed;
    if (mIsMovingDown)
        movement.y += PlayerSpeed;
    if (mIsMovingLeft)
        movement.x -= PlayerSpeed;
    if (mIsMovingRight)
        movement.x += PlayerSpeed;
    
    mPlayer.move(movement * delta.asSeconds());
}

void Game::render() {
    mWindow.clear();
    mWindow.draw(mPlayer);
    mWindow.display();
}