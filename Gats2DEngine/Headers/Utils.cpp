
#include "Headers/pch.h"
#include "Utils.h"

bool Utils::StartsWith(std::string str, std::string comp)
{
	std::wstring::size_type index = str.find(comp);
	if (index != std::wstring::npos && index == 0)
		return true;

	return false;
}

bool Utils::StartsWith(std::wstring str, std::wstring comp)
{
	std::wstring::size_type index = str.find(comp);
	if (index != std::wstring::npos && index == 0)
		return true;

	return false;
}

std::wstring Utils::ToWString(std::string value)
{
	return std::wstring(value.begin(), value.end());
}

std::string Utils::ToString(std::wstring value)
{
	return std::string(value.begin(), value.end());
}

void Utils::Replace(OUT std::string& str, std::string from, std::string to)
{

	std::string temp = str;

	size_t start_pos = 0;
	while ((start_pos = temp.find(from, start_pos)) != std::string::npos)
	{
		temp.replace(start_pos, from.length(), to);
		start_pos += to.length();
	}

	str = temp;
}

void Utils::Replace(OUT std::wstring& str, std::wstring from, std::wstring to)
{
	std::wstring temp = str;
	size_t start_pos = 0;
	while ((start_pos = temp.find(from, start_pos)) != std::wstring::npos)
	{
		temp.replace(start_pos, from.length(), to);
		start_pos += to.length();
	}
	str = temp;
}
