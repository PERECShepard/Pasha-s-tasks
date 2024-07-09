cmake_minimum_required(VERSION 3.24)
project(1000_)

set(CMAKE_CXX_STANDARD 17)

add_executable(game.cpp randomEngine.cpp player.cpp card.cpp cardPack.cpp main.cpp cardService.cpp)
