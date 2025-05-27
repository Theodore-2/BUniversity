#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>

int main() {
    int arr[] = {1, 6, 2, 9, 12, 15, 33, 28};
    int arrSize = sizeof(arr) / sizeof(int);

    std::vector<int> vec(arr, arr + arrSize);

    double sum = std::accumulate(vec.begin(), vec.end(), 0);
    double average = sum / vec.size();

    std::cout << "Average: " << average << std::endl;

    for (size_t i = 0; i < vec.size(); ++i) {
        double deviation = vec[i] - average;
        std::cout << "Value: " << vec[i] << ", Deviation: " << deviation << std::endl;
    }

    return 0;
}

