# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "Beta_BullDog_autogen"
  "CMakeFiles\\Beta_BullDog_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Beta_BullDog_autogen.dir\\ParseCache.txt"
  )
endif()
