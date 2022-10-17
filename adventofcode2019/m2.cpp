#include<vector>
#include<cmath>
#include <assert.h>
#include<map>
#include<iostream>
#include<fstream>
using namespace std;
using ll = long long;
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
ll loc2(int mode, ll num) {
switch(mode) {
    case 0: case 1: return num;
    case 2: return relative+num;
}
return -1;
}

vector<int> cache;
vector<vector<int>> locs;
vector<string> board;
int maxx,maxy;
int main(int argc, char** argv){
    ifstream fin("in");
    string intcode;
    getline(fin,intcode);

    v = split_delimiter_char(intcode,',');
    vector<int> output;
    int ct;
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
                cout << "expecting input (the board looks like this): ";
                maxx = 0, maxy = 0;
                for (auto a:locs) {
                    maxx = fmax(maxx,a[0]);
                    maxy = fmax(maxy,a[1]);
                }
                board.clear();
                board.resize(maxx+1);
                for (auto& a: board) a = string(maxy+1,' ');
                for (auto a: board) cout << a << endl;
                for (auto a: locs) {
                    cout << a[0] << " " << a[1] << " " << a[2] <<endl;
                    if (a[0]==-1 and a[1]==0) cout << "Score: " << a[2] << endl;
                    else board[a[0]][a[1]] = '0'+a[2];
                }
                for (auto a: board) cout << a << endl;
                cin >> v[loc2(mode[0],v[i+1])];
                locs.clear();
            break;
            case 4:
                cache.push_back(loc(mode[0],v[i+1]));
                if (cache.size()==2) {
                    locs.push_back(cache);
                    cache.clear();
                }
            break;
            case 99:
                // ct=0;
                // for (int j=2;j<output.size();j+=3) {
                //     if (output[j]==2) ct++;
                // }
                // cout << ct << endl;
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