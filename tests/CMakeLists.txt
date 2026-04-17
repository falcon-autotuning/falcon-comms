find_package(GTest REQUIRED)
include(GoogleTest)

set(DLL_SEARCH_PATHS "${CMAKE_BINARY_DIR}}/tests" "${CMAKE_BINARY_DIR}")
string(REPLACE ";" "\\;" TEST_PATH_ENV "${DLL_SEARCH_PATHS}")
set(TEST_PATH_ENV "${TEST_PATH_ENV};$ENV{PATH}")

# Test utilities
add_library(falcon-comms-test-utils STATIC
  test_utils/TestFixture.hpp
)

target_link_libraries(falcon-comms-test-utils
  PUBLIC
    falcon-comms
    GTest::gtest
)

target_include_directories(falcon-comms-test-utils
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/test_utils
)

set_target_properties(falcon-comms-test-utils PROPERTIES
  LINKER_LANGUAGE CXX
)

# Unit tests
add_executable(falcon_comms_unit_tests
  unit/test_manager.cpp
  unit/test_autotuner_comms.cpp
  unit/test_routine_comms.cpp
  unit/test_runtime_comms.cpp
)

target_link_libraries(falcon_comms_unit_tests
  PRIVATE
    falcon-comms
    falcon-comms-test-utils
    GTest::gtest
    GTest::gtest_main
)

add_test(NAME falcon_comms_unit_tests COMMAND falcon_comms_unit_tests)
if(WIN32)
  set_tests_properties(falcon_comms_unit_tests 
    PROPERTIES ENVIRONMENT "PATH=${TEST_PATH_ENV}")
endif()

