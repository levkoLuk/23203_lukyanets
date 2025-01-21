cmake_minimum_required(VERSION 3.14)

project(Blackjack)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

set(SRC_FILES
    src/main.cpp
    src/Card.cpp
    src/Deck.cpp
    src/Player.cpp
    src/Strategy.cpp
    src/Game.cpp
    src/Tournament.cpp
    src/Factory.cpp
    src/DynamicLoader.cpp
    src/SimpleStrategy.cpp
)

add_executable(blackjack ${SRC_FILES})

target_link_libraries(blackjack dl)

add_library(SimpleStrategy SHARED src/SimpleStrategy.cpp)
target_link_libraries(SimpleStrategy Strategy)

target_include_directories(blackjack PRIVATE src)
target_include_directories(SimpleStrategy PRIVATE src)
