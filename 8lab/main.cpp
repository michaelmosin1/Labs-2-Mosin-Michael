#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include "SFML/Audio.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    sf::Font font;
    sf::Music music;
    music.openFromFile("music.flac");
    music.setLoop(true);
    music.setVolume(50);
    music.play();
    font.loadFromFile("NotoSans-Medium.ttf");
    sf::Text text("\n\n\n\n\n\t\t\tHello world!", font);
    text.setCharacterSize(14);
    text.setStyle(sf::Text::Bold);
    shape.setFillColor(sf::Color::Red);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.draw(text);
        window.display();
    }

    return 0;
}
