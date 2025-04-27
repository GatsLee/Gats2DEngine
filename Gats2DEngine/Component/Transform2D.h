#pragma once
#include "Component.h"

class Transform2D : public Component, public std::enable_shared_from_this<Transform2D>
{
public:
    Transform2D();
    ~Transform2D() = default;

    // Local transform setters
    void SetLocalPosition(const sf::Vector2f& pos);
    void SetLocalRotation(float angle); // degrees
    void SetLocalScale(const sf::Vector2f& scale);

	// World transform setters
	void SetWorldPosition(const sf::Vector2f& pos);
	void SetWorldRotation(float angle); // degrees
	void SetWorldScale(const sf::Vector2f& scale);

    // Getters
    sf::Vector2f& GetLocalPosition();
    float& GetLocalRotation();
    sf::Vector2f& GetLocalScale();

    sf::Vector2f& GetWorldPosition();
    float& GetWorldRotation();
    sf::Vector2f& GetWorldScale();

    sf::Transform& GetWorldMatrix();

    // Hierarchy
    void SetParent(std::shared_ptr<Transform2D> parent);
    std::shared_ptr<Transform2D> GetParent();
    void AddChild(std::shared_ptr<Transform2D> child);
    std::vector<std::shared_ptr<Transform2D>>& GetChildren();

    // Direction vectors
    sf::Vector2f GetRight();   // local X axis
    sf::Vector2f GetUp();      // local Y axis

    void UpdateTransform();

private:
    sf::Vector2f mLocalPosition = { 0.f, 0.f };
    float mLocalRotation = 0.f;             // in degrees
    sf::Vector2f mLocalScale = { 1.f, 1.f };

	mutable sf::Vector2f mWorldPosition = { 0.f, 0.f };
	mutable float mWorldRotation = 0.f;     // in degrees
	mutable sf::Vector2f mWorldScale = { 1.f, 1.f };

    mutable sf::Transform mCachedWorldTransform;
    mutable bool mDirty = true;

    std::weak_ptr<Transform2D> mParent;
    std::vector<std::shared_ptr<Transform2D>> mChildren;
};