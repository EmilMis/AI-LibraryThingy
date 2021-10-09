#include <random>

class Random{
    static double pot(int number, int potention);
public:
    Random();
    static int random_int(int from, int to);
    static double generate_random_float(int size = 6);
};

double Random::pot(int number, int potention) {
    int result = 1;
    for (int i = 0; i < potention; ++i) {
        result *= number;
    }
    return result;
}

double Random::generate_random_float(int size) {
    double result = 0;
    for (int i = 0; i < size; ++i) {
        if (i == size - 1){
            result += (random_int(1, 9) * pot(10, i));
            continue;
        }
        result += (random_int(0, 9) * pot(10, i));
    }
    return result / pot(10, size);
}

int Random::random_int(int from, int to) {
    std::random_device random_device;
    std::mt19937 engine{random_device()};
    std::uniform_int_distribution<> dist(from, to);
    return dist(engine);
}


Random::Random() = default;
