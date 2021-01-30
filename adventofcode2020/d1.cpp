#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    ifstream inp("i1");
    vector<short> inputs; // short is fine because none of the numbers go over 4 digits.
    string str;
    while (getline(inp,str)) {
        inputs.push_back((short) stoi(str));
    }
    // since the max is 305274146 (673*673*674 because the most optimized volume
    // for l+w+h=x is such that l,w, and h are as close as possible. In other words,
    // a cube.)
    // can't use a short, which is only guaranteed to a number as big as 65535.
    int p1=0;
    int p2=0;
    for (short &i: inputs) {
        for (short &j: inputs) {
            for (short &k: inputs) {
                if (!p2 && i+j+k==2020) {
                    p2=i*j*k;
                    break;
                }
            }
            if (!p1 && i+j==2020) p1=i*j;
            if (p1 && p2) break;
        }
    }
    //part 1 answer 388075, part 2 answer 293450526
    cout << p1 << endl << p2 << endl;
}