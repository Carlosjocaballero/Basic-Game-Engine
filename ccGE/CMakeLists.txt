set(SOURCE_FILES
	ccGEApp.cpp
   )

set(HEADER_FILES
	ccGe.h
	ccGEApp.h
	ccGEUtil.h
	ccGEWindow.h
	GLFWcode/GLFWimplementation.h
   )

add_library(ccGE SHARED ${SOURCE_FILES} ${HEADER_FILES})

add_definitions(-DCCGE_LIB)

target_precompile_headers(ccGE PRIVATE pch.h)

include_directories(../glfw/include)
include_directories(../ccGE)

target_link_libraries(ccGE glfw)