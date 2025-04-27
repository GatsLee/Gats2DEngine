#pragma once
class EventManager
{
	DECLARE_SINGLE(EventManager);
public:
	using EventCallback = std::function<void()>;

	void Subscribe(const std::string& eventName, EventCallback callback)
	{
		mSubscribers[eventName].push_back(callback);
	}

	void Broadcast(const std::string& eventName)
	{
		auto iter = mSubscribers.find(eventName);
		if (iter != mSubscribers.end())
		{
			for (auto& cb : iter->second)
				cb();
		}
	}

private:
	std::unordered_map<std::string, std::vector<EventCallback>> mSubscribers;
};

