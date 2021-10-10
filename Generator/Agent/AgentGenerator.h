#include "Agent.h"
#include <utility>
#include <vector>

class AgentGenerator{
public:
    AgentGenerator();
    std::vector<std::vector<int>> generateIndexesToModify(int size);
};

std::vector<std::vector<int>> AgentGenerator::generateIndexesToModify(int size) {
    //small, but powerful
    std::vector<std::vector<int>> results = {};
    for (int i = 0; i < size; ++i) {
        std::vector<std::vector<int>> pack = {};
        for (int j = 0; j < size - i; ++j) {
            std::vector<int> mini_pack = {};
            for (int k = 0; k < i + 1; ++k) {
                mini_pack.push_back(k + j);
                std::cout << k + j << " ";
                }
            std::cout << "   ";
        }
        std::cout << "\n";
    }
    return {{{}}};
}

AgentGenerator::AgentGenerator() = default;