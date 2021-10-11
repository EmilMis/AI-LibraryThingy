#include "Agent.h"
#include <utility>
#include <vector>

class AgentGenerator{
public:
    AgentGenerator();
    std::vector<std::vector<double>> generateIndexesToModify(int size);
    std::vector<Agent> generate_agents(Agent base, double offset);
    double get_size(std::vector<std::vector<double>> big_vector);
    std::vector<std::vector<double>> edit(std::vector<std::vector<double>> list, double index, double element);
    std::vector<std::vector<double>> edit_pp(std::vector<std::vector<double>> list, double index, double element);
    Agent mutate_indexes(Agent base_agent, double offset, std::vector<double> indexes);
};

std::vector<std::vector<double>> AgentGenerator::edit_pp(std::vector<std::vector<double>> list, double index, double element) {
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

    list_export[index] = element + list_export[index];
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

Agent AgentGenerator::mutate_indexes(Agent base_agent, double offset, std::vector<double> indexes) {
    std::vector<std::vector<std::vector<double>>> agent_export = base_agent.export_network();
    std::vector<std::vector<double>> agent_network = agent_export[0];
    std::vector<double> agent_build = agent_export[1][0];
    for(auto index : indexes){
        agent_network = edit_pp(agent_network, index, offset);
    }
    return Agent({agent_network, {agent_build}});
}

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
    std::vector<Agent> agents = {};
    double agent_size = base.export_network()[0].size();
    std::vector<std::vector<double>> indexes_modify = generateIndexesToModify(agent_size);
        for (auto index_pack: indexes_modify) {
            agents.push_back(
                    mutate_indexes(base, offset, index_pack)
            );
        }
        for (auto index_pack: indexes_modify) {
            agents.push_back(
                    mutate_indexes(base, -offset, index_pack)
            );
        }

    return agents;
}

std::vector<std::vector<double>> AgentGenerator::generateIndexesToModify(int size) {
    //small, but powerful
    std::vector<std::vector<double>> results = {};
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size - i; ++j) {
            std::vector<double> mini_pack = {};
            for (int k = 0; k < i + 1; ++k) {
                mini_pack.push_back(k + j);
            }
            results.push_back(mini_pack);
        }
    }
    return results;
}

AgentGenerator::AgentGenerator() = default;