#include "Headers/pch.h"
#include "Camera.h"

Camera::Camera()
	:Component(ComponentType::Camera)
{
	mCamera = std::make_shared<sf::View>();
}

Camera::Camera(const sf::FloatRect& rect)
	: Component(ComponentType::Camera)
{
	mCamera = std::make_shared<sf::View>();
	mCamera->setSize(sf::Vector2f(rect.size.x, rect.size.y));
}

Camera::Camera(sf::Vector2f center, sf::Vector2f size)
	: Component(ComponentType::Camera)
{
	mCamera = std::make_shared<sf::View>(center, size);
}

Camera::~Camera()
{
}
