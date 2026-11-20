# Blocsar

A Minecraft like game being developed alongside my custom game engine [Kesar](https://github.com/TalinTheDev/Kesar) to
learn and have fun.

## Building

### Prerequisites

- A C++23 compatible compiler
- CMake 4.0+
- Ninja
- Graphics drivers supporting OpenGL 4.6+ (core)
- Git

### Build Instructions

1. Clone this repository

```bash
git clone https://github.com/TalinTheDev/Blocsar.git
cd Blocsar
```

2. Configure and build:

```bash
cmake -S . -B build -G Ninja # Add '-DFETCHCONTENT_SOURCE_DIR_KESAR="../Kesar"' if a Kesar's source exists locally
cmake --build build
```

3. Run (on PowerShell at least):
```bash
./build/Blocsar.exe
```

## Project Structure
```
Blocsar/
├── include/   # Game headers
├── src/       # Game implementation files
```

## License
Blocsar is licensed under the MIT License. See [LICENSE](LICENSE) for details.

### Third-Party Licenses
Blocsar uses the following open-source libraries:

- **[Kesar](https://github.com/TalinTheDev/Kesar)** — Licensed under the [MIT License](https://github.com/TalinTheDev/Kesar/blob/main/LICENSE). Kesar also uses additional third-party libraries, each with their own licenses.

Third-party components remain subject to their respective licenses.
