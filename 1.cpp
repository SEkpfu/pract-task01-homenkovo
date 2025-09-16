#include <iostream>

int main() {
    int hours;
    double cost, prem;
    std::cout << "Hours: ";
    std::cin >> hours;
    std::cout << "Cost: ";
    std::cin >> cost;
    std::cout << "Prem: ";
    std::cin >> prem;

    std::cout << "Full: " << hours * cost * (prem / 100 + 1) << std::endl;

    return 0;
}
