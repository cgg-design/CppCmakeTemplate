# add to this liste the link to linalg.h
set (LIBRARY_INCLUDES "linalg/" ) # only .h
add_library(${LIBRARY_LINALG} INTERFACE)
# target_include_directories(${LIBRARY_LINALG} INTERFACE linalg)  # durch set library definieren
target_include_directories(${LIBRARY_LINALG} INTERFACE ${LIBRARY_INCLUDES})

# Loguru
# set (LOGURU_SOURCES "loguru.cpp/" ) #  for .cpp files
file(GLOB LOGURU_SOURCES "loguru/*.cpp*")  # werden alle .cpp files in loguru gelesen
add_library(${LIBRARY_LOG} ${LOGURU_SOURCES})
target_include_directories(${LIBRARY_LOG} PUBLIC loguru) # loguru = ordner name
if(UNIX)
    target_link_libraries(${LIBRARY_LOG} PUBLIC pthread dl)
endif()

# Celero : nue wenn der user benchmark ausführen will
if(USE_BENCHMARKS)
    add_subdirectory(Celero) # Celero = definierte Name in external dir
    add_library(${LIBRARY_BENCH} ALIAS celero)
endif()
