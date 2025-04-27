#pragma once

enum class ResourceType : uint8
{
	// Resource classes
	Material,
	Animation,
	//Wrapper classes
	WFont,
	WTexture,
	WShader,
	None,
	//...
	End
};

enum
{
	RESOURCE_TYPE_COUNT = static_cast<uint8>(ResourceType::End)
};

class ResourceBase : public std::enable_shared_from_this<ResourceBase>
{

public:
	ResourceBase(ResourceType type);
	virtual ~ResourceBase();
	
	ResourceType GetType() const { return mType; }

	const std::wstring& GetName() const { return mName; }
	const std::wstring& GetPath() const { return mPath; }
	uint32 GetId() const { return mId; }

	void SetName(const std::wstring& name) { mName = name; }
	void SetPath(const std::wstring& path) { mPath = path; }
	void SetId(uint32 id) { mId = id; }


	bool IsLoaded() const { return mLoaded; }
	void SetLoaded(bool loaded) { mLoaded = loaded; }


protected:
	virtual void Load(const std::wstring& path) { }
	virtual void Save(const std::wstring& path) { }

protected:
	ResourceType mType = ResourceType::None;
	std::wstring mName;
	std::wstring mPath;
	uint32 mId = 0;

	//flags
	bool mLoaded = true;
};


