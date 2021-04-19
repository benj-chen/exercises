#include <iostream>
#include <cmath>
using namespace std;
// Largest palindrome that is a product of two 3-digit numbers
// O(999^2)
int main() {
    int max=0;
    for (int i=999;i--;) {
        for (int j=999;j--;) {
            int prod = i*j;
            string forw = to_string(prod);
            string backw = forw;
            reverse(begin(backw),end(forw));
            if (forw==backw) {
                max=fmax(max,prod);
            }
        }
    }
    cout << max << endl;
}