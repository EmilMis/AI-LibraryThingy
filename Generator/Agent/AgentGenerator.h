#include "Agent.h"
#include <utility>
#include <vector>

class AgentGenerator{
public:
    AgentGenerator();
    std::vector<std::vector<int>> generateIndexesToModify(int size);
    std::vector<Agent> generate_agents(Agent base, double offset);
    double get_size(std::vector<std::vector<double>> big_vector);
    std::vector<std::vector<double>> edit(std::vector<std::vector<double>> list, double index, double element);
};

double AgentGenerator::get_size(std::vector<std::vector<double>> big_vector) {
    double size = 0;
    for (auto vector : big_vector){
        size += vector.size();
    }
    return size;
}

std::vector<std::vector<double>> AgentGenerator::edit(std::vector<std::vector<double>> list, double index, double element) {
    std::vector<double> list_export = {};
    std::vector<double> list_build = {};
    std::vector<std::vector<double>> list_rebuild = {};

    for (auto vector : list){
        list_build.push_back(vector.size());
        for (auto element : vector){
            list_export.push_back(element);
        }
    }

    double rebuild_index = 0;

    list_export[index] = element;
    for(auto build_info : list_build){
        std::vector<double> rebuild_element = {};
        for (int i = 0; i < build_info; ++i) {
            rebuild_element.push_back(list_export[rebuild_index]);
            rebuild_index ++;
        }
        list_rebuild.push_back(rebuild_element);
    }
    return list_rebuild;
}

std::vector<Agent> AgentGenerator::generate_agents(Agent base, double offset) {
    std::vector<std::vector<std::vector<double>>> base_exported = base.export_network();
    std::vector<std::vector<double>> base_network_exported = base_exported[0];
    std::vector<double> base_build_exported = base_exported[1][0];
    return {Agent(Generator().generate_random_network({1, 2, 1}, 1))};
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