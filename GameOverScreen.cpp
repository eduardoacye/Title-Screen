#include "GameOverScreen.hpp"
#include "Master.hpp"


GameOverScreen::GameOverScreen(fsm::Q type_ = fsm::GameOver, std::string description_ = "Game Over Screen")
    : State(type_, description_)
{
    goToState = type;
    font.loadFromFile("res/sansation.ttf");

    title.setFont(font);
    title.setCharacterSize(40);
    title.setColor(sf::Color::White);
    title.setString("Game Over");
    sf::FloatRect textRect = title.getLocalBounds();
    title.setOrigin(textRect.left + textRect.width/2.0f,
                   textRect.top  + textRect.height/2.0f);
    title.setPosition(sf::Vector2f(sizeX/2.f, sizeY/10.f));

    back.setFont(font);
    back.setCharacterSize(30);
    back.setColor(sf::Color::White);
    back.setString("Back to title");
    textRect = back.getLocalBounds();
    back.setOrigin(textRect.left + textRect.width/2.0f,
                   textRect.top  + textRect.height/2.0f);
    back.setPosition(sf::Vector2f(sizeX/2.f, sizeY/2.f + 150 + 20));

    instructions.setFont(font);
    instructions.setCharacterSize(30);
    instructions.setColor(sf::Color::White);
    instructions.setString(std::string("Eres un perdedor ... un mequetrefe sin remedio,\n")+
                           std::string("te exhorto a que te des piola.\n\n")+
                           std::string("\n\n\tScore: ") + to_string(record));
    textRect = instructions.getLocalBounds();
    instructions.setOrigin(textRect.left + textRect.width/2.0f,
                   textRect.top  + textRect.height/2.0f);
    instructions.setPosition(sf::Vector2f(sizeX/2.f, sizeY/2.f));

    background.setFillColor(sf::Color(100,0,0));
    background.setPosition(0,0);
    background.setSize(sf::Vector2f(sizeX, sizeY));

    selection.setFillColor(sf::Color(255,255,255,100));
    selection.setOrigin(back.getOrigin());
    selection.setPosition(back.getPosition().x - 10, back.getPosition().y);
    selection.setSize(sf::Vector2f(back.getLocalBounds().width + 20,40));
}
void GameOverScreen::itemSelected()
{
    goToState = fsm::TitleScreen;
}

void GameOverScreen::processEvent(sf::Event &event)
{
    switch(event.type){
    case sf::Event::KeyPressed:
        if(event.KeyPressed){
            switch(event.key.code){
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

void GameOverScreen::update(sf::Time dt)
{
    int x = sin(masterClock.getElapsedTime().asSeconds()*5) * 40 + 40;
    instructions.setString(std::string("Eres un perdedor ... un mequetrefe sin remedio,\n")+
                           std::string("te exhorto a que te des piola.\n\n")+
                           std::string("\n\n\tScore: ") + to_string(record));
    selection.setFillColor(sf::Color(255,255,255,x));

    background.setFillColor(sf::Color(sin(masterClock.getElapsedTime().asSeconds()/2.f+2) * 10 + 20,
                                     sin(masterClock.getElapsedTime().asSeconds()/2.f+70) * 70 + 70,
                                     sin(masterClock.getElapsedTime().asSeconds()/2.f+123) * 20 + 50));
}

void GameOverScreen::render(sf::RenderWindow & window)
{
    window.clear();
    window.draw(background);
    window.draw(title);
    window.draw(instructions);
    window.draw(back);
    window.draw(selection);
    window.display();
}
fsm::Q GameOverScreen::goTo() const
{
    return goToState;
}
