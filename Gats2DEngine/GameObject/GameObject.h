#pragma once
#include "Component/Component.h"
#include "Component/ScriptComponent.h"

class Animator;
class Camera;
class ScriptComponent;
class SpriteRenderer;
class Transform2D;
class Script;

class GameObject : public std::enable_shared_from_this<GameObject>
{
public:
	GameObject() {}
	GameObject(std::wstring name) : mName(name) {}
	~GameObject() {}

	virtual void Awake();
	virtual void Start();
	virtual void Update();
	virtual void FixedUpdate();
	virtual void LateUpdate();
	virtual void Render();

	std::shared_ptr<Component> GetFixedComponent(ComponentType type);
	std::shared_ptr<Transform2D> GetTransform2D();
	std::shared_ptr<SpriteRenderer> GetSpriteRenderer();
	std::shared_ptr<Animator> GetAnimator();
	std::shared_ptr<Camera> GetCamera();
	std::shared_ptr<ScriptComponent> GetScriptComponent();
	std::shared_ptr<GameObject> GetGameObject() { return shared_from_this(); }

	std::wstring GetName() { return mName; }
	void SetName(std::wstring name) { mName = name; }

	std::shared_ptr<Transform2D> GetOrAddTransform2D();
	void AddComponent(std::shared_ptr<Component> component);

	template<typename T>
	std::shared_ptr<T> AddScript(std::string scriptName)
	{
		static_assert(std::is_base_of<Script, T>::value, "T must inherit from Script");

		auto scriptComponent = GetScriptComponent();
		if (!scriptComponent)
		{
			scriptComponent = std::make_shared<ScriptComponent>();
			AddComponent(scriptComponent);
		}
		return scriptComponent->AddScript<T>(scriptName);
	}

protected:
	std::wstring mName = L"DefaultGameObject";
	std::array<std::shared_ptr<Component>, FIXED_COMPONENT_COUNT> mComponents;
	std::vector <std::shared_ptr<ScriptComponent>> mScripts;

};

