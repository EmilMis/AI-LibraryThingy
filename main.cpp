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
    std::vector<std::vector<std::vector<double>>> train_data = {
            {
                    {1, 0}, {1, 0}
            },
            {
                    {1, 10}, {0, 1}
            },
            {
                    {1, 20}, {0, 1}
            },
            {
                    {3, 2}, {1, 0}
            },
            {
                    {5, 4}, {1, 0}
            },
            {
                    {1, 3}, {0, 1}
            },
            {
                    {1, 1}, {0.5, 0.5}
            },
    };
    Agent agent = agentSystem.train({2}, train_data, 0.01);
    std::cout << agent.forward({6, 5})[0] << " " << agent.forward({6, 5})[1];
}