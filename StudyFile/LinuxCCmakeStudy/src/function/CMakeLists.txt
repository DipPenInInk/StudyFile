
# aux_source_directory(. FUNCTION)
# add_library(function ${FUNCTION})
# add_subdirectory(func)

# target_link_libraries(function func) 

get_filename_component(FOLDER_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
string(TOUPPER ${FOLDER_NAME} UPPER_FOLDER_NAME)

aux_source_directory(. ${UPPER_FOLDER_NAME}_SOURCES)

add_library(${FOLDER_NAME} ${${UPPER_FOLDER_NAME}_SOURCES})



# 获取当前文件夹下的所有子目录
file(GLOB subdirectories RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/*)

# 遍历所有子目录
foreach(subdirectory ${subdirectories})
    if(IS_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${subdirectory})
        # 为每个子目录添加一个库
        add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/${subdirectory})
        
        # 将子目录的库链接到 src
        target_link_libraries(${FOLDER_NAME} ${subdirectory})
    endif()
endforeach()