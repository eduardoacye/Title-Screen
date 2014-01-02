#include "TitleScreen.hpp"

TitleScreen::TitleScreen(fsm::Q type_ = fsm::TitleScreen, std::string description_ = "Title Screen")
    : State(type_, description_)
{
    goToState = type;
    font.loadFromFile("res/sansation.ttf");

    title.setFont(font);
    title.setCharacterSize(40);
    title.setColor(sf::Color::White);
    title.setString("Title Screen");
    sf::FloatRect textRect = title.getLocalBounds();
    title.setOrigin(textRect.left + textRect.width/2.0f,
                   textRect.top  + textRect.height/2.0f);
    title.setPosition(sf::Vector2f(sizeX/2.f, sizeY/2.f));

    startGame.setFont(font);
    startGame.setCharacterSize(30);
    startGame.setColor(sf::Color::White);
    startGame.setString("Start");
    textRect = startGame.getLocalBounds();
    startGame.setOrigin(textRect.left + textRect.width/2.0f,
                   textRect.top  + textRect.height/2.0f);
    startGame.setPosition(sf::Vector2f(sizeX/2.f, sizeY/2.f + 50 + 20));

    exitGame.setFont(font);
    exitGame.setCharacterSize(30);
    exitGame.setColor(sf::Color::White);
    exitGame.setString("Exit");
    textRect = exitGame.getLocalBounds();
    exitGame.setOrigin(textRect.left + textRect.width/2.0f,
                   textRect.top  + textRect.height/2.0f);
    exitGame.setPosition(sf::Vector2f(sizeX/2.f, sizeY/2.f + 150 + 20));

    instructions.setFont(font);
    instructions.setCharacterSize(30);
    instructions.setColor(sf::Color::White);
    instructions.setString("Instructions");
    textRect = instructions.getLocalBounds();
    instructions.setOrigin(textRect.left + textRect.width/2.0f,
                   textRect.top  + textRect.height/2.0f);
    instructions.setPosition(sf::Vector2f(sizeX/2.f, sizeY/2.f + 100 + 20));

    background.setFillColor(sf::Color(100,0,0));
    background.setPosition(0,0);
    background.setSize(sf::Vector2f(sizeX, sizeY));

    selection.setFillColor(sf::Color(255,255,255,100));
    selection.setOrigin(instructions.getOrigin());
    selection.setPosition(instructions.getPosition().x - 10, instructions.getPosition().y-50);
    selection.setSize(sf::Vector2f(textRect.width + 20,40));

    selectionId = 99;
}

void TitleScreen::itemSelected()
{
    switch(selectionId%3){
    case 0:
        goToState = fsm::GameLoop;
        break;
    case 1:
        goToState = fsm::Instructions;
        break;
    case 2:
        goToState = fsm::Empty;
        break;
    default:
        break;
    }
}

void TitleScreen::processEvent(sf::Event &event)
{
    switch(event.type){
    case sf::Event::KeyPressed:
        if(event.KeyPressed){
            switch(event.key.code){
            case sf::Keyboard::Down:
                selectionId++;
                break;
            case sf::Keyboard::Up:
                selectionId--;
                break;
            case sf::Keyboard::Return:
                itemSelected();
                break;
            default:
                break;
            }
        }
        break;
    default:
        break;
    }
}

void TitleScreen::update(sf::Time dt)
{
    int x = sin(masterClock.getElapsedTime().asSeconds()*5) * 40 + 40;
    selection.setFillColor(sf::Color(255,255,255,x));

    switch(selectionId%3){
    case 0:
        selection.setPosition(instructions.getPosition().x - 10, instructions.getPosition().y-50);
        break;
    case 1:
        selection.setPosition(instructions.getPosition().x - 10, instructions.getPosition().y);
        break;
    case 2:
        selection.setPosition(instructions.getPosition().x - 10, instructions.getPosition().y+50);
        break;
    }

    background.setFillColor(sf::Color(sin(masterClock.getElapsedTime().asSeconds()/2.f+2) * 10 + 20,
                                     sin(masterClock.getElapsedTime().asSeconds()/2.f+70) * 70 + 70,
                                     sin(masterClock.getElapsedTime().asSeconds()/2.f+123) * 20 + 50));
}

void TitleScreen::render(sf::RenderWindow & window)
{
    window.clear();
    window.draw(background);
    window.draw(title);
    window.draw(startGame);
    window.draw(instructions);
    window.draw(exitGame);
    window.draw(selection);
    window.display();
}
fsm::Q TitleScreen::goTo() const
{
    return goToState;
}
