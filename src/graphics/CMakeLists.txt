include(FetchContent)

FetchContent_Declare(
  SDL2
  GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
  GIT_TAG 5d249570393f7a37e037abf22cd6012a4cc56a71 # release-2.32.10
  GIT_SHALLOW TRUE
  GIT_PROGRESS TRUE
)

set(SDL_SHARED OFF CACHE BOOL "" FORCE)
set(SDL_STATIC ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(SDL2)

add_library(graphics)

target_sources(graphics
  PRIVATE
    Renderer.cpp
    Window.cpp
  PUBLIC
    FILE_SET HEADERS
    BASE_DIRS .
    FILES
      Renderer.h
      Types.h
      Window.h
)

target_link_libraries(graphics
  PUBLIC
    SDL2::SDL2-static
)

if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
  target_compile_definitions(graphics PUBLIC __PRFCHWINTRIN_H)
endif()
