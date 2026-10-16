include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG 063de7e9578f82b369302001269680b4b1553359 # v1.18.0
  GIT_SHALLOW TRUE
  GIT_PROGRESS TRUE
)

if(WIN32)
  set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
endif()

FetchContent_MakeAvailable(googletest)

add_executable(tests)

target_sources(tests
  PRIVATE
    game_logic_tests.cpp
)

target_link_libraries(tests
  PRIVATE
    game_logic
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(tests)
