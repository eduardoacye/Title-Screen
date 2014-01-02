#include "Game.hpp"

Game::Game()
    : window(sf::VideoMode(sizeX, sizeY), "Disparele", sf::Style::Fullscreen, sf::ContextSettings(16,0,8,0,0))
{
    window.setMouseCursorVisible(false);
    window.setVerticalSyncEnabled(true);
    srand(time(NULL));
    currentState = fsm::TitleScreen;

    states = new State*[4];
    states[fsm::TitleScreen] = new TitleScreen(fsm::TitleScreen, "Title Screen");
    states[fsm::Instructions] = new InstructionsScreen(fsm::Instructions, "Instructions");
    states[fsm::GameLoop] = new GameScreen(fsm::GameLoop, "Gameplay Screen");
    states[fsm::GameOver] = new GameOverScreen(fsm::GameOver, "Game Over Screen");
}
Game::~Game()
{
    delete[] states;
}

void Game::run()
{
    sf::Clock deltaClock;
    sf::Time dt;
    fsm::Q newState;
    state = states[currentState];
    while(window.isOpen()){
        dt = deltaClock.restart();
        processEvents();
        state->update(dt);
        state->render(window);
        newState = state->goTo();
        state->goToState = state->type;
        if(newState != state->type){
            if(newState == fsm::Empty)
                window.close();
            if(newState == fsm::GameOver){
                dynamic_cast<GameScreen*>(states[fsm::GameLoop])->clear();
            }
            state = states[newState];
            currentState = newState;
        }
    }
}

void Game::processEvents()
{
    sf::Event event;

    while(window.pollEvent(event)){
        switch(event.type){
        case sf::Event::Closed:
            window.close();
            break;
        default:
            break;
        }
        state->processEvent(event);
    }
}
