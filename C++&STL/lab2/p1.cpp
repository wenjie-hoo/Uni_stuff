#include<iostream>
#include<memory>
#include<random>
using namespace std;

class Counter{
    public:
        uint64_t count;
        Counter():count(1){};
        virtual ~Counter(){
            std::cerr<<"Counter value:" << count << std::endl;
        }
        void increment(uint64_t value){
            count += value;
        }
        uint64_t getValue() const{
            return count;
        }
};

void recursiveFunction(std::unique_ptr<Counter[]> &counterArray, int m, int n) {
    if (m == 0) {
        return;
    }
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> randomIndex(0, n - 1);
    std::uniform_real_distribution<double> randomIncrement(0.1, 1.0);

    for (int i = 0; i < n; ++i) {
        int randomIndexValue = randomIndex(gen);
        double incrementValue = i * 0.1 * randomIncrement(gen);
        counterArray[randomIndexValue].increment(incrementValue);
    }

    recursiveFunction(counterArray, m - 1, n);
}

int main() {
    int n = 20;
    int m = 20;
    std::unique_ptr<Counter[]> counterArray(new Counter[n]);
    recursiveFunction(counterArray, m, n);
    for (int i = 0; i < n; ++i) {
        std::cout << "Counter " << i << " value: " << counterArray[i].getValue() << std::endl;
    }
    return 0;
}
