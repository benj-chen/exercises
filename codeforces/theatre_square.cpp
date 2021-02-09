#include <iostream>
#include <cmath>
using namespace std;
int main() {
    unsigned long long n,m,a;
    cin >> n >> m >> a;
    n = n/a + bool(n%a);
    m = m/a + bool(m%a);
    cout << n*m << '\n';
}