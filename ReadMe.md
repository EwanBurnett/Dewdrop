# Dewdrop
A C++ 3D Rendering Library and Utilities

Planned to support major Graphics APIs:
    - DirectX 11
    - DirectX 12
    - OpenGL
    - Vulkan
 
## Dependencies
| Dependency | Version | Desc | 
| - | - | - | 
| [GLFW3](https://github.com/glfw/glfw) | 3.3.8 | Used for cross-platform Windowing |
| [IMGUI](https://github.com/ocornut/imgui/) | 1.89.8 | Intuitive native GUI | 


## Building and Requirements
### CMake
- Requires CMake 3.14.0 or greater 
    - You can install the latest version of CMake from [CMake.org](https://cmake.org/download/)
  
```bash
# Clone the repository
git clone https://github.com/EwanBurnett/Dewdrop/
cd Dewdrop

# Build using CMake
mkdir build
cd build 
cmake .. 
```

