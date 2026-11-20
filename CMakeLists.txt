cmake_minimum_required(VERSION 4.0)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
include(FetchContent)

project(Blocsar LANGUAGES C CXX)

add_executable(${PROJECT_NAME} 
    src/main.cpp
)

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_23)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Include Kesar
FetchContent_Declare(
    Kesar
    GIT_REPOSITORY https://github.com/TalinTheDev/Kesar.git
    GIT_TAG main
)

FetchContent_MakeAvailable(Kesar)

target_link_libraries(${PROJECT_NAME}
    PRIVATE Kesar::Kesar
)
