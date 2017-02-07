
# Assume Debug if a build type isn't specified
if( "" STREQUAL "${CMAKE_BUILD_TYPE}" )
    set( CMAKE_BUILD_TYPE "Debug" CACHE FILEPATH "" FORCE )
endif()

### Force some Emscripten CMake variables. CMake seems to be really particular
### about when these vars show up. They need to come after project.
set( CMAKE_AR 							"emcc" CACHE FILEPATH "" FORCE)
set( CMAKE_STATIC_LIBRARY_SUFFIX 		".bc" )
set( CMAKE_C_CREATE_STATIC_LIBRARY 		"<CMAKE_AR> -o <TARGET> <LINK_FLAGS> <OBJECTS>" )
set( CMAKE_CXX_CREATE_STATIC_LIBRARY 	"<CMAKE_AR> -o <TARGET> <LINK_FLAGS> <OBJECTS>" )

if( CINDER_GL_ES_2 )
	set( CINDER_GL_ES_PLATFORM	"es2" )
	set( CINDER_GL_ES_FLAGS 	"-DCINDER_GL_ES_2 -s FULL_ES2=1" )
elseif( CINDER_GL_ES_3 )
	set( CINDER_GL_ES_PLATFORM	"es3" )
	set( CINDER_GL_ES_FLAGS 	"-DCINDER_GL_ES_3 -s USE_WEBGL2=1 -s FULL_ES3=1" )
endif()

# C Flags
set( C_FLAGS "-fvisibility=default -D_UNIX ${CINDER_GL_ES_FLAGS} -s USE_GLFW=3 -s ALLOW_MEMORY_GROWTH=1 -s NO_EXIT_RUNTIME=1 -s DISABLE_EXCEPTION_CATCHING=0" )
set( CMAKE_C_FLAGS_DEBUG   "${C_FLAGS} -g -O0" )
set( CMAKE_C_FLAGS_RELEASE "${C_FLAGS} -Os" )

# CPP Flags
set( CXX_FLAGS "-stdlib=libc++ -std=c++11 -fvisibility=default -D_UNIX ${CINDER_GL_ES_FLAGS} -s USE_GLFW=3 -s DEMANGLE_SUPPORT=1 -s ALLOW_MEMORY_GROWTH=1 -s NO_EXIT_RUNTIME=1 -s DISABLE_EXCEPTION_CATCHING=0" )
set( CMAKE_CXX_FLAGS_DEBUG    "${CXX_FLAGS} -g -O0 -fexceptions -frtti" )
set( CMAKE_CXX_FLAGS_RELEASE  "${CXX_FLAGS} -Os -fexceptions -frtti" )

get_filename_component( CINDER_INC_DIR "${CINDER_DIR}/include" ABSOLUTE )
get_filename_component( CINDER_LIB_DIR "${CINDER_DIR}/lib"     ABSOLUTE )

set( CMAKE_DEBUG_POSTFIX "_d" )

if( "Debug" STREQUAL "${CMAKE_BUILD_TYPE}" )
    set( CINDER_LIB_SUFFIX "_d" CACHE FILEPATH "" FORCE )
endif()

