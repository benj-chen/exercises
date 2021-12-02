#include <string>
#include <fstream>
using namespace std;
string s;
int k;
int ct(string targ, int tlen) {
    int count=0;
    for (int letter=0;letter<k;letter++) {
        if (s.substr(letter,tlen)==targ) count++;
    }
    return count;
}
int main() {
    ifstream cin("whereami.in");
    ofstream cout("whereami.out");
    cin >> k >> s;
    for (int x=1;x<k+2;x++) {
        bool is1=true;
        for (int y=0;y<k-x;y++) {
            if (ct(s.substr(y,x),x)!=1) {
                is1=false;
                break;
            }
        }
        if (is1) {
            cout << x << endl;
            return 0;
        }
    }
    return -1;

}