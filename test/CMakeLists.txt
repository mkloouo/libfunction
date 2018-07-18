# Configuring GTest/GMock framework
include(prepare_google_test.cml)

# Tests main file
set(TEST_MAIN_FILE ${CMAKE_CURRENT_SOURCE_DIR}/test_main.cc)

# Tests for functon library
add_subdirectory(testfunction)