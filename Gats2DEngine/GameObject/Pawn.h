#pragma once

#include "Component/Component.h"
#include "Actor.h"

class MonoBehaviour;
class Transform;
class Camera;
class MeshRenderer;
class ModelRenderer;
//class Animator;

class Pawn : public Actor
{
public:
	Pawn() : Actor("DefaultPawn") {}
	Pawn(string name) : Actor(name) {}
	~Pawn() {}

	void Awake() override;
	void Start() override;
	void Update() override;
	void FixedUpdate() override;
	void LateUpdate() override;

	virtual void SetupInput() {};
	virtual void Possess() {};
	virtual void UnPossess() {};

protected:
	bool mIsPossessed = false;
	//shared_ptr<Controller> mController;

};

