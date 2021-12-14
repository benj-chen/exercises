#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<long long> fish(9);
    int i;
    while (cin >> i) {
        cin.ignore(); // comma
        fish[i]++;
    }
    for (int i=0;i<80;i++)
        fish[(i+7)%9]+=fish[i%9];
    long long ct = 0;
    for (long long i: fish) {
        ct+=i;
    }
    cout << ct << endl;
}