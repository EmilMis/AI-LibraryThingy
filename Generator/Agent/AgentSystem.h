#include "AgentGenerator.h"

class AgentSystem{
public:
    AgentSystem();
    Agent train(std::vector<int> build, std::vector<std::vector<std::vector<double>>> train_data, double min_fitness);
};

Agent AgentSystem::train(std::vector<int> build, std::vector<std::vector<std::vector<double>>> train_data, double min_fitness) {
    Random random = Random();
    AgentGenerator agentGenerator = AgentGenerator();
    Generator generator = Generator();
    Agent agent = Agent(generator.generate_random_network(build, train_data[0][0].size()));
    double best_fitness = agent.full_fitness(train_data);
    Agent best_agent = agent;
    double gen = 0;
    while (true){
        if (best_fitness < min_fitness){
            break;
        }
        std::vector<Agent> pop = agentGenerator.generate_agents(best_agent, (best_fitness - min_fitness) * random.generate_random_float() * random.random_int(2, 9));
        for (auto agent_pop : pop){
            if (agent_pop.full_fitness(train_data) < best_fitness){
                best_fitness = agent_pop.full_fitness(train_data);
                best_agent = agent_pop;
            }
        }
        std::cout << gen << " " << best_fitness << " " << min_fitness << "\n";
        gen ++;

    }
    return best_agent;
}

AgentSystem::AgentSystem() = default;