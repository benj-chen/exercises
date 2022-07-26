// gotta change intcode to a class type

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

struct Intcode {
    vector<int> code;
    int i=0;
    int loc(bool is_immediate, int num) {
        
        if (is_immediate) {
            return num;
        }
        return code[num];
    }
    int wrapper(int input) {
        // for everything except the initial double input
        ret_intcode(input);
        return ret_intcode(-1);
    }
    int ret_intcode(int input) {
        
        // using reference, clear the stack for next round
        for (;i<code.size();) {
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
                    if (input==-1) cout << "problem" << endl;
                    code[code[i+1]] = input;
                    i+=2; // must be at end if possible
                    return -1;
                break;
                case 4:
                    i+=2;
                    return loc(mode[0],code[i-1]); // change because of i+=2
                break;
                case 99:
                    return -1;
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
    Intcode(vector<int> code): code(code) {
    }
};
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
int main() {
    string intcode;
    getline(cin,intcode);
    const vector<int> code = split_delimiter_char(intcode,',');
    int input=0;
    int max = 0;
    for (vector<int> a: all_perms_unsorted({5,6,7,8,9})) {

    
        int cycle=0;
        vector<Intcode> abcde;
        vector<int> outputs;
        for (int i=0;i<5;i++) {
            abcde.push_back(Intcode(code));
            outputs.push_back(abcde.back().ret_intcode(a[i]));
        }
        int last_e = -1;
        int input = 0;
        while (input != -1) {
            if (cycle%5 == 0) {
                last_e = input;
            }
            input = abcde[cycle%5].wrapper(input);
            cycle++;
        }
        max = fmax(max,last_e);
    }
    cout << max << endl;
}