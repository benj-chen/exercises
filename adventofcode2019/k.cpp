#include<iostream>
#include<fstream>
#include<utility>
#include<set>
#include<vector>
#include<assert.h>
#include<map>
#define f first
#define s second
using namespace std;
using ll = long long;
using coord = pair<ll,ll>;
map<ll,ll> split_delimiter_char(string s, char delim) {
    map<ll,ll> res;
    ll ct = 0;
    string temp;
    for (char c: s) {
        if (c==delim) {
            res[ct++]=stoll(temp);
            temp = "";
        }
        else temp+=c;
    }
    res[ct]=stoi(temp);
    return res;
}
map<ll,ll> p_szs {
    {1,3},
    {2,3},
    {99,0},
    {3,1},
    {4,1},
    {5,2},
    {6,2},
    {7,3},
    {8,3},
    {9,1} // new
};
int initsz_p = p_szs.size();
// vector<ll> v;
map<ll,ll> v; // new: large numbers
int relative = 0; // new
ll loc(int mode, ll num) { // new
    switch(mode) {
        case 0: return v[num];
        case 1: return num;
        case 2: return v[relative+num];
    }
    cout << "loc problem" << endl;
    return -1;
}
ll loc2(int mode, ll num) { // very new, a Reddit user pointed out the 203 error.
// found it after maybe 3 days.
switch(mode) {
    case 0: case 1: return num;
    case 2: return relative+num;
}
return -1;
}
int main(int argc, char** argv){
    ifstream cin(argv[1]);
    string intcode;
    getline(cin,intcode);
    int x=0,y=0, dir = 0,k;
    //   0
    // 3   1
    //   2
    v = split_delimiter_char(intcode,',');
    bool typ = 1;
    map<coord,bool> spots;
    set<coord> painted;
    for (ll i=0;;) { // new
        assert(initsz_p == p_szs.size());
        // opcode processing
        ll cmd = v[i];
        ll opcode = cmd % 100; cmd /= 100;
        vector<int> mode; // new
        for (int j=0;j<p_szs[opcode];j++) { // new, for security
            int b = cmd % 10; // new
            cmd /= 10;
            mode.push_back(b);
        }
        switch(opcode) {
            case 1:
                v[loc2(mode[2],v[i+3])] = loc(mode[0],v[i+1]) + loc(mode[1],v[i+2]);
            break;
            case 2:
                v[loc2(mode[2],v[i+3])] = loc(mode[0],v[i+1]) * loc(mode[1],v[i+2]);
            break;
            case 3:
                v[loc2(mode[0],v[i+1])] = spots[{x,y}];
            break;
            case 4:
                k = loc(mode[0],v[i+1]);
                // cout << "output: " << k << endl;
                // use set for count, map for access?
                if (typ) { // move, paint
                    spots[{x,y}] = k;
                    painted.insert({x,y});
                    cout << endl;
                }
                else { // rotate
                    if (k) dir = (dir+1)%4; // right
                    else dir = (dir+3)%4; // left
                    switch(dir) {
                        case 0:
                        y++;
                        break;
                        case 1:
                        x++;
                        break;
                        case 2:
                        y--;
                        break;
                        case 3:
                        x--;
                        break;
                    }
                }
                typ = not typ;
            break;
            case 99:
                cout << "done" << endl;
                cout << painted.size() << endl;
            return 0;
            case 5:
                if (loc(mode[0],v[i+1]) != 0)
                    i = loc(mode[1],v[i+2])-p_szs[opcode]-1;// offset for the addition at the end;
            break;
            case 6:
                if (loc(mode[0],v[i+1]) == 0)
                    i = loc(mode[1],v[i+2])-p_szs[opcode]-1; // offset for the addition at the end
            break;
            case 7:
                v[loc2(mode[2],v[i+3])] = ((loc(mode[0],v[i+1]) < loc(mode[1],v[i+2])));
            break;
            case 8:
                v[loc2(mode[2],v[i+3])] = ((loc(mode[0],v[i+1]) == loc(mode[1],v[i+2])));
            break;
            // new
            case 9:
                relative += loc(mode[0],v[i+1]);
            break;
            default:
                cout << "opcode was " << opcode << endl;
        }
        i+=p_szs[opcode]+1;
    }
}
// 2116 too low