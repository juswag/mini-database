cmake_minimum_required(VERSION 3.20)

project(mini_database LANGUAGES CXX)

add_executable(kv
    main.cc
)

target_compile_features(kv PRIVATE cxx_std_20)
