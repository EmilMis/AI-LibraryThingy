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
    Generator generator = Generator();
    AgentGenerator agentGenerator = AgentGenerator();
    Agent agent = Agent(generator.generate_random_network({1, 2}, 1));
    std::vector<Agent> agets_pop = agentGenerator.generate_agents(agent, 1);
    for (auto agent : agets_pop){
        for (auto element : agent.forward({1})){
            std::cout << element << " ";
        }
        std::cout << "\n";
    }
}