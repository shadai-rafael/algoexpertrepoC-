include(FetchContent)

FetchContent_Declare(
                googletest
                URL https://github.com/google/googletest/archive/555486f408ab4906118eddf11c856da7f8690f14.zip)
            
FetchContent_MakeAvailable(googletest)
            
enable_testing()

add_executable(
                Algoexpertcpp_test
                main.cpp
                array_callenges_test.cpp
                recursion_challenges_test.cpp
                stack_challenges_test.cpp
                binary_search_tree_challenges_test.cpp
                )
            
target_link_libraries(
                Algoexpertcpp_test
                Algoexpertcpp_lib
                GTest::gtest_main
                GTest::gmock_main)
            
include(GoogleTest)
            
gtest_discover_tests(Algoexpertcpp_test)