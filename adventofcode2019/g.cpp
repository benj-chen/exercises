#include<vector>
#include<cmath>
#include<stack>
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
vector<int> code;
int loc(bool is_immediate, int num) {

    if (is_immediate) {
        return num;
    }
    return code[num];
}
int ret_intcode(int input1, int input2) {
    bool called = false;
    // using reference, clear the stack for next round
    for (int i=0;i<code.size();) {
        // opcode processing
        int cmd = code[i];
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
                code[code[i+3]] = loc(mode[0],code[i+1]) + loc(mode[1],code[i+2]);
            break;
            case 2:
                code[code[i+3]] = loc(mode[0],code[i+1]) * loc(mode[1],code[i+2]);
            break;
            case 3:
                code[code[i+1]] = (called? input2: input1);
                called = true;
            break;
            case 4:
                return loc(mode[0],code[i+1]);
            break;
            case 99:
                return 0;
            case 5:
                if (loc(mode[0],code[i+1]) != 0) {
                    i = loc(mode[1],code[i+2]);
                    no_change = false;
                }
            break;
            case 6:
                if (loc(mode[0],code[i+1]) == 0) {
                    i = loc(mode[1],code[i+2]);
                    no_change = false;
                }
            break;
            case 7:
                code[code[i+3]] = ((loc(mode[0],code[i+1]) < loc(mode[1],code[i+2])));
            break;
            case 8:
                code[code[i+3]] = ((loc(mode[0],code[i+1]) == loc(mode[1],code[i+2])));
        }
        if (no_change) i+=p_szs[opcode]+1;
    }
    throw exception();
}
vector<vector<int>> all_perms_unsorted(vector<int> l) {
    if (l.empty()) return {{}};
    vector<vector<int>> res;
    for (int i=0;i<l.size();i++) {
        int add_back=l[i];
        l.erase(l.begin()+i);
        for(vector<int> y: all_perms_unsorted(l)) {
            y.push_back(add_back);
            res.push_back(y);
        }
        l.insert(l.begin()+i,add_back);
    }
    return res;
}
int main(){

    
    string intcode;
    getline(cin,intcode);

    code = split_delimiter_char(intcode,',');
    vector<int> v = code;
    int input = 0;
    int max = 0;
    for (vector<int> i: all_perms_unsorted({0,1,2,3,4})) {
        for (int j=0;j<5;j++) {
            input = ret_intcode(i[j],input);
            code = v;
        }
        cout << input << endl;
        max = fmax(max,input);
        input = 0;
    }
    cout << max << endl;
}