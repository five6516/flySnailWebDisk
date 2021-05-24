cmake_minimum_required (VERSION 3.0)
project (FlySnailWebDisk)

# The version number.
set (Tutorial_VERSION_MAJOR 1)
set (Tutorial_VERSION_MINOR 0)

# Enable C++17
set(CMAKE_CXX_STANDARD 17)

# 查找指定目录下的所有.cpp与.h文件 并存放到指定变量名SC_FILES中
set(HTTPLIB_SRC ${PROJECT_SOURCE_DIR}/opensourcelib/httplib/httplib.h ${PROJECT_SOURCE_DIR}/opensourcelib/httplib/httplib.cc)
FILE(GLOB SC_FILES "*.cpp" "*.cc" "*.h")

add_executable(${PROJECT_NAME} ${SC_FILES} ${HTTPLIB_SRC}) 

# 添加包含目录
include_directories(${PROJECT_SOURCE_DIR}/opensourcelib)
include_directories(${PROJECT_SOURCE_DIR}/opensourcelib/httplib)
include_directories(${PROJECT_SOURCE_DIR}/opensourcelib/inja)
include_directories(${PROJECT_SOURCE_DIR}/opensourcelib/nlohmann)

#添加选项
if(CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_C_FLAGS -pthread)  
    set(CMAKE_CXX_FLAGS -pthread)  
    set(CMAKE_EXE_LINKER_FLAGS -Wl,-rpath=.)
endif(CMAKE_COMPILER_IS_GNUCXX)

