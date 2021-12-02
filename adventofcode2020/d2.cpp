// with O2 optimization flag, exec time is 0.005s
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ifstream in("i2");
    vector<int> st,end;
    vector<char> aim;
    vector<string> targ;
    string raw_input;
    int ind=0, cta=0, ctb=0;;
    while (getline(in,raw_input)) {
        int indst=raw_input.find('-'),
            indsp=raw_input.find(' '),
            indtarg=raw_input.find(": ");
        st.push_back(stoi(raw_input.substr(0,indst)));
        end.push_back(stoi(raw_input.substr(indst+1,indsp)));
        aim.push_back(raw_input[indsp+1]);
        targ.push_back(raw_input.substr(indtarg+2,raw_input.length()));
        ind++;
    }
    in.close();
    while (ind--) {

        int& a1=st[ind],a2=end[ind];
        char& b=aim[ind];
        string& c = targ[ind];
        int bcount=count(c.begin(),c.end(),b); // include algorithm
        if (bcount >=a1 && bcount <=a2) cta++; // for part 1

        if ((c[a1-1]==b)!=(c[a2-1]==b)) // bitwise xor essentially
         ctb++; // for part 2
    }
    // part 1 answer 434, part 2 answer 509
    cout << cta << '\n' << ctb << '\n';
}