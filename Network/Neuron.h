#include <utility>
#include <vector>
#include <iostream>

class Neuron {
    bool use_ReLU;
    static double max(double first_number, double second_number);
public:
    double bias;
    std::vector<double> weights;
    Neuron(std::vector<double> weights_input, double bias_input, bool use_ReLU_input = true);
    double forward(std::vector<double> inputs);
};

double Neuron::max(double first_number, double second_number) {
    if (first_number > second_number){
        return first_number;
    }
    else{
        return second_number;
    }
}

double Neuron::forward(std::vector<double> inputs) {
    double output = 0;
    for (int i = 0; i < inputs.size(); ++i) {
        output += inputs[i] * weights[i];
    }
    output += bias;
    if (use_ReLU){
        output = max(0, output);
    }
    return output;
}

Neuron::Neuron(std::vector<double> weights_input, double bias_input, bool use_ReLU_input) {
    weights = std::move(weights_input);
    bias = bias_input;
    use_ReLU = use_ReLU_input;
}