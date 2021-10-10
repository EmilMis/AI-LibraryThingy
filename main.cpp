#include "Generator/Agent/AgentGenerator.h"
#include <iostream>

void print_bigg_vector(std::vector<std::vector<std::vector<int>>> bigg_vector){
    for (auto big_vector : bigg_vector){
        for(auto vector : big_vector){
            for (auto element : vector){
                std::cout << element << " ";
            }
        }
    }
    std::cout << "\n";
}

int main(){
    AgentGenerator agentGenerator = AgentGenerator();
    std::vector<std::vector<int>> generated = agentGenerator.generateIndexesToModify(37);
    for (auto big_vector : generated){
        for (auto vector : big_vector){
                std::cout << vector << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}
