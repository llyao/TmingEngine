add_subdirectory(glad)
add_subdirectory(Lua)
add_subdirectory(Box2D)
add_subdirectory(KHR)
add_subdirectory(GLFW)
add_subdirectory(glm)
add_subdirectory(Assimp)
add_subdirectory(ImGui)
add_subdirectory(Stb_Image)
add_subdirectory(yaml)
add_subdirectory(TextEditor)
add_subdirectory(ImNodes)
add_subdirectory(Angelscript/sdk/angelscript/projects/cmake)
add_subdirectory(tgaimage)

SET_PROPERTY(TARGET glad  PROPERTY FOLDER "ThirdParty")
SET_PROPERTY(TARGET Box2D  PROPERTY FOLDER "ThirdParty")
#SET_PROPERTY(TARGET GLFW  PROPERTY FOLDER "ThirdParty")
SET_PROPERTY(TARGET glm  PROPERTY FOLDER "ThirdParty")
SET_PROPERTY(TARGET ImGui  PROPERTY FOLDER "ThirdParty")
#SET_PROPERTY(TARGET SDL  PROPERTY FOLDER "ThirdParty")

SET_PROPERTY(TARGET stb  PROPERTY FOLDER "ThirdParty")
SET_PROPERTY(TARGET yaml-cpp  PROPERTY FOLDER "ThirdParty")
SET_PROPERTY(TARGET TextEditor  PROPERTY FOLDER "ThirdParty")
SET_PROPERTY(TARGET ImNodes  PROPERTY FOLDER "ThirdParty")
SET_PROPERTY(TARGET lua  PROPERTY FOLDER "ThirdParty")
SET_PROPERTY(TARGET angelscript  PROPERTY FOLDER "ThirdParty")
SET_PROPERTY(TARGET tgaimage  PROPERTY FOLDER "ThirdParty")
if(WIN32)
SET_PROPERTY(TARGET zlib  PROPERTY FOLDER "ThirdParty")
SET_PROPERTY(TARGET zlibstatic  PROPERTY FOLDER "ThirdParty")
endif()
SET_PROPERTY(TARGET IrrXML  PROPERTY FOLDER "ThirdParty")
SET_PROPERTY(TARGET assimp  PROPERTY FOLDER "ThirdParty")