file(GLOB_RECURSE headers 
"Core/*.h"
"Core/Log/*.h"
"Core/*.h??"
"Plantform/FileSystem/*.h"
"Plantform/FileSystem/*.hpp"
"Scene/Components/Transform.h"
"Plantform/Time/*.h"
"Scene/Components/IComponent.h"
"Core/Math/Vector2.h"
"Core/Math/Vector3.h"
"Core/Math/Matrix.h"
"Core/Math/Radian.h"
"Core/Math/Quaternion.h"
"Plantform/Windows/win/*.h"
"Plantform/Windows/*.h"

"im.h"
"Scene/*.h??"
"Rendering/*.h"
"Rendering/*.h??"

)

file(GLOB_RECURSE sources 
"Core/*.cpp" 
"Core/Log/*.cpp"
"Plantform/FileSystem/*.cpp" 
"imgui/*.c"
"imgui/*.c??"
"3Part/STB/*.cpp"
"../../include/*.cpp"
"Model/model.cpp"
"Core/Math/Vector2.cpp"
"Core/Math/Vector3.cpp"
"Core/Math/Matrix.cpp"
"Core/Math/Quaternion.cpp"

"Scene/Components/Transform.cpp"
"Scene/Components/IComponent.cpp"
"Scene/*.cpp"

"Plantform/Windows/win/*.cpp"
"Plantform/Windows/*.cpp"

#"RHI/*.c"
#"RHI/*.c??"

#"Threading/*.c??"

#"RHI/D3D11/*.c"
#"RHI/D3D11/*.c??"

#"RHI/Vulkan/*.c"
#"RHI/Vulkan/*.c??"

"Rendering/*.c"
"Rendering/*.c??"

"Plantform/Time/*.c??"

#"../ThirdParty/Angelscript/sdk/add_on/scriptstdstring/*.c??"

) 

include_directories("../../include")									#添加头文件目录
include_directories(".")    	
include_directories("../ThirdParty/Box2D")
include_directories("../ThirdParty/Box2D/Testbed/Framework")            #添加头文件目录
include_directories("../ThirdParty/Vulkan_1.1.106.0/shaderc")
include_directories("../ThirdParty/Vulkan_1.1.106.0/vulkan")
include_directories("../ThirdParty/SPIRV-Cross-2019-03-29")
include_directories("../ThirdParty/Angelscript/sdk/add_on")
include_directories("../../include/angelscript")
include_directories("../../include/ImGui")

set(libpath ${PROJECT_SOURCE_DIR}/Library/static)
link_directories(${libpath})

add_library_beautiful(TmingEngine STATIC ${headers} ${sources})


if(WIN32)
find_library (GLFW glfw3.lib ${libpath})
elseif(APPLE)
find_library (GLFW libglfw3.a ${libpath})
endif()

target_link_libraries(TmingEngine lua)
target_link_libraries(TmingEngine Box2D)
target_link_libraries(TmingEngine ${GLFW})
target_link_libraries(TmingEngine stb)
target_link_libraries(TmingEngine ImGui)
target_link_libraries(TmingEngine glad)
target_link_libraries(TmingEngine glm)
#target_link_libraries(TmingEngine scheme)
target_link_libraries(TmingEngine assimp)
target_link_libraries(TmingEngine TextEditor)
target_link_libraries(TmingEngine ImNodes)
target_link_libraries(TmingEngine angelscript)
target_link_libraries(TmingEngine tgaimage)


