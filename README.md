# Gats2DEngine

- this is a simple 2d game engine based on SFML libray and C++17

![Engine Structure](https://github.com/GatsLee/Gats2DEngine/blob/master/Document/Gats2DEngine_structure.png)

- the engine is designed to be modular and extensible, allowing developers to easily add new features and functionality as needed.
- the engine is built using C++17 and SFML, making it easy to use and integrate with other libraries and tools.
- the engine is designed to be easy to use and understand, with a focus on simplicity and clarity AND my personal study for understanding of game engine(unity-like) architecture.

![Engine Core Structure](https://github.com/GatsLee/Gats2DEngine/blob/master/Document/EngineCore_Structure.png)

### Features I implemented

- 2D Rendering Engine
- Scene Management
  - Whole scene are managed in a map(efficient access) & stack(stack for undo/redo)
- Component System: Unity-like component system
  - Transform2D, SpriteRenderer, Animator, Camera, ScriptComponent
- Event System: Event system for communication between components
- Resource Management: Animation(SpriteSheet), Texture, Material, Shader, Font, Animation
- Coroutine System : Coroutine(ex. Scene Change: Title->Menu->Game)
- Input Management: Keyboard, Mouse, Joystick
- UI System: UI lock for preventing user double click
- Time Management: calculate DT and FPS

# Requirements

- C++17
- SFML 3.1
- Visual Studio 2022 (or compatible C++ IDE)

# Building

1. Clone the repository
2. Get SFML 3.1 and place it in the `Library/SFML` folder
3. Link necessary SFML libraries(get reference from SFML page)
4. Build and Run
