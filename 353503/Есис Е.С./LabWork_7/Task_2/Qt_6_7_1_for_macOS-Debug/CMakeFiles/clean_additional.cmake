# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/Lab7_Task2_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/Lab7_Task2_autogen.dir/ParseCache.txt"
  "Lab7_Task2_autogen"
  )
endif()
