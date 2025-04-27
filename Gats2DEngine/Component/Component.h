#pragma once

class GameObject;
class Transform2D;

enum class ComponentType : uint8
{
	Transform2D,
	SpriteRenderer,
	Animator,
	Camera,
	ScriptComponent,
	// ...
	End
};

enum
{
	FIXED_COMPONENT_COUNT = static_cast<uint8>(ComponentType::End),
};


class Component
{
public:
	Component(ComponentType type);
	~Component();

	virtual void Awake(); // When the object is created/ loaded
	virtual void Start(); // On first frame after Awake
	virtual void Update(); // every frame
	virtual void FixedUpdate(); // every fixed timestep
	virtual void LateUpdate(); // every frame after Updat
	virtual void Render(); // for rendering
	virtual void OnDestroy(); // When the object is destroyed

	ComponentType GetType() { return mType; }

	std::shared_ptr<GameObject> GetGameObject();
	std::shared_ptr<Transform2D> GetTransform2D();

private:
	friend class GameObject;
	void SetGameObject(std::shared_ptr<GameObject> gameObject) { mGameObject = gameObject; }

private:
	ComponentType mType;
	std::weak_ptr<GameObject> mGameObject;
};

