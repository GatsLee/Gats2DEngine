#include "Headers/pch.h"
#include "ResourceManager.h"
#include "Resource/WTexture.h"
#include "Resource/WFont.h"
#include "Resource/WShader.h"
#include "Resource/Material.h"

void ResourceManager::Initialize()
{
	// Initialize resources
	// Add default resources

	// Default Texture
	Add<WTexture>(L"DefaultTexture", std::make_shared<WTexture>(L"DefaultTexture.png"));
	
	// Default Material
	Add<Material>(L"DefaultMaterial", std::make_shared<Material>());
	
	// Default Shader
	Add<WShader>(L"DefaultShader", std::make_shared<WShader>());
	std::shared_ptr<WShader> defaultShader = Get<WShader>(L"DefaultShader");
	if (defaultShader->LoadFromFile(L"default.vert", L"default.frag") == false)
	{
		ASSERT_MSG(false, "Failed to load default shader");
	}

	// Default Font
	Add<WFont>(L"DefaultFont", std::make_shared<WFont>());

	// Default Texture
	Add<WTexture>(L"DefaultTexture", std::make_shared<WTexture>(L"DefaultTexture.png"));
}