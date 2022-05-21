#include "tApplication.h"
#include "functions.h"

tApplication::tApplication() : Window(nullptr) {}

tApplication::~tApplication() {
    delete Window;
    delete Map;
    delete Object;
    for (auto &el : Danger)
        delete el;
    for (auto &el : Lives)
        delete el;
    delete Boom;
    delete End;
}

void tApplication::Init() { // Инициализация объектов
    Window = new sf::RenderWindow(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "MyGame");
    Window->setFramerateLimit(60);
    Map = new tMap();
    Object = new tObject(0, SCREEN_HEIGHT/2 + OBJECT_SIZE/2, OBJECT_SIZE, OBJECT_SIZE);
    Boom = new tBoom(OBJECT_SIZE * 1.5, OBJECT_SIZE * 1.5);
    End = new tEnd();
    for (int i = 0; i < DANGER_COUNT; i++)
        Danger.emplace_back(new tDanger(rand_uns(0, 4)));
    for (int i = 0; i < 3; i++)
        Lives.emplace_back(new tLives(OBJECT_SIZE/2 * Lives.size(), 0, OBJECT_SIZE/2, OBJECT_SIZE/2));
    auto _init = std::chrono::system_clock::now();
}

void tApplication::Run() {
    Window->display();
    bool left_pr = false;
    bool right_pr = false;
    bool up_pr = false;
    bool down_pr = false;
    bool IsBoom = false;
    bool IsDead = false;
    auto prev_collision = std::chrono::system_clock::now() - std::chrono::seconds(2);
    auto speed_timer = std::chrono::system_clock::now();
    float _speed = BASE_SPEED;
    while (Window->isOpen()) {
        sf::Event event;
        // Обработка событий
        if (std::chrono::system_clock::now() - speed_timer >= std::chrono::milliseconds (100)) {
            _speed += D_X;
            speed_timer = std::chrono::system_clock::now();
        }
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
        if (std::chrono::system_clock::now() - prev_collision >= std::chrono::seconds(1) && !IsDead) {
            for (auto &el: Danger) {
                if (el->IsOut()) {
                    el->Run(_speed);
                }
            }

            if (left_pr)
                Object->Move(-_speed, 0);
            if (right_pr)
                Object->Move(_speed, 0);
            if (up_pr)
                Object->Move(0, -_speed);
            if (down_pr)
                Object->Move(0, _speed);
            for (auto &el: Danger) {
                el->Move();
                if (el->IsCollisison(Object->get_X(), Object->get_Y(), Object->get_Width(), Object->get_Height()) &&
                    std::chrono::system_clock::now() - prev_collision >= std::chrono::seconds(2))
                    IsBoom = true;
            }

            // Очистка экрана и отрисовка всех объектов

            Window->clear();
            Map->Draw(Window);
            Object->Draw(Window);

            for (auto &el: Danger)
                el->Draw(Window);

            if (IsBoom) {
                _speed = BASE_SPEED;
                IsBoom = false;
                prev_collision = std::chrono::system_clock::now();
                Boom->set_Position(Object->get_X() + Object->get_Width() / 2,
                                   Object->get_Y() + Object->get_Height() / 2);
                Object->set_Position(OBJECT_SIZE / 2, SCREEN_HEIGHT / 2);
                Lives.pop_back();
                if (Lives.empty())
                    IsDead = true;
            }

            for (auto &el: Lives)
                el->Draw(Window);

            if (std::chrono::system_clock::now() - prev_collision <= std::chrono::seconds(1))
                Boom->Draw(Window);
            if (IsDead)
                End->Draw(Window);
            Window->display();
        }
    }
}


