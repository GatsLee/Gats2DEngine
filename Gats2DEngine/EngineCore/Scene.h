#pragma once

class GameObject;
class UIWidget;

class Scene
{
public:
	Scene(std::string sceneName);
	virtual ~Scene();
	// Initialize
	virtual void Initialize() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;
	// Scene ControlW
	virtual void OnEnter() = 0;
	virtual void OnExit() = 0;

	//add gameobject
	void AddGameObject(const std::wstring& name, std::shared_ptr<GameObject> object);
	//remove gameobject
	void RemoveGameObject(const std::wstring& name);

	std::shared_ptr<GameObject> GetGameObject(const std::wstring& name);

	// add UI widget
	void AddUIWidget(const std::wstring& name, std::shared_ptr<UIWidget> object);
	// remove UI widget
	void RemoveUIWidget(const std::wstring& name);

	std::shared_ptr<UIWidget> GetUIWidget(const std::wstring& name);

 // Default
public:
    void DefaultInitialize();
	void DefaultUpdate();
	void DefaultRender();

protected:
	void CreateDefaultCamera();

protected:
	std::string mSceneName;
	std::shared_ptr<GameObject> mDefaultCamera;
protected:
	// GameObjects
    std::unordered_map<std::wstring, std::shared_ptr<GameObject>> mGameObjects; // name , object(shared_ptr)
    // UI objects
    std::unordered_map<std::wstring, std::shared_ptr<UIWidget>> mUIObjects; // name , object(shared_ptr)

    // flags
	bool mIsCurrentScene = false;
};