#include "AgentGenerator.h"

class AgentSystem{
public:
    AgentSystem();
    Agent train(std::vector<int> build, std::vector<std::vector<std::vector<double>>> train_data, double min_fitness);
};

Agent AgentSystem::train(std::vector<int> build, std::vector<std::vector<std::vector<double>>> train_data, double min_fitness) {
    AgentGenerator agentGenerator = AgentGenerator();
    Generator generator = Generator();
    Agent agent = Agent(generator.generate_random_network(build, train_data[0][0].size()));
    double best_fitness = agent.full_fitness(train_data);
    Agent best_agent = agent;
    while (min_fitness < best_fitness){
        std::vector<Agent> pop = agentGenerator.generate_agents(best_agent, (best_fitness - min_fitness) * 2.18);
        for (auto agent_pop : pop){
            if (agent_pop.full_fitness(train_data) < best_fitness){
                best_fitness = agent_pop.full_fitness(train_data);
                best_agent = agent_pop;
            }
        }
    }
    return best_agent;
}

AgentSystem::AgentSystem() = default;