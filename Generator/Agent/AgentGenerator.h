#include "Agent.h"
#include <utility>
#include <vector>

class AgentGenerator{
public:
    AgentGenerator();
    std::vector<std::vector<int>> generateIndexesToModify(int size);
};

std::vector<std::vector<int>> AgentGenerator::generateIndexesToModify(int size) {
    std::vector<std::vector<int>> results = {};
    for (int j = 0; j < size; ++j) {
        for (int k = 0; k < size; ++k) {
            results.push_back({j, k});
            std::cout << j << " " << k << "\n";
        }
    }
    return results;
}

AgentGenerator::AgentGenerator() = default;