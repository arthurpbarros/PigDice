cmake_minimum_required(VERSION 2.0)
project (PigDice)
#Inclui o diretório com os .h
include_directories(include)
#Adiciona os arquivos .cpp
#set(SOURCES src/game.cpp src/ia.cpp src/main.cpp)
file(GLOB SOURCES "src/*.cpp")

add_executable(game ${SOURCES})
