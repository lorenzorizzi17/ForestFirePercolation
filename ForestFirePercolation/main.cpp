#include"forest.hpp"
#include<vector>
#include<algorithm>
#include<SFML/Graphics.hpp>


int main() {
    //setting random seed
    srand((unsigned)time(NULL));

    //graphic constants and parameters
    const int N = 100 * 100;     //n. of cells (perfect square)
    const int n = std::sqrt(N);
    double p = 0.6;
    unsigned const display_height = 0.9 * sf::VideoMode::getDesktopMode().height; //=768
    int const fps = 60;
    double const R = 3.5;


    //Creating the forest
    Forest forest = Forest(n);
    forest.fillRandom(p);
    forest.setFire();

    //graphic sfml
    sf::RenderWindow window(sf::VideoMode(display_height, display_height), "Forest fire percolation", sf::Style::Default);
    window.setFramerateLimit(fps);
    //graphic loop
    while (window.isOpen())
    {
        //handling the events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Space) {
                    forest.sweep();
                    std::cerr << "Sweeped\n";
                    std::cerr << forest.fireStatus();
                }
            }

            //evolution

            window.clear(sf::Color::White);
            //drawing the forest
            for (int i = 0; i < N; i++)
            {
                sf::CircleShape unity(R);
                double L = display_height / (n);
                int column = i % n;
                int row = (i - column) / n;
                unity.setOrigin(R / 2, R / 2);
                unity.setPosition(0.0125 * display_height + (0.5 + column) * L, 0.0125 * display_height + L * (row + 0.5));
                if (forest.get(row, column) == 1) {
                    unity.setFillColor(sf::Color::Green);
                }
                else if (forest.get(row, column) == 0) {
                    unity.setFillColor(sf::Color::White);
                }
                else if ((forest.get(row, column) == 2)) {
                    unity.setFillColor(sf::Color::Red);
                }
                else {
                    unity.setFillColor(sf::Color::Black);
                }
                window.draw(unity);
            }


            window.display();
        }

    }
}