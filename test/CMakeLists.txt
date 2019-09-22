find_package(Boost REQUIRED COMPONENTS unit_test_framework)
include_directories("${PROJECT_SOURCE_DIR}/include")

set(TEST_SOURCEs ${PROJECT_SOURCE_DIR}/test/StackArrayTest.cpp)
set(TEST_LIBS StackArray)

add_executable(test_main ${TEST_SOURCEs})
target_link_libraries(test_main ${TEST_LIBS} ${Boost_LIBRARIES})
add_test(StackArrayTest test_main COMMAND test_main)

