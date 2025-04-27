#pragma once
class Utils
{
public:
	static bool StartsWith(std::string str, std::string comp);
	static bool StartsWith(std::wstring str, std::wstring comp);

	static std::wstring ToWString(std::string value);
	static std::string ToString(std::wstring value);

	static void Replace(OUT std::string& str, std::string from, std::string to);
	static void Replace(OUT std::wstring& str, std::wstring from, std::wstring to);
};

