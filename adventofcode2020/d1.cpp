#include <fstream>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
    ifstream inp("i1");
    vector<int> inputs;
    string str;
    while (getline(inp,str)) inputs.push_back(stoi(str));
    inp.close();
    int p1=0;
    int p2=0;
    for (int &i: inputs) {
        for (int &j: inputs) {
            for (int &k: inputs) {
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