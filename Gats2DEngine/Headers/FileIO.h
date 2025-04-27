#pragma once

enum FileIOType :uint8
{
	READ,
	WRITE,
	APPEND,

	END
};;

/*	
	c: FileIO: Wrapper class for file I/O
		- Open, Close, Read, Write file
		- support binary file
		- support read/write custom struct
		- support read/write vector<T>
		- support read/write void*
*/
class FileIO
{
public:
	FileIO() = default;
	~FileIO() { Close(); }

	/*
		f: Open file
		param
		- wstring path: file name
		- FileIOType type: file open type(READ, WRITE, APPEND)
		return
		- bool: true if success, false if failed
	*/
	bool Open(std::wstring path, FileIOType type)
	{
		DWORD access = (type == FileIOType::READ) ? GENERIC_READ : GENERIC_WRITE;
		DWORD shared = (type == FileIOType::READ) ? FILE_SHARE_READ : 0;
		DWORD creation = (type == FileIOType::READ) ? OPEN_EXISTING : CREATE_ALWAYS;

		mHandle = CreateFileW(
			path.c_str(), access, shared, nullptr, creation, FILE_ATTRIBUTE_NORMAL, nullptr
		);

		return mHandle != INVALID_HANDLE_VALUE;
	}

	/*
		f: Close file
	*/
	void Close()
	{
		if (mHandle != INVALID_HANDLE_VALUE)
		{
			CloseHandle(mHandle);
			mHandle = INVALID_HANDLE_VALUE;
		}
	}

	template<typename T>
	void Write(const  T& data)
	{
		DWORD bytesWritten = 0;
		bool result = ::WriteFile(mHandle, &data, sizeof(T), reinterpret_cast<LPDWORD>(&bytesWritten), nullptr);
		assert(result == true);
	}

	void Write(const void* data, uint32 size)
	{
		uint32 bytesWritten = 0;
		bool result = ::WriteFile(mHandle, data, size, reinterpret_cast<LPDWORD>(&bytesWritten), nullptr);
		assert(result == true);
	}

	template<>
	void Write<std::string>(const std::string& data)
	{
		return Write(data);
	}

	void Write(const std::string& data)
	{
		uint32 size = (uint32)data.size();
		Write(size);

		if (data.size() == 0)
			return;

		Write((void*)data.data(), size);
	}

	template<typename T>
	void Read(OUT T& data)
	{
		DWORD bytesRead = 0;
		bool result = ::ReadFile(mHandle, &data, sizeof(T), reinterpret_cast<LPDWORD>(&bytesRead), nullptr);
		assert(result == true);
	}

	void Read(OUT void** data, uint32 size)
	{
		DWORD bytesRead = 0;
		bool result = ::ReadFile(mHandle, *data, size, reinterpret_cast<LPDWORD>(&bytesRead), nullptr);
		assert(result == true);
	}

	void Read(OUT std::string& data)
	{
		uint32 size = Read<uint32>();

		if (size == 0)
			return;

		char* temp = new char[size + 1];
		temp[size] = 0;
		Read((void**)&temp, size);
		data = temp;
		delete[] temp;
	}

	template<typename T>
	T Read()
	{
		T data;
		Read(data);
		return data;
	}

private:
	HANDLE mHandle = INVALID_HANDLE_VALUE;

};

