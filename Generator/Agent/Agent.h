#include "Generator/Generator.h"
#include <utility>
#include <vector>

class Agent{
    double simple_fitness(std::vector<double> predicted, std::vector<double> expected);
public:
    Network network;
    Agent(Network agent_network);
    Agent(std::vector<std::vector<std::vector<double>>> exported_network);
    double fitness(std::vector<double> inputs, std::vector<double> expected);
    std::vector<double> export_neuron(Neuron neuron);
    std::vector<std::vector<std::vector<double>>> export_network();
    Neuron load_neuron(std::vector<double> exported_neuron);
    void load_network(std::vector<std::vector<std::vector<double>>> exported_network);
    std::vector<double> forward(std::vector<double> inputs);
};

std::vector<double> Agent::forward(std::vector<double> inputs) {
    return network.forward(inputs);
}

Agent::Agent(std::vector<std::vector<std::vector<double>>> exported_network) {
    load_network(std::move(exported_network));
}

void Agent::load_network(std::vector<std::vector<std::vector<double>>> exported_network) {
    std::vector<std::vector<double>> network_data = exported_network[0];
    std::vector<double> build_data = exported_network[1][0];
    std::vector<Layer> layers = {};

    int neuron = 0;

    for(auto build : build_data){
        std::vector<Neuron> layer = {};
        for (int i = 0; i < build; ++i) {
            layer.push_back(load_neuron(network_data[neuron]));
            neuron ++;
        }
        Layer new_Layer = Layer(layer);
        layers.push_back(new_Layer);
    }

    network = Network(layers);
}

Neuron Agent::load_neuron(std::vector<double> exported_neuron) {
    std::vector<double> weights = {};
    double bias = 0;
    for (int i = 0; i < exported_neuron.size(); ++i) {
        if (i < exported_neuron.size() - 1) {
            weights.push_back(exported_neuron[i]);
            continue;
        }
        bias = exported_neuron[i];
    }
    Neuron neuron = Neuron(weights, bias);
    return neuron;
}

std::vector<std::vector<std::vector<double>>> Agent::export_network() {
    std::vector<std::vector<double>> exported_network = {};
    std::vector<double> exported_build = {};
    for (auto layer : network.layers){
        exported_build.push_back(layer.neurons.size());
        for (auto neuron : layer.neurons){
            exported_network.push_back(export_neuron(neuron));
        }
    }
    return {exported_network, {exported_build}};
}

std::vector<double> Agent::export_neuron(Neuron neuron) {
    std::vector<double> exported = {};
    for (auto weight : neuron.weights){
        exported.push_back(weight);
    }
    exported.push_back(neuron.bias);
    return exported;
}

double Agent::fitness(std::vector<double> inputs, std::vector<double> expected) {
    std::vector<double> outputs = network.forward(inputs);
    return simple_fitness(outputs, expected);
}

double Agent::simple_fitness(std::vector<double> predicted, std::vector<double> expected) {
    double sum = 0;
    for (int i = 0; i < predicted.size(); ++i) {
        sum += (abs(predicted[i] - expected[i]));
    }
    return sum;
}

Agent::Agent(Network agent_network) {
    network = agent_network;
}