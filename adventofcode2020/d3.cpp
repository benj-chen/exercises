// with O2 optimization flag, execution time is 0.005s
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<string> inputs;
int f(int r, int d) {
    int count=0,xinput=0,yinput=0;
    while (yinput<inputs.size()) {
        char pos=inputs[yinput][xinput%inputs[0].length()];
        if (pos=='#') count++;
        xinput+=r;
        yinput+=d;
    }
    return count;
}
int main() {
    ifstream in("i3");
    string raw_input;
    while (in >> raw_input) inputs.push_back(raw_input);
    // part 1 answer 257, part 2 answer 1744787392
    cout << f(3,1) << '\n' << f(1,1)*f(3,1)*f(5,1)*f(7,1)*f(1,2) << '\n';
}