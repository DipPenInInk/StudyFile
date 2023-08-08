cmake_minimum_required(VERSION 3.0)  #规定使用的最低版本

project(TEST)  #规定项目名称

set(EXECUTABLE_NAME test_cmake)  # 设置可执行文件名
set(FIRMWARE_FOLDER_NAME genfiles)  # 设置可执行文件名
set(SOFTWARE_FOLDER_NAME src)  # 设置可执行文件名


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -lm -O2 -Wall") # -Wall 输出警告信息； -g增加调试信息   -O2增加优化

set(CMAKE_BUILD_TYPE Debug)

aux_source_directory(. PRIMARY)#收集指定目录中所有源文件的名称，并将列表存储在提供的变量中。

# 查找并包含相关头文件
file(GLOB_RECURSE HEADER_FILES ${CMAKE_SOURCE_DIR}/${SOFTWARE_FOLDER_NAME}/*.h)
foreach(HEADER ${HEADER_FILES})
    get_filename_component(HEADER_PATH ${HEADER} DIRECTORY)
    list(APPEND INCLUDE_DIRS ${HEADER_PATH})
endforeach()
list(REMOVE_DUPLICATES INCLUDE_DIRS)
include_directories(${INCLUDE_DIRS})




add_subdirectory(${SOFTWARE_FOLDER_NAME})
add_executable(${EXECUTABLE_NAME} ${PRIMARY}) #创建可执行文件 可执行文件名称  源文件名称  == gcc main.c -o test_cmake


add_custom_target(bclean
    COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/clean_build.sh
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

add_dependencies(bclean ${EXECUTABLE_NAME})



add_custom_target(
  genfiles

  COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_BINARY_DIR}/${FIRMWARE_FOLDER_NAME}
  COMMAND "${CMAKE_OBJCOPY}" -O ihex ${CMAKE_BINARY_DIR}/${EXECUTABLE_NAME} ${CMAKE_BINARY_DIR}/${FIRMWARE_FOLDER_NAME}/${EXECUTABLE_NAME}.hex  
  COMMAND "${CMAKE_OBJCOPY}" -O binary ${CMAKE_BINARY_DIR}/${EXECUTABLE_NAME} ${CMAKE_BINARY_DIR}/${FIRMWARE_FOLDER_NAME}/${EXECUTABLE_NAME}.bin  
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)

target_link_libraries(${EXECUTABLE_NAME} ${SOFTWARE_FOLDER_NAME})






