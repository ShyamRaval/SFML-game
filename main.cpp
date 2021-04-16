#include <vector>
#include <iostream>
using namespace std;

#include <SFML/Graphics.hpp>

//window size
const int w_height = 729;
const int w_width = 1300;

void render_board(sf::RectangleShape &rect, sf::RenderWindow &window)
{
    struct location_of_box
    {   int x;
        int y;
    };
    location_of_box position;
    position.x = 50;
    position.y = 50;
    rect.setPosition(position.x, position.y);
    
    for (int i=0;i < 3;i++)
    {
        position.x = position.x+130;
        rect.setPosition(position.x, position.y);
        for (int j=0; j < 3; j++)
        {
            position.y = position.y+130;
            rect.setPosition(position.x, position.y);
            window.draw(rect);
        }
        position.y = 50;
        window.draw(rect);
    }
}

int main()
{
    //define and initialize the game window named window
    sf::RenderWindow window(sf::VideoMode(w_width, w_height), "SFML works!", sf::Style::Close );
    window.setFramerateLimit(40);
    //defines the background 
    sf::RectangleShape background(sf::Vector2f(w_width, w_height));
    background.setFillColor(sf::Color::Blue);
    
    //defines the rectangle 
    sf::RectangleShape box(sf::Vector2f(100.0f, 100.0f));
    box.setPosition(300, 100);
    box.setFillColor(sf::Color::Red);
    box.setOutlineColor(sf::Color::Green);
    box.setOutlineThickness(10);
    
    //game loop
    while (window.isOpen())
    {
        window.draw(background);
        render_board(box, window);

        //define a game Event name event 
        sf::Event evnt;

        //check for any 
        while (window.pollEvent(evnt))
        {

            if (evnt.type == evnt.Closed)
            {
                window.close();
            }
        }

        //this if is only used to make a block of rendering part
        if (1)
        {
            window.display();
            window.clear();
        }
    }

    return 0;
}