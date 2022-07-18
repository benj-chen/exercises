#include <iostream>
#include <vector>
#include <assert.h>
#include <map>
// previously did day 1 early
#include <fstream>
using namespace std;
ifstream fin("in");
using vs = vector<string>;
using vi = vector<int>;
vi split(string s, char delim) {
    vi ret(1);
    for (char c: s) {
        if (c==delim) ret.push_back(0);
        else if (c=='-')
            ret.push_back(-1);
        else if (ret.back()==-1) {
            ret.back() = '0'-c;
        }
        else if (ret.back()<0) {
            ret.back() = ret.back() * 10 + '0'-c;
        }
        else
        ret.back() = ret.back() * 10 + c-'0';
    }
    return ret;
}
vi in;
int get(bool typ, int num) {
    if (typ) {
        return num;
    }
    else return in[num];
}
int set(bool typ, int num) {
    // not necessary: set is always not immediate
    return -1;
}

int main() {
    string s; fin >> s;
    in = split(s,',');
    for (int i: in) cout << i << " "; cout << endl;
    map<int,int> amt_params = {
        {1,3},
        {2,3},
        {3,1},
        {4,1},
        {99,9}
    };
    for (int i=0;i<in.size();) {
        string inst = to_string(in[i]);
        int cmd = in[i] % 100;
        // cout << cmd << endl;
        vector<bool> types; // types[0] refers to the treatment of the first parameter
        for (int j=inst.size()-3;j>-1;j--) {
            types.push_back(inst[j]=='1');
        }
        assert (types.size() <= amt_params[cmd]);
        types.resize(amt_params[cmd]); // leading 0
        // for (bool j: types) cout << j; cout << endl;
        switch(cmd) {
            case 1:
            // cout << in[get(types[0],i+1)] << ' ' <<
// get(types[0],i+1) << ' ' <<
// in[get(types[1],i+2)] <<' ' <<
// get(types[1],i+2) << endl;
            in[get(types[2],i+3)] = in[get(types[0],i+1)] + in[get(types[1],i+2)] ;
            cout << get(types[2],i+3) << endl;
            break;
            case 2:

            in[get(types[2],i+3)] = in[get(types[0],i+1)] * in[get(types[1],i+2)];
            // cout << in[get(types[0],i+1)]  << " " << in[get(types[1],i+2)] << endl;;
            break;
            case 3:
            // input
            cout << "waiting for input: ";
            cin >> in[in[i+1]];
            break;
            case 4:
            cout << in[get(amt_params[0],i+1)] << endl;
            break;
            case 99:
            cout << "done" << endl;
            return 0;
        }
        i+=amt_params[cmd]+1;
    }
    for (int i: in) cout << i << " "; cout << endl;
}