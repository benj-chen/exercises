#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
vector<string> vs;
int st, nd; // nd exclusive
bool type;
bool decide(int a, int b) {
    if (type) return a <= b; // co2
    return a > b;
}
void process(int bit) {
    if (st + 1 == nd) return;
    // note when the bit changes
    int change = -1;
    for (int i = st; i < nd; i++) {
        if (vs[i][bit] == '1') {
            change = i;
            break;
        }
    }
    if (decide(change - st, nd - change)) nd = change;
    else st = change;
    process(bit + 1);
}
int main() {
    string in;
    while (cin >> in) vs.push_back(in);
    sort(vs.begin(), vs.end());
    st = 0;
    nd = vs.size();
    type = 0;
    process(0);
    int o2 = 0, co2 = 0;
    for (char c: vs[st]) {
        o2 <<= 1;
        if (c == '1') o2++;
    }
    st = 0;
    nd = vs.size();
    type = 1;
    process(0);
    for (char c: vs[st]) {
        co2 <<= 1;
        if (c == '1') co2++;
    }
    cout << o2 * co2 << endl;
}