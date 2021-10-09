#include "Generator/Agent/Agent.h"



int main(){
    Generator generator = Generator();
    Agent agent = Agent(
            generator.generate_random_network({1, 1, 2}, 2)
            );
    Agent agent2 = Agent(
            generator.generate_random_network({1, 1, 2}, 2)
    );
    print_vector(agent.network.forward({1, 1}));
    print_vector(agent2.network.forward({1, 1}));
    std::vector<std::vector<std::vector<double>>> exported_agent = agent.export_network();
    agent2.load_network(exported_agent);
    print_vector(agent2.network.forward({1, 1}));
}
