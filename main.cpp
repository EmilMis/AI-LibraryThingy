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
    std::vector<std::vector<int>> generated = agentGenerator.generateIndexesToModify(37);
    for (auto big_vector : generated){
        for (auto vector : big_vector){
                std::cout << vector << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";*/

    AgentGenerator agentGenerator = AgentGenerator();
    std::vector<std::vector<double>> sample_list = {
            {1, 2, 3},
            {4, 5}
    };
    //std::cout << agentGenerator.get_size(sample_list);
    sample_list = agentGenerator.edit(sample_list, 4, 6);
    /*
    for (auto vector : sample_list){
        for (auto element : vector){
            std::cout << element << " ";
        }
        std::cout << "\n";
    }*/
}
