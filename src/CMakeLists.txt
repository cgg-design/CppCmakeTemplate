### Bibliotheque ###
# MyLib library

set(LIBRARY_SOURCES "my_lib.cpp")
set(LIBRARY_INCLUDES "${PROJECT_SOURCE_DIR}/include/")

# Option for generating/building (doe src soll die libraries verwenden können)
add_library(${LIBRARY_NAME} OBJECT ${LIBRARY_SOURCES})
target_include_directories(${LIBRARY_NAME} PUBLIC ${LIBRARY_INCLUDES})
# mit Public linking sagt mann , dass wir die linalg lib in unserer lib nutzen wollen
# target_link_libraries(${LIBRARY_NAME} PUBLIC ${LIBRARY_LINALG}  )
target_link_libraries(${LIBRARY_NAME} PUBLIC ${LIBRARY_LINALG} ${LIBRARY_LOG} )

target_compile_features(${LIBRARY_NAME} PUBLIC cxx_std_17)
