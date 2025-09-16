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

void get_all(int hours, double cost, double prem, double* full, double* tax, double* pure) {
    *full = get_full(hours, cost, prem);
    *tax = get_tax(*full);
    *pure = get_pure(*full);
}

void get_worker_data(int* hours, double* cost, double* prem) {
    std::cout << "Hours: ";
    std::cin >> *hours;
    std::cout << "Cost: ";
    std::cin >> *cost;
    std::cout << "Prem: ";
    std::cin >> *prem;
}

int main() {
    int hours;
    double cost, prem, full, middle = 0;
    for (int i = 0; i < 5; ++i) {
        get_worker_data(&hours, &cost, &prem);
        full = get_full(hours, cost, prem);
        std::cout << "Full: " << full << std::endl;
        middle += full;
    }

    middle /= 5;

    std::cout << "Middle: " << middle << std::endl;

    return 0;
}
