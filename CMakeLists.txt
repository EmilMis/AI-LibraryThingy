cmake_minimum_required(VERSION 3.20)
project(AI-remastered)

set(CMAKE_CXX_STANDARD 14)

add_executable(AI main.cpp Network/Neuron.h Network/Layer.h Network/Network.h Random/Random.h Generator/Generator.h Generator/Agent/Agent.h Generator/Agent/AgentGenerator.h)