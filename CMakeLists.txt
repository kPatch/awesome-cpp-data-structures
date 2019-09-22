cmake_minimum_required (VERSION 3.5)
project(DSPractice)

set(DS_PRACTICE_VERSION_MAJOR 1)
set(DS_PRACTICE_VERSION_MINOR 0)

# Adds single source file
# set(SOURCES ${PROJECT_SOURCE_DIR}/src/StackArray.cpp)

# Adds all cpp file to a GLOB instead of indivudally 
file(GLOB SOURCES "src/*.cpp")

include_directories("${PROJECT_SOURCE_DIR}/include")

####################################################
# Add BOOST test declarations
####################################################
# add_library(StackArray STATIC ${SOURCES})
add_library(DataStructuresLib STATIC ${SOURCES})
# enable_testing()
# add_subdirectory(test)

#Setup CMake to run tests
enable_testing()

#Prep ourselves for compiling boost
find_package(Boost COMPONENTS unit_test_framework REQUIRED)
include_directories (${Boost_INCLUDE_DIRS})

#I like to keep test files in a separate source directory called test
file(GLOB TEST_SRCS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} test/*.cpp)

#Run through each source
foreach(testSrc ${TEST_SRCS})
    #Extract the filename without an extension (NAME_WE)
    get_filename_component(testName ${testSrc} NAME_WE)

    #Add compile target
    add_executable(${testName} ${testSrc})

    #link to Boost libraries AND your targets and dependencies
    # target_link_libraries(${testName} ${Boost_LIBRARIES} [YOUR TARGETS/LIBRARIES])
    target_link_libraries(${testName} ${Boost_LIBRARIES} DataStructuresLib)

    #I like to move testing binaries into a testBin directory
    set_target_properties(${testName} PROPERTIES 
        RUNTIME_OUTPUT_DIRECTORY  ${CMAKE_CURRENT_SOURCE_DIR}/testBin)

    #Finally add it to test execution - 
    #Notice the WORKING_DIRECTORY and COMMAND
    add_test(NAME ${testName} 
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/testBin 
        COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/testBin/${testName} )
endforeach(testSrc)


#################
# Generate binary
#################
# add_executable(stackarray ${SOURCES})

