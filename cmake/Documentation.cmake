find_package(Doxygen)
if(DOXYGEN_FOUND)
    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/docs/Doxyfile.in
                   ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile @ONLY)
    add_custom_target("${PROJECT}_Doc"
    ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile # Wo liegt dise doxyfile datei
    WORKING_DIRRECTORY  ${CMAKE_CURRENT_SOURCE_DIR}/docs) # Wo soll speichern
endif()