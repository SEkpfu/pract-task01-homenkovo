#include <functional>
#include <algorithm>
#include <iostream>
#include <utility>
#include <numeric>

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

template <class Iterator> std::size_t min_index(Iterator start, Iterator end) {
    return std::min_element(start, end) - start;
}

template <class Iterator> Iterator max_index(Iterator start, Iterator end) {
    return std::max_element(start, end);
}

template <typename T> std::vector<std::size_t> get_greater(const T* start, const T* end, T number) {
    std::vector<std::size_t> to_return;
    
    for (const T* i = start; i < end; ++i) {
        if (*i > number) {
            to_return.push_back(i - start);
        }
    }

    return to_return;
}

template <class Iterator, typename T> T sum(Iterator start, Iterator end, T init) {
    return std::accumulate(start, end, static_cast<T>(0), std::plus<T>());
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

    const std::vector<double>::const_iterator max = max_index(full.cbegin(), full.cend());
    const std::vector<std::size_t> workers_with_full_greater_than_50000 = get_greater(&pure[0], &pure[0] + pure.size(), 50000.0);

    std::cout << "The cheapest worker #" << min_index(full.cbegin(), full.cend()) + 1 << std::endl
              << "The most expensive worker #" << max - full.cbegin() + 1 << " gained " << *max << std::endl
              << "Count of workers gained more than 50000: " << workers_with_full_greater_than_50000.size() << std::endl;
    
    for (const std::size_t& i : workers_with_full_greater_than_50000) {
        std::cout << " - " << i + 1 << std::endl;
    }

    std::cout << "Full tax: " << sum(tax.cbegin(), tax.cend(), 0.0) << std::endl;

    return 0;
}
