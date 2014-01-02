#include "GameScreen.hpp"
#include "Master.hpp"
#include <cmath>
#define MAX_LIVES 5

int score;
int record;

GameScreen::GameScreen(fsm::Q type_ = fsm::GameLoop, std::string description_ = "Game Screen")
    : State(type_, description_)
{
    goToState = type;
    font.loadFromFile("res/sansation.ttf");

    score = 0;
    lives = MAX_LIVES;
    delay = 0;

    scoreString.setFont(font);
    scoreString.setCharacterSize(40);
    scoreString.setPosition(10, sizeY-130);
    scoreString.setColor(sf::Color::White);
    scoreString.setString("Score: "+to_string(score));
    scoreBackground.setFillColor(sf::Color(0,0,0,100));
    scoreBackground.setPosition(5,sizeY-130);
    scoreBackground.setSize(sf::Vector2f(200, 50));

    livesString.setFont(font);
    livesString.setCharacterSize(40);
    livesString.setPosition(10, sizeY-60);
    livesString.setColor(sf::Color::White);
    livesString.setString("Lives: "+to_string(lives));
    livesBackground.setFillColor(sf::Color(0,0,0,100));
    livesBackground.setPosition(5,sizeY-60);
    livesBackground.setSize(sf::Vector2f(200, 50));

    music.openFromFile("res/song.ogg");
    music.setLoop(true);
    music.play();

    background.setPosition(0,0);
    background.setSize(sf::Vector2f(sizeX,sizeY));
    background.setFillColor(sf::Color(100,100,100));
    effect.setPosition(0,0);
    effect.setSize(sf::Vector2f(sizeX,sizeY));
    effect.setFillColor(sf::Color(rand()%256, rand()%256, rand()%256, 0));
    effectDecay = 0;

    mousePosition.x = 0;
    mousePosition.y = 0;
}
void GameScreen::itemSelected()
{
    goToState = fsm::TitleScreen;
}

void GameScreen::processEvent(sf::Event &event)
{
    switch(event.type){
    case sf::Event::MouseButtonPressed:
        shotSound.sound.play();
        succesfulHit = false;
        for(int i=0; i<enemies.size(); ++i){
            if(enemies[i].isClicked(mousePosition)){
                enemies[i].isDead = true;
                succesfulHit = true;
                effectDecay = 128;
            }
        }
        if (succesfulHit == false) --score;
        break;
    case sf::Event::KeyPressed:
        if(event.KeyPressed){
            switch(event.key.code){
            case sf::Keyboard::Escape:
                this->goToState = fsm::TitleScreen;
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

void GameScreen::update(sf::Time dt)
{
    float x = masterClock.getElapsedTime().asSeconds();
    crosshair.update(x);
    background.setFillColor(sf::Color(255*sin(x/9),255*sin(x/5),255*sin(x/9)));
    if(effectDecay > 0)
        effectDecay -= 10;
    else
        effectDecay = 0;
    effect.setFillColor(sf::Color(effect.getFillColor().r,
                              effect.getFillColor().g,
                              effect.getFillColor().b,
                              effectDecay));
    for(int i=0; i<enemies.size(); ++i){
        enemies[i].move(x);
        if(enemies[i].getPosition().y > sizeY){
            damageSound.hitSound.play();
            enemies.erase(enemies.begin()+i);
            --lives;
        }else if(enemies[i].isDead){
            hitSound.sound.play();
            enemies.erase(enemies.begin()+i);
            score++;
        }
    }
    if(rand()%1000 <= x-delay)
        enemies.push_back(Enemy());
    scoreString.setString("Score: "+to_string(score));
    livesString.setString("Lives: "+to_string(lives));
    if(lives <= 0)
        goToState = fsm::GameOver;
}

void GameScreen::render(sf::RenderWindow & window)
{
    mousePosition = sf::Mouse::getPosition(window);
    crosshair.sprite.setPosition(sf::Vector2f(sf::Mouse::getPosition(window)));
    window.clear(sf::Color::White);
    window.draw(background);
    for(int i=0; i<enemies.size(); ++i)
        window.draw(enemies[i]);
    window.draw(effect);
    window.draw(crosshair.sprite);
    window.draw(scoreBackground);
    window.draw(livesBackground);
    window.draw(scoreString);
    window.draw(livesString);
    window.display();
}
fsm::Q GameScreen::goTo() const
{
    return goToState;
}
void GameScreen::clear()
{
    delay = masterClock.getElapsedTime().asSeconds();
    enemies.clear();
    lives = MAX_LIVES;
    record = score;
    score = 0;
    scoreString.setString("Score: " + to_string(score));
    livesString.setString("Lives: " + to_string(lives));
}
