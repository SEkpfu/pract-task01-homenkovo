// Not done yet!

#include <algorithm>
#include <iostream>
#include <numeric>

#ifndef WORKERS
#   define WORKERS 4
#endif

#ifndef MONTHS
#   define MONTHS 12
#endif

#ifndef TAX
#   define TAX 0.13
#endif

double get_full(int hours, double cost, double prem = 0.0) {
    return hours * cost * (prem / 100 + 1);
}

double get_tax(double full) {
    return full * TAX;
}

double get_pure(double full) {
    return full * (1 - TAX);
}

int main() {
    double cost[WORKERS];
    int hours[WORKERS][MONTHS];

    std::cerr << "Where is " << MONTHS << " months!" << std::endl;
    for (std::size_t i = 0; i < WORKERS; ++i) {
        std::cout << "Cost: ";
        std::cin >> cost[i];
        std::cout << "Hours: ";
        for (std::size_t j = 0; j < MONTHS; ++j) {
            std::cin >> hours[i][j];
        }
    }

    double pnt[2][WORKERS][MONTHS];
    double summary = 0;

    for (std::size_t i = 0; i < WORKERS; ++i) {
        for (std::size_t j = 0; j < MONTHS; ++j) {
            const double full = get_full(hours[i][j], cost[i]);
            summary += 
            (pnt[0][i][j] = get_pure(full));
            pnt[1][i][j] = get_pure(full);
        }
    }

    std::cout << "Cost of first worker in second month: " << pnt[0][0][1] << std::endl
              << "Tax of third worker: " << std::accumulate(pnt[1][2], pnt[1][2] + MONTHS, 0.0, std::plus<double>()) << std::endl
              << "Worker that gets most in third month #" <<  << std::endl
              << "Summary: " << summary << std::endl;

    return 0;
}
