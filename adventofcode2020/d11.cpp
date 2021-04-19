#include <utility>
#include <vector>
#include <fstream>
#include <iostream>
#define f first
#define s second
using namespace std;
using pii = pair<pair<int,int>,char>;
vector<string> inputs;
int input_len, input_width;
void get_input() {
    ifstream input("i11");
    string raw_input;
    while (input >> raw_input) inputs.push_back(raw_input);
    input_len = inputs.size();
    input_width = inputs[0].length();
}
void solve1() {
    vector<pii> change(1);
    while (!change.empty()) {
        change.resize(0);
        for (int i=0;i<input_len;i++) for (int j=0;j<input_width;j++) {
            int ct = 0;
            for (int a=i-1;a<i+2;a++) for (int b=j-1;b<j+2;b++) if ((a!=i||b!=j) && a>-1 && a<input_len && b>-1 && b<input_width
                && inputs[a][b]=='#') {
                ct++; // occupied adj seat
            }
            if (inputs[i][j]=='L') {
                if (!ct/*ct==0*/) change.push_back(make_pair(make_pair(i,j),'#')); // change to
            }
            else if (inputs[i][j]=='#') {
                if (ct>3) change.push_back(make_pair(make_pair(i,j),'L'));
            }
        }
        for (pii p: change) {
            inputs[p.f.f][p.f.s]=p.s;
        }
    }
    int ct = 0;
    for (string s: inputs) for (char c: s) if (c=='#') ct++;
    // part 1 answer 2275
    cout << ct << endl;
}

void solve2() {
    vector<pii> change(1);
    while (!change.empty()) {
        change.resize(0);
        for (int i=0;i<input_len;i++) for (int j=0;j<input_width;j++) {
            int ct = 0;
            for (int a=-1;a<2;a++) for (int b=-1;b<2;b++) if (a||b) {
                // check each thing that's a x-units away and b y-units away
                int mult = 1;
                int newx = i+(mult*a), newy = j+(mult*b);
                while (newx>-1 && newx<input_len && newy>-1 && newy<input_width) {
                    if (inputs[newx][newy]=='.') {
                        mult++;
                        newx=i+(mult*a);newy=j+(mult*b);
                    }
                    else {
                        if (inputs[newx][newy]=='#') ct++;
                        break;
                    }
                }
            }
            if (inputs[i][j]=='L') {
                if (!ct/*ct==0*/) {
                    change.push_back(make_pair(make_pair(i,j),'#'));
                }
            }
            else if (inputs[i][j]=='#') {
                if (ct>4) {
                    change.push_back(make_pair(make_pair(i,j),'L'));
                }
            }
        }
        for (pii p: change) {
            inputs[p.f.f][p.f.s]=p.s;
        }
    }
    int ct = 0;
    for (string s: inputs) for (char c: s) if (c=='#') ct++;
    // part 2 answer 2121
    cout << ct << endl;
}
int main() {
    get_input();
    solve1();
    inputs = {}; get_input(); // the input was modified
    solve2();
}