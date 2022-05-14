#include "tApplication.h"
#include "functions.h"

tApplication::tApplication() : Window(nullptr) {}

tApplication::~tApplication() {
    delete Window;
    delete Map;
    delete Object;
    for (auto &el : Danger)
        delete el;
}

void tApplication::Init() { // Инициализация объектов
    Window = new sf::RenderWindow(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "MyGame");
    Map = new tMap(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    Object = new tObject(0, SCREEN_HEIGHT/2 + OBJECT_SIZE/2, OBJECT_SIZE, OBJECT_SIZE);
    Window->setFramerateLimit(60);
    for (int i = 0; i < DANGER_COUNT; i++)
        Danger.emplace_back(new tDanger(rand_uns(0, 4)));
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

        for (auto &el : Danger) {
            if (el->IsOut()) {
                el->Run();
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
        for (auto &el : Danger)
            el->Move();
        // Очистка экрана и отрисовка всех объектов


        Window->clear();
        Map->Draw(Window);
        Object->Draw(Window);
        for (auto &el : Danger)
            el->Draw(Window);
        Window->display();
    }

}


