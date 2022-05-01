#include "tApplication.h"

tApplication::tApplication() : Window(nullptr) {}

tApplication::~tApplication() {
    delete Window;
}

void tApplication::Init() { // Инициализация объектов
    Window = new sf::RenderWindow(sf::VideoMode(2000, 2000), "MyGame");
    Map = new tMap(0, 0, 2000, 2000);
    Window->setFramerateLimit(60);
}

void tApplication::Run() {
    Window->display();
    while (Window->isOpen()) {
        sf::Event event;
        // Обработка событий
        while (Window->pollEvent(event)) {
            switch (event.type) {

                case sf::Event::Closed:
                    Window->close();
                    break;

                // Нажатие клавишей
                case sf::Event::KeyPressed:
                    // А именно Esc
                    if (event.key.code == sf::Keyboard::Escape)
                        Window->close();
                    break;
                    
                default:
                    break;
            }

        }
        // Очистка экрана и отрисовка всех объектов
        Window->clear();
        Map->Draw(Window);
        Window->display();
    }

}


