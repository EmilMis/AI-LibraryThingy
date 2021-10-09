#include "Layer.h"
#include <utility>
#include <vector>
#include <cmath>

class Network{
    static double sum(const std::vector<double>& some_list);
    static std::vector<double> softmax(std::vector<double> outputs);
public:
    std::vector<Layer> layers;
    Network(std::vector<Layer> layers_input);
    Network() {};
    std::vector<double> forward(std::vector<double> inputs, bool use_softmax = true);
};



double Network::sum(const std::vector<double>& some_list) {
    double sum = 0;
    for (auto element : some_list){
        sum += element;
    }
    return sum;
}

std::vector<double> Network::softmax(std::vector<double> outputs) {
    double e = 2.71828;
    for (double & output : outputs) {
        output = pow(output, e);
    }
    std::vector<double> softmax_outputs = {};
    double sum_outputs = sum(outputs);
    softmax_outputs.reserve(outputs.size());
    for (auto element : outputs){
        softmax_outputs.push_back(element / sum_outputs);
    }
    return softmax_outputs;
}

std::vector<double> Network::forward(std::vector<double> inputs, bool use_softmax) {
    std::vector<double> current_inputs = std::move(inputs);
    for (auto layer : layers){
        current_inputs = layer.forward(current_inputs);
    }
    if (use_softmax){
        current_inputs = softmax(current_inputs);
    }
    return current_inputs;
}

Network::Network(std::vector<Layer> layers_input) {
    layers = std::move(layers_input);
}