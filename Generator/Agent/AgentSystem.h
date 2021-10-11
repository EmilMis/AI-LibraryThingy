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
    double best_fitness = agent.fitness();
}

AgentSystem::AgentSystem() = default;