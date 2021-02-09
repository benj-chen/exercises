#include <iostream>
using namespace std;
int main() {
    int n,m,a;
    cin >> n >> m >> a;
    n = n/a + bool(n%a);
    m = m/a + bool(m%a);
    cout << (unsigned long long) n*m << '\n';
}