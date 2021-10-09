#include "Agent.h"
#include <utility>
#include <vector>

class AgentGenerator{
public:
    AgentGenerator();
    Network edit_network(Network network, int layer, int neuron, Neuron this_neuron);
};

Network AgentGenerator::edit_network(Network network, int layer, int neuron, Neuron this_neuron) {
    Network edited_network = std::move(network);
    edited_network.layers[layer].neurons[neuron] = std::move(this_neuron);
    return edited_network;
}

AgentGenerator::AgentGenerator() = default;