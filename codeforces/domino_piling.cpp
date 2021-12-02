#include <iostream>
int main() {
    short m,n;
    std::cin >> m >> n;
    std::cout << m*(n/2)+ (n%2 ? m/2 : 0) << '\n';
}