#pragma once

#include "Component.h"

class Camera : public Component
{
public:
	Camera();
	Camera(const sf::FloatRect& rect);
	Camera(sf::Vector2f center, sf::Vector2f size);
	~Camera();

public:
	//Getters
	sf::Vector2f GetCenter() const { return mCamera->getCenter(); }
	sf::Angle GetRotation() const { return mCamera->getRotation(); }
	sf::Vector2f GetSize() const { return mCamera->getSize(); }
	sf::FloatRect GetViewport() const { return mCamera->getViewport(); }
	std::shared_ptr<sf::View> GetCamera() const { return mCamera; }
	sf::View& GetNativeCamera() { return *mCamera; }

	void Move(float x = 0.f, float y = 0.f) { mCamera->move(sf::Vector2f({ x, y })); }
	void Rotate(float angle) { mCamera->rotate(sf::degrees(angle)); }
	void SetCenter(float x, float y) { mCamera->setCenter(sf::Vector2f(x, y)); }
	void SetViewport(const sf::FloatRect& rect) { mCamera->setViewport(rect); }
	void Zoom(float factor) { mCamera->zoom(factor); } // 1.0f = no zoom, 2.0f = zoom in, 0.5f = zoom out

private:
	std::shared_ptr<sf::View> mCamera;

	//flags
	bool mLoaded = false;
};

