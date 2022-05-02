#include "tApplication.h"

tApplication::tApplication() : Window(nullptr) {}

tApplication::~tApplication() {
    delete Window;
}

void tApplication::Init() { // Инициализация объектов
    Window = new sf::RenderWindow(sf::VideoMode(1500, 1500), "MyGame");
    Map = new tMap(0, 0, 1500, 1500);
    Object = new tObject(0, 675, 150, 150);
    Window->setFramerateLimit(60);
}

void tApplication::Run() {
    Window->display();
    bool left_pr = false;
    bool right_pr = false;
    bool up_pr = false;
    bool down_pr = false;
    while (Window->isOpen()) {
        sf::Event event;
        // Обработка событий
        while (Window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                Window->close();
            else {
                // Выход по Esc
                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                    Window->close();
                // Определеяем необходимость перемещения объекта при нажатых клавишах
                right_pr = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
                left_pr = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
                up_pr = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
                down_pr = sf::Keyboard::isKeyPressed(sf::Keyboard::Down);
            }
        }

        if (left_pr)
            Object->Move(-5, 0);
        if (right_pr)
            Object->Move(5, 0);
        if (up_pr)
            Object->Move(0, -5);
        if (down_pr)
            Object->Move(0, 5);
        // Очистка экрана и отрисовка всех объектов
        Window->clear();
        Map->Draw(Window);
        Object->Draw(Window);
        Window->display();
    }

}


