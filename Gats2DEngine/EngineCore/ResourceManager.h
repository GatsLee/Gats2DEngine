#pragma once

#include "Resource/ResourceBase.h"

// resource class: add more functionalities
class Animation;
class Material;

// sfml wrapper class: minimal functionality
class WTexture;
class WFont;
class WShader;

class ResourceManager 
{
	DECLARE_SINGLE(ResourceManager)
public:

	void Initialize();

	template <typename T>
	std::shared_ptr<T> Load(const std::wstring& key, const std::wstring& path);

	template <typename T>
	bool Add(const std::wstring& key, std::shared_ptr<T> actor);

	template <typename T>
	std::shared_ptr<T> Get(const std::wstring& key);


	template<typename T>
	ResourceType GetResourceType();

private:

	using KeyObjMap = std::map<std::wstring/*key*/, std::shared_ptr<ResourceBase> /*value*/>;
	std::array<KeyObjMap, RESOURCE_TYPE_COUNT> mResources;
};

template<typename T>
std::shared_ptr<T> ResourceManager::Load(const std::wstring& key, const std::wstring& path)
{
	auto objectType = GetResourceType<T>();
	
	KeyObjMap& keyObjMap = mResources[static_cast<uint8>(objectType)];

	auto iter = keyObjMap.find(key);
	if (iter != keyObjMap.end())
	{
		return std::static_pointer_cast<T>(iter->second);
	}

	std::shared_ptr<T> object = std::make_shared<T>();
	object->Load(path);
	keyObjMap[key] = object;

	return object;
}

template<typename T>
bool ResourceManager::Add(const std::wstring& key, std::shared_ptr<T> object)
{
	auto objectType = GetResourceType<T>();
	KeyObjMap& keyObjMap = mResources[static_cast<uint8>(objectType)];

	auto iter = keyObjMap.find(key);
	if (iter != keyObjMap.end())
	{
		return false;
	}
	keyObjMap[key] = object;
	return true;
}

template<typename T>
std::shared_ptr<T> ResourceManager::Get(const std::wstring& key)
{
	auto objectType = GetResourceType<T>();
	KeyObjMap& keyObjMap = mResources[static_cast<uint8>(objectType)];

	auto iter = keyObjMap.find(key);
	if (iter != keyObjMap.end())
	{
		return std::static_pointer_cast<T>(iter->second);
	}
	return nullptr;
}

template<typename T>
ResourceType ResourceManager::GetResourceType()
{
	if (std::is_same<T, Animation>::value)
	{
		return ResourceType::Animation;
	}
	else if (std::is_same<T, Material>::value)
	{
		return ResourceType::Material;
	}
	else if (std::is_same<T, WTexture>::value)
	{
		return ResourceType::WTexture;
	}
	else if (std::is_same<T, WFont>::value)
	{
		return ResourceType::WFont;
	}
	else if (std::is_same<T, WShader>::value)
	{
		return ResourceType::WShader;
	}

	assert(false);
	return ResourceType::None;
}