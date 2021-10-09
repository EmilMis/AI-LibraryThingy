#include "Agent.h"
#include <utility>
#include <vector>

class AgentGenerator{
public:
    AgentGenerator();
    std::vector<std::vector<std::vector<int>>> generateIndexesToModify(int size);
};

std::vector<std::vector<std::vector<int>>> AgentGenerator::generateIndexesToModify(int size) {
    std::vector<std::vector<std::vector<int>>> result = {};
    for (int i = 0; i < size + 1; ++i) {
        std::vector<std::vector<int>> prop_distribution = {};
        for (int j = 0; j < size - i; ++j) {
            std::vector<int> prop = {};
            for (int k = 0; k < i; ++k) {
                std::cout << k + i << " ";
            }
        }
    }
    return {{{}}};
}

AgentGenerator::AgentGenerator() = default;