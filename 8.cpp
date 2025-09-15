#include <iostream>
#include <vector>
#include <limits>

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
    std::size_t count;
    std::cout << "Count: ";
    std::cin >> count;

    std::vector<int> hours(count);
    std::vector<double> cost(count), prem(count), full(count), tax(count), pure(count);
    for (int i = 0; i < count; ++i) {
        get_worker_data(&hours[i], &cost[i], &prem[i]);
        get_all(hours[i], cost[i], prem[i], &full[i], &tax[i], &pure[i]);
    }

    std::size_t min_num, max_num;
    double min = std::numeric_limits<double>::infinity(), max = 0, sum_tax = 0;
    std::vector<std::size_t> workers_with_full_greater_than_50000;
    for (std::size_t i = 0; i < count; ++i) {
        if (min > full[i]) {
            min = full[i];
            min_num = i;
        }

        if (max < full[i]) {
            max = full[i];
            max_num = i;
        }

        if (pure[i] > 50000) {
            workers_with_full_greater_than_50000.push_back(i);
        }

        sum_tax += tax[i];
    }

    std::cout << "The cheapest worker #" << min_num + 1 << std::endl
              << "The most expensive worker #" << max_num + 1 << " gained " << max << std::endl
              << "Count of workers gained more than 50000: " << workers_with_full_greater_than_50000.size() << std::endl;
    
    for (const std::size_t& i : workers_with_full_greater_than_50000) {
        std::cout << " - " << i + 1 << std::endl;
    }

    std::cout << "Full tax: " << sum_tax << std::endl;

    return 0;
}
