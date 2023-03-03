add_library(
            Algoexpertcpp_lib
            STATIC)

target_sources(
            Algoexpertcpp_lib
            PRIVATE
            array_challenges.cpp
            recursion_challenges.cpp)

target_include_directories(
            Algoexpertcpp_lib
            PUBLIC
            ./)

