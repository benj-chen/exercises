#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int a,b,min=1,max=6;
    cin >> a >> b;
    
    while (true) {
        if (pow(3,min) * a > pow(2,min) * b) {
            cout << min << endl;
            return 0;
        } else min++;
        if (!(pow(3,max) * a > pow(2,max) * b)) {
            cout << max+1 << endl;
            return 0;
        } else max--;
    }
}