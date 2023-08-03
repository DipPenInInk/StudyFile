if(NOT EXISTS "./cmake_install.cmake")
  message(STATUS "No install rules found, no clean made.")
  return()
endif() 

file(REMOVE_RECURSE

#删除文件夹
	"CMakeFiles"
	"./build"  

#删除文件
	"CMakeCache.txt"
	"Makefile"
	"./cmake_install.cmake"
	"./test_cmake"  
	"./.bash_profile"  
)
