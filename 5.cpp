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
    double cost, prem, tmp[2];
    for (int i = 0; i < 2; ++i) {
        get_worker_data(&hours, &cost, &prem);
        tmp[i] = get_full(hours, cost, prem);
    }

    std::cout << (tmp[0] >= tmp[1] ? '1' : '0') << ' ' << tmp[0] + tmp[1] << std::endl;

    return 0;
}
