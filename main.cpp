#include "Generator/Agent/AgentSystem.h"
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
    AgentSystem agentSystem = AgentSystem();

    Agent agent = agentSystem.train({20, 15, 13, 8, 5, 4, 2}, train_data, 13.2);
    std::cout << agent.forward({6, 5})[0] << " " << agent.forward({6, 5})[1];
}