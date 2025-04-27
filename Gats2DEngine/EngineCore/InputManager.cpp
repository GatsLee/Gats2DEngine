#include "Headers/pch.h"
#include "InputManager.h"

void InputManager::Initialize()
{
	mKeyStates.resize(KEY_TYPE_COUNT, KEY_STATE::NONE);
}

void InputManager::Update()
{
	// Save previous mouse position
	mPrevMousePos = mMousePos;

	// Get current mouse position
	sf::Vector2i pos = sf::Mouse::getPosition(*WINDOW); // global
	mMousePos = { pos.x, pos.y };
	mMouseDelta = { mMousePos.x - mPrevMousePos.x, mMousePos.y - mPrevMousePos.y };

	// Update all keys
	for (int i = 0; i < KEY_TYPE_COUNT; i++)
	{
		sf::Keyboard::Key sfKey = static_cast<sf::Keyboard::Key>(i);

		bool isPressed = sf::Keyboard::isKeyPressed(sfKey);
		KEY_STATE& state = mKeyStates[i];

		switch (state)
		{
		case KEY_STATE::NONE:
			if (isPressed) state = KEY_STATE::DOWN;
			break;
		case KEY_STATE::DOWN:
			state = isPressed ? KEY_STATE::PRESS : KEY_STATE::UP;
			break;
		case KEY_STATE::PRESS:
			if (!isPressed) state = KEY_STATE::UP;
			break;
		case KEY_STATE::UP:
			state = KEY_STATE::NONE;
			break;
		}
	}
}

bool InputManager::IsKeyPressed(KEY_TYPE key)
{
	return mKeyStates[static_cast<int32_t>(key)] == KEY_STATE::PRESS;
}

KEY_STATE InputManager::GetKeyState(KEY_TYPE key)
{
	return mKeyStates[static_cast<int32_t>(key)];
}

sf::Vector2i InputManager::GetMousePos() const
{
	return mMousePos;
}

sf::Vector2i InputManager::GetMouseDelta() const
{
	return mMouseDelta;
}
