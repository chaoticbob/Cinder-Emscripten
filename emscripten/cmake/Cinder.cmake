
# include(${CMAKE_CURRENT_LIST_DIR}/DebugColours.cmake)
#
# execute_process( COMMAND uname -m COMMAND tr -d '\n' OUTPUT_VARIABLE CINDER_ARCH )
# execute_process( COMMAND which clang OUTPUT_VARIABLE CLANG_PATH )

### Force some Emscripten CMake variables. CMake seems to be really particular
### about when these vars show up. They need to come after project.
set( CMAKE_AR 							"emcc" CACHE FILEPATH "" FORCE)
set( CMAKE_STATIC_LIBRARY_SUFFIX 		".bc" )
set( CMAKE_C_CREATE_STATIC_LIBRARY 		"<CMAKE_AR> -o <TARGET> <LINK_FLAGS> <OBJECTS>" )
set( CMAKE_CXX_CREATE_STATIC_LIBRARY 	"<CMAKE_AR> -o <TARGET> <LINK_FLAGS> <OBJECTS>" )

# C Flags
set( C_FLAGS "-fvisibility=default -D_UNIX -DCINDER_GL_ES_2 -s FULL_ES2=1 -s USE_GLFW=3 -s ALLOW_MEMORY_GROWTH=1" )
set( CMAKE_C_FLAGS_DEBUG   "${C_FLAGS} -g -O0" )
set( CMAKE_C_FLAGS_RELEASE "${C_FLAGS} -O3 -ffast-math" )

# CPP Flags
set( CXX_FLAGS "-std=c++11 -fvisibility=default -D_UNIX -DCINDER_GL_ES_2 -s FULL_ES2=1 -s USE_GLFW=3 -s DEMANGLE_SUPPORT=1 -s ALLOW_MEMORY_GROWTH=1" )
set( CMAKE_CXX_FLAGS_DEBUG    "${CXX_FLAGS} -g -O0 -fexceptions -frtti" )
set( CMAKE_CXX_FLAGS_RELEASE  "${CXX_FLAGS} -O3 -fexceptions -frtti -ffast-math" )

get_filename_component( CINDER_INC_DIR "${CINDER_DIR}/include" ABSOLUTE )
get_filename_component( CINDER_LIB_DIR "${CINDER_DIR}/lib"     ABSOLUTE )
