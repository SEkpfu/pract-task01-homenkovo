#include <iostream>
#include <cstring>
#include <iomanip>

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
    double cost, prem, data[2][3];
    char surnames[2][81];
    for (int i = 0; i < 2; ++i) {
        std::cout << "Surname: ";
        std::cin >> surnames[i];
        get_worker_data(&hours, &cost, &prem);
        get_all(hours, cost, prem, data[i], data[i] + 1, data[i] + 2);
    }

    for (int i = 0; i < 2; ++i) {
        if (data[i][2] < 1000) {
            // std::cout << surnames[i] << std::endl;
        } if (data[i][1] > 50) {
            // Writing first character '-' and last character of utf-8 encoded string 

            const std::size_t count = 1 + (static_cast<unsigned char>(surnames[i][0]) >> 6 == 0b11)
                                        + (static_cast<unsigned char>(surnames[i][0]) >> 5 == 0b111)
                                        + (static_cast<unsigned char>(surnames[i][0]) >> 4 == 0b1111);

            for (std::size_t j = 0; j < count; ++j) {
                std::cout << surnames[i][j];
            }

            std::cout << '-';

            std::size_t start, stop = std::strlen(surnames[i]);
            for (start = stop - 1; static_cast<unsigned char>(surnames[i][start]) >> 6 == 0b10; --start);

            for (std::size_t j = start; j < stop; ++j) {
                std::cout << surnames[i][j];
            }

            std::cout << std::endl;
        }
    }

    return 0;
}
