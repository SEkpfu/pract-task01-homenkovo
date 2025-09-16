#include <iostream>

#ifndef TAX
#   define TAX 0.13
#endif

double get_full(int hours, double cost, double prem) {
    return hours * cost * (prem / 100 + 1);
}

double get_tax(double full) {
    return full * TAX;
}

double get_pure(double full) {
    return full * (1 - TAX);
}

int main() {
    int hours;
    double cost, prem;
    std::cout << "Hours: ";
    std::cin >> hours;
    std::cout << "Cost: ";
    std::cin >> cost;
    std::cout << "Prem: ";
    std::cin >> prem;

    const double full = get_full(hours, cost, prem);
    std::cout << "Full:\t" << full << std::endl
              << "Tax:\t" << get_tax(full) << std::endl
              << "Pure:\t" << get_pure(full) << std::endl;

    return 0;
}
