cmake_minimum_required(VERSION 3.24)
project(1000__ver2_0)

set(CMAKE_CXX_STANDARD 17)

add_executable(1000__ver2_0 main.cpp card.h card.cpp cardPack.h cardPack.cpp
        randomEngine.h randomEngine.cpp croupier.h croupier.cpp player.h player.cpp)
