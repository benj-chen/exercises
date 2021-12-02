// with O2 optimization flag, exec time is 0.004s
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
using ul = unsigned long;
int main() {

    const short PALEN=25;
    ifstream in("i9");
    vector<ul> input(PALEN);
    ul raw_input,num; // my unsigned long range is 0 to 18446744073709551615 which is enough to hold
    // the bigger numbers in the input
    int ind=0;
    for (int i=0;i<PALEN;i++) in >> input[i];
    while (in >> raw_input) {
        for (int i=ind;i<PALEN+ind;i++)
            for (int j=ind;j<PALEN+ind;j++)
                if (i-j &&  // not the same spot
                    input[i]+input[j]==raw_input)
                    goto notok;
        num=raw_input;
        cout << num << endl;
        break;
        notok:;
        ind++;
        input.push_back(raw_input);
    }
    while (in >> raw_input) input.push_back(raw_input);
    for (ul st=0;st<input.size();st++) {
        ul sum=0;
        for (ind=st;sum<num;ind++) sum+=input[ind];
        if (sum==num) {
            ul min=-1,max=0; // implicit type conversion from -1 to the max
            for (ind--;ind>=st;ind--) {
                min=fmin(min,input[ind]);
                max=fmax(max,input[ind]);
            }
            cout << max+min << endl;
            return 0;
        }
    }
}