#pragma once

#pragma once

enum class KEY_TYPE : int32_t
{
    UP = sf::Keyboard::Key::Up,
    DOWN = sf::Keyboard::Key::Down,
    LEFT = sf::Keyboard::Key::Left,
    RIGHT = sf::Keyboard::Key::Right,

    SHIFT = sf::Keyboard::Key::LShift,
    ESC = sf::Keyboard::Key::Escape,

    W = sf::Keyboard::Key::W,
    A = sf::Keyboard::Key::A,
    S = sf::Keyboard::Key::S,
    D = sf::Keyboard::Key::D,

    Q = sf::Keyboard::Key::Q,
    E = sf::Keyboard::Key::E,
    Z = sf::Keyboard::Key::Z,
    C = sf::Keyboard::Key::C,
    X = sf::Keyboard::Key::X,
    V = sf::Keyboard::Key::V,

    KEY_1 = sf::Keyboard::Key::Num1,
    KEY_2 = sf::Keyboard::Key::Num2,
    KEY_3 = sf::Keyboard::Key::Num3,
    KEY_4 = sf::Keyboard::Key::Num4,

    // Map mouse separately
    LBUTTON = 1000,
    RBUTTON = 1001,
};

enum class KEY_STATE
{
    NONE,
    DOWN,
    UP,
    PRESS,
    END
};

enum
{
    KEY_TYPE_COUNT = sf::Keyboard::KeyCount,
    KEY_STATE_COUNT = static_cast<int32_t>(KEY_STATE::END),
};

class InputManager
{
    DECLARE_SINGLE(InputManager)
public:
    void Initialize();
    void Update();

    bool IsKeyPressed(KEY_TYPE key);
    KEY_STATE GetKeyState(KEY_TYPE key);

    sf::Vector2i GetMousePos() const;
    sf::Vector2i GetMouseDelta() const;

private:
    std::vector<KEY_STATE> mKeyStates;

    sf::Vector2i mMousePos = {};
    sf::Vector2i mPrevMousePos = {};
    sf::Vector2i mMouseDelta = {};

};
