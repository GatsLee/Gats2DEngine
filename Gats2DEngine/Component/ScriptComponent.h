#pragma once
#include "Component.h"

class Script
{
public:
	Script() : mName("DefaultScript") {}
	Script(std::string name) : mName(name) {}
	virtual ~Script() {}

	virtual void Awake() {}
	virtual void Start() {}
	virtual void Update() {}
	virtual void FixedUpdate() {}
	virtual void LateUpdate() {}
	virtual void OnDestroy() {}


	std::string	GetName() const { return mName; }
	void SetName(std::string name) { mName = name; }

	void SetOwner(std::shared_ptr<GameObject> owner) { mOwner = owner; }
	std::shared_ptr<GameObject> GetOwner()
	{
		if (mOwner.expired())
			return nullptr;
		return mOwner.lock();
	}

protected:
	std::string mName;
	std::weak_ptr<GameObject> mOwner;
};

class ScriptComponent : public Component
{

public:
	ScriptComponent();
	~ScriptComponent();

	virtual void Start() override;
	virtual void Awake() override;
	virtual void Update() override;
	virtual void FixedUpdate() override;
	virtual void LateUpdate() override;
	virtual void OnDestroy() override;

	template<typename T>
	std::shared_ptr<T> AddScript(std::string scriptName)
	{
		static_assert(std::is_base_of<Script, T>::value, "T must inherit from Script");
		auto script = std::make_shared<T>(scriptName);
		script->SetOwner(GetGameObject());
		mScripts.push_back(script);
		return script;
	}

	std::shared_ptr<Script> GetScript(std::string scriptName)
	{
		for (auto& script : mScripts)
		{
			if (script->GetName() == scriptName)
			{
				return script;
			}
		}
		return nullptr;
	}

	void RemoveScript(std::string scriptName)
	{
		auto iter = std::remove_if(mScripts.begin(), mScripts.end(),
			[scriptName](const std::shared_ptr<Script>& script) { return script->GetName() == scriptName; });
		mScripts.erase(iter, mScripts.end());
	}

protected:
	std::vector<std::shared_ptr<Script>> mScripts;
};

