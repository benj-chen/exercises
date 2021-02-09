#include <iostream>
int main() {
    short m,n; // m and n are both less than 16 so why not; dominoes has
                        // a maximum of 128
    std::cin >> m >> n;
    std::cout << m*(n/2)+ (n%2 ? // has a line left over
    m/2 : 0) << '\n';
}