#include "Network/Network.h"
#include "Random/Random.h"
#include <vector>

class Generator{
public:
    Generator();
    Neuron generate_random_neuron(int amount_of_weights);
    Layer generate_random_layer(int amount_of_neurons, int amount_of_weights_per_neuron);
    Network generate_random_network(std::vector<int> build, int size_of_input);
};

Network Generator::generate_random_network(std::vector<int> build, int size_of_input) {
    std::vector<Layer> layers = {};
    for (int i = 0; i < build.size(); ++i) {
        if (i == 0){
            layers.push_back(generate_random_layer(build[i], size_of_input));
            continue;
        }
        layers.push_back(generate_random_layer(build[i], build[i - 1]));
    }
    return {layers};
}

Layer Generator::generate_random_layer(int amount_of_neurons, int amount_of_weights_per_neuron) {
    std::vector<Neuron> neurons = {};
    for (int i = 0; i < amount_of_neurons; ++i) {
        neurons.push_back(generate_random_neuron(amount_of_weights_per_neuron));
    }
    return {neurons};
}

Neuron Generator::generate_random_neuron(int amount_of_weights) {
    std::vector<double> weights = {};
    Random random = Random();
    for (int i = 0; i < amount_of_weights; ++i) {
        weights.push_back(random.generate_random_float());
    }
    return {weights, random.generate_random_float()};
}

Generator::Generator() = default;