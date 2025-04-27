#pragma once

#define DECLARE_SINGLE(ClassName)		\
private:									\
	ClassName() { }							\
public:										\
	static ClassName* GetInstance()	{		\
		static ClassName instance;			\
		return &instance;					\
	}

#define GET_SINGLE(ClassName) ClassName::GetInstance()
#define CHECK(p)	assert(SUCCEEDED(p))

#define ASSERT_MSG(expr, msg)                                      \
    if (!(expr))                                                   \
    {                                                              \
        OutputDebugStringA("Assertion Failed: " msg "\n");         \
        DebugBreak();                                              \
    }

#define HR(x)                                                 \
    {                                                         \
        HRESULT hr__ = (x);                                   \
        if (FAILED(hr__))                                     \
        {                                                     \
            OutputDebugStringA("HRESULT FAILED: " #x "\n");   \
            DebugBreak();                                     \
        }                                                     \
    }

#define DEBUG_PRINT_W0(msg) \
    OutputDebugStringW((std::wstring(L"[DEBUG] ") + std::wstring(msg) + L"\n").c_str())

#define DEBUG_PRINT_W1(msg, ...)                                                    \
    do {                                                                         \
        wchar_t buffer[512];                                                     \
        swprintf_s(buffer, 512, L"[DEBUG] " msg L"\n", __VA_ARGS__);             \
        OutputDebugStringW(buffer);                                              \
    } while (0)

#define DEBUG_PRINT_A0(msg) \
    OutputDebugStringA((std::string("[DEBUG] ") + std::string(msg) + "\n").c_str())

#define DEBUG_PRINT_A1(msg, ...)                                                    \
    do {                                                                         \
        char buffer[512];                                                        \
        sprintf_s(buffer, 512, "[DEBUG] " msg "\n", __VA_ARGS__);                \
        OutputDebugStringA(buffer);                                              \
    } while (0)



#define APP		    GET_SINGLE(Application)
#define WINDOW      Application::GetInstance()->GetWindow()
#define SCENE		GET_SINGLE(SceneManager)
#define INPUT		GET_SINGLE(InputManager)
#define TIME		GET_SINGLE(TimeManager)
#define DT			TIME->GetDeltaTime()
#define RESOURCES	GET_SINGLE(ResourceManager)
#define EVENT       GET_SINGLE(EventManager)
#define COROUTINE   GET_SINGLE(CoroutineManager)
#define UI          GET_SINGLE(UIManager)

//Animation
#define MAX_ANIMATION_FRAME		200
