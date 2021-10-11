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
    /*
    AgentGenerator agentGenerator = AgentGenerator();
    std::vector<std::vector<int>> generated = agentGenerator.generateIndexesToModify(15);
    std::cout << "done";
    for (auto big_vector : generated){
        for (auto vector : big_vector){
                std::cout << vector << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";*/
    std::vector<std::vector<double>> list = {
            {1, 2},
            {3, 4}
    };
    AgentGenerator agentGenerator = AgentGenerator();
    agentGenerator.edit(list, 0, 0);
}
