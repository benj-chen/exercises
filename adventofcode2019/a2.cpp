#include<iostream>
#include<fstream>
using namespace std;
int main(int argc, char** argv) {
    ifstream cin(argv[1]);
    int i, sum = 0;
    while (cin>>i) {
        sum -= i;
        while (i>0) {
            sum+=i;
            i = i/3-2;
        }
    }
    cout << sum << endl;
}