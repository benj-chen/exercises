#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int nums,num1,num2,num3;
    double sum;
    cin >> nums;
    for (int i=0;i<nums;i++) {
        cin >> num1 >> num2 >> num3;
        sum+=cbrt(num1*num2*num3);
    }
    cout << sum << endl;
    cout << (sum==0? "YES":"NO") << '\n';
}