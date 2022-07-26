#include <iostream>
#include <map>
#include <vector>
#include <fstream>
using namespace std;
//fuck the windows clipboard, I spent over two hours figuring out why the
// thing wasn't working only to find that the string was 15000 chars instead
// of 4096
// maybe it's the terminal, either way I wasted so much time of my life over this
int main() {
    ifstream fin("in");
    string s;
    fin >> s;
    cout << s.size() << endl;
    int l = 25, w = 6;
    vector<char> res(l*w);
    for (int i=0;i<l*w;i++) {
        bool act = 0;
        for (int j=i;j<s.size();j+=l*w) {
            if (s[j]!='2') {
                res[i]=s[j];
                act=1;
                cout << s[j];
                break;
            }
        }
        if (!act){ cout << "!act" << endl; res[i] = '2';}
    }
    cout << endl << res.size() << endl;
    for (char i: res) cout << i;
    cout << endl;
    map<char,char> pix {
        {'0', ' '},
        {'1', '#'},
        {'2', ' '}
    };
    for (int i=0;i<w;i++) {
        for (int j=0;j<l;j++) {
            cout << pix[res[i*l+j]];
        }
        cout << endl;
    }
}