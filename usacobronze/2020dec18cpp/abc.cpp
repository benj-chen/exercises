#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int inp[7];
    for (int i=0;i<7;i++) cin >> inp[i];
    sort (inp, inp+7);
    const int a=inp[0];
    const int b=inp[1];
    cout << a << ' ' << b << ' ' << inp[6]-a-b << '\n';
}