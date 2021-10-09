#include "Generator/Agent/Agent.h"



int main(){
    Generator generator = Generator();
    Agent agent = Agent(
            generator.generate_random_network({1, 2, 3, 2, 1, 2, 3, 2, 1, 2, 3, 172000, 2}, 2)
            );
    for (auto something : agent.forward({1, 1})){
        std::cout << something << " ";
    }
    std::cout << "\nNow Agent1\n";
    Agent agent1 = Agent(
            agent.export_network()
            );
    for (auto something : agent1.forward({1, 1})){
        std::cout << something << " ";
    }
}
