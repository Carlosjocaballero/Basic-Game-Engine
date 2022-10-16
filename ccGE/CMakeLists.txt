set(SOURCE_FILES
	ccGEApp.cpp
   )

set(HEADER_FILES
	ccGe.h
	ccGEApp.h
	ccGEUtil.h
   )

add_library(ccGE SHARED ${SOURCE_FILES} ${HEADER_FILES})

add_definitions(-DCCGE_LIB)

target_precompile_headers(ccGE PRIVATE pch.h)

include_directories(../glfw/include)

target_link_libraries(ccGE glfw)