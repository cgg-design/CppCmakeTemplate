####### Main Application  #######
# Main executable
# add the executabl, it's in same dir
add_executable(${MAIN} "main.cpp")
# Executable lirary: ${PROJECT}_Executable
# mit my_lib linken
target_link_libraries(${MAIN} PUBLIC ${LIBRARY_NAME})
# Wo liegt diese header file
target_include_directories(${MAIN} PUBLIC ${PROJECT_BINARY_DIR} )
target_compile_features(${LIBRARY_NAME} PUBLIC cxx_std_17)