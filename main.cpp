#include "Generator/Agent/AgentSystem.h"

int main(){
    AgentSystem agentSystem = AgentSystem();

    Agent agent = agentSystem.train({20, 15, 13, 8, 5, 4, 2}, train_data, 13.2);
    std::cout << agent.forward({6, 5})[0] << " " << agent.forward({6, 5})[1];
}