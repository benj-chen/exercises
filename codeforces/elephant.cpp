#include <iostream>

int main() {
    int n;
    std::cin >> n;
    std::cout << bool(n%5) + n/5 << '\n';
}