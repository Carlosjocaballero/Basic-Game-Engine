set(SOURCE_FILES
	Event.cpp
	OpenGLCode/OpenGLPicture.cpp
	OpenGLCode/OpenGLShader.cpp
	OpenGLCode/OpenGLRenderer.cpp
	Picture.cpp
	Shader.cpp
	Renderer.cpp
	ccGEApp.cpp
	ccGEWindow.cpp
	GLFWcode/GLFWimplementation.cpp
   )

set(HEADER_FILES
	Event.h
	Keys.h
	OpenGLCode/OpenGLPicture.h
	OpenGLCode/OpenGLShader.h
	OpenGLCode/OpenGLRenderer.h
	Picture.h
	Shader.h
	Renderer.h
	PictureImplementation.h
	ShaderImplementation.h
	ccGE.h
	ccGEApp.h
	ccGEUtil.h
	ccGEWindow.h
	WindowImplementation.h
	GLFWcode/GLFWimplementation.h
   )

add_library(ccGE SHARED ${SOURCE_FILES} ${HEADER_FILES})

add_definitions(-DCCGE_LIB)

target_precompile_headers(ccGE PRIVATE pch.h)

include_directories(../glfw/include)
include_directories(../ccGE)
include_directories(../glad/include)
include_directories(../stbi)

target_link_libraries(ccGE glfw glad stbi)