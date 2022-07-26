#include<iostream>
using namespace std;
int main() {
    string s;
    cin >> s;
    int min0 = 1e9, score = -1;
    for (int i=0;i<s.size();i+=25*6) {
        int c0 = 0, c1 = 0, c2 = 0;
        for (int j=0;j<25*6;j++) {
            switch(s[i+j]) {
                case '0': c0++; break;
                case '1': c1++; break;
                case '2': c2++; break;
            }
        }
        if (c0 < min0) {
            min0=c0;
            score = c1 * c2;
        }
    }
    cout << score << endl;
}