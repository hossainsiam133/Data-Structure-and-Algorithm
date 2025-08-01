#include <iostream>

// Function to calculate combinations (n choose r)
double combinations(int n, int r) {
    if (n < r) {
        return 0; // Invalid input
    }

    double result = 1.0;
    for (int i = 1; i <= r; i++) {
        result *= (static_cast<double>(n - i + 1) / static_cast<double>(i));
    }

    return result;
}

int main() {
    int n, r;

    // Input values for n and r
    std::cout << "Enter the value of n: ";
    std::cin >> n;
    std::cout << "Enter the value of r: ";
    std::cin >> r;

    // Calculate and display the combination
    double result = combinations(n, r);
    std::cout << "C(" << n << ", " << r << ") = " << result << std::endl;

    return 0;
}
