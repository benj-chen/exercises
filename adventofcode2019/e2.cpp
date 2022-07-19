#include<vector>
#include<map>
#include<iostream>
using namespace std;

vector<int> split_delimiter_char(string s, char delim) {
    vector<int> res;
    string temp;
    for (char c: s) {
        if (c==delim) {
            res.push_back(stoi(temp));
            temp = "";
        }
        else temp+=c;
    }
    if (temp!="") res.push_back(stoi(temp));
    return res;
}
map<int,int> p_szs {
    {1,3},
    {2,3},
    {99,0},
    {3,1},
    {4,1},
    {5,2},
    {6,2},
    {7,3},
    {8,3}
};
vector<int> v;
int loc(bool is_immediate, int num) {

    if (is_immediate) {
        return num;
    }
    return v[num];
}
int main(){
    
    string intcode;
    getline(cin,intcode);

    v = split_delimiter_char(intcode,',');
    for (int i=0;i<v.size();) {
        // opcode processing
        int cmd = v[i];
        int opcode = cmd % 100; cmd /= 100;
        vector<bool> mode;
        while (cmd) {
            bool b = cmd % 10;
            cmd /= 10;
            mode.push_back(b);
        }
        mode.resize(p_szs[opcode]);
        bool no_change = true;
        switch(opcode) {
            case 1:
                v[v[i+3]] = loc(mode[0],v[i+1]) + loc(mode[1],v[i+2]);
            break;
            case 2:
                v[v[i+3]] = loc(mode[0],v[i+1]) * loc(mode[1],v[i+2]);
            break;
            case 3:
                cout << "expecting input: ";
                cin >> v[v[i+1]];
            break;
            case 4:
                cout << "output: " << loc(mode[0],v[i+1])<< endl;
            break;
            case 99:
                cout << "done" << endl;
            return 0;
            case 5:
                if (loc(mode[0],v[i+1]) != 0) {
                    i = loc(mode[1],v[i+2]);
                    no_change = false;
                }
            break;
            case 6:
                if (loc(mode[0],v[i+1]) == 0) {
                    i = loc(mode[1],v[i+2]);
                    no_change = false;
                }
            break;
            case 7:
                v[v[i+3]] = ((loc(mode[0],v[i+1]) < loc(mode[1],v[i+2])));
            break;
            case 8:
                v[v[i+3]] = ((loc(mode[0],v[i+1]) == loc(mode[1],v[i+2])));
        }
        if (no_change) i+=p_szs[opcode]+1;
    }
}