#include "Agent.h"
#include <utility>
#include <vector>

class AgentGenerator{
public:
    AgentGenerator();
    std::vector<std::vector<int>> generateIndexesToModify(int size);
    std::vector<Agent> generate_agents(Agent base, double offset);
    double get_size(std::vector<std::vector<double>> big_vector);
};

double AgentGenerator::get_size(std::vector<std::vector<double>> big_vector) {
    double size = 0;
    for (auto vector : big_vector){
        size += vector.size();
    }
    return size;
}

std::vector<Agent> AgentGenerator::generate_agents(Agent base, double offset) {
    std::vector<std::vector<std::vector<double>>> base_exported = base.export_network();
    std::vector<std::vector<double>> base_network_exported = base_exported[0];
    std::vector<double> base_build_exported = base_exported[1][0];
}

std::vector<std::vector<int>> AgentGenerator::generateIndexesToModify(int size) {
    //small, but powerful
    std::vector<std::vector<int>> results = {};
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size - i; ++j) {
            std::vector<int> mini_pack = {};
            for (int k = 0; k < i + 1; ++k) {
                mini_pack.push_back(k + j);
            }
            results.push_back(mini_pack);
        }
    }
    return results;
}

AgentGenerator::AgentGenerator() = default;