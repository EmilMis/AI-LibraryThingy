#include "Neuron.h"
#include <utility>
#include <vector>

class Layer{
public:
    std::vector<Neuron> neurons;
    Layer(std::vector<Neuron> neurons_input);
    std::vector<double> forward(const std::vector<double>& inputs);
};

std::vector<double> Layer::forward(const std::vector<double>& inputs) {
    std::vector<double> outputs = {};
    for (auto neuron : neurons){
        outputs.push_back(neuron.forward(inputs));
    }
    return outputs;
}

Layer::Layer(std::vector<Neuron> neurons_input) {
    neurons = std::move(neurons_input);
}