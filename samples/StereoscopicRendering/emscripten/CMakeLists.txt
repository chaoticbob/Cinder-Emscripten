# StereoscopicRendering
cmake_minimum_required( VERSION 3.1 FATAL_ERROR )
set( CMAKE_VERBOSE_MAKEFILE on )

get_filename_component( CINDER_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../../.." ABSOLUTE )
include( ${CINDER_DIR}/emscripten/cmake/Cinder.cmake )

project( StereoscopicRendering )

# For Emscripten we need to do this again since project() resets some vars .
include( ${CINDER_DIR}/emscripten/cmake/Cinder.cmake )

get_filename_component( SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../src" ABSOLUTE )
get_filename_component( INC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../include" ABSOLUTE )
set( ASSETS_DIR "../../../assets@/" )

#if( NOT TARGET cinder${CINDER_LIB_SUFFIX} )
#    find_package( cinder REQUIRED
#        PATHS ${PROJECT_SOURCE_DIR}/../../../emscripten/${CMAKE_BUILD_TYPE}/${CINDER_OUT_DIR_PREFIX}
#        $ENV{Cinder_DIR}/emscripten/${CMAKE_BUILD_TYPE}/${CINDER_OUT_DIR_PREFIX}
#    )
#endif()

# Use PROJECT_NAME since CMAKE_PROJET_NAME returns the top-level project name.
set( EXE_NAME ${PROJECT_NAME} )

set( SRC_FILES
	${SRC_DIR}/StereoscopicRenderingApp.cpp
	${SRC_DIR}/StereoAutoFocuser.cpp
)

set( CMAKE_EXECUTABLE_SUFFIX ".html" )
if( EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/../assets" )
	set( CMAKE_EXE_LINKER_FLAGS  "--preload-file ${ASSETS_DIR}" )
endif()

add_executable( "${EXE_NAME}" ${SRC_FILES} )

target_include_directories(
	"${EXE_NAME}"
	PUBLIC ${INC_DIR} 
	${CINDER_INC_DIR}
)

target_link_libraries( 
	"${EXE_NAME}" 
	${CINDER_LIB_DIR}/emscripten/${CINDER_GL_ES_PLATFORM}/libcinder${CINDER_LIB_SUFFIX}.bc
	${CINDER_LIB_DIR}/emscripten/libboost_filesystem.a
	${CINDER_LIB_DIR}/emscripten/libboost_system.a
)
