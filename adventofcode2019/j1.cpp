#include<cmath>
#include<fstream>
#include<iostream>
#include<vector>
#include<utility>
#include<set>
#define f first
#define s second
using namespace std;
using p = pair<int,int>;

int main(int argc, char** argv) {
    vector<p> v; // coordinates
    ifstream cin(argv[1]);
    string s;
    int y=0;
    while (getline(cin,s)){for (int i=0;i<s.size();i++)
        if (s[i]=='#')
            v.push_back({i,y});
        y++;
    }
    int best = 0;

    for (p ast: v) {
        set<p> angles; // 2 32-bit numbers: to access first, use shift
        for (p every: v) {
            int num1 = ast.f - every.f,
            num2 = ast.s - every.s,
            lcm = 1;
            if (num1==0) {
                // x doesn't change: up/down
                if (num2==0); // every and ast are the same
                else if (num2 > 0) angles.insert({0,1}); // ast is below
                else angles.insert({0,-1}); // ast is above
                continue;
            }
            if (num2==0) {
                // left/right
                if (num1 > 0) angles.insert({1,0});// ast is right
                else angles.insert({-1,0});// left
                continue;
            }
            num1 = abs(num1); num2 = abs(num2);
            int min = (num1<num2? num1:num2);
            start:;
            
            for (int i=2;i<=min;i++) {
                if (!(num1%i) and !(num2%i)) {
                    lcm*=i;
                    num1/=i;
                    num2/=i;
                    goto start;
                }
            }
            angles.insert({(ast.f-every.f)/lcm,(ast.s-every.s)/lcm});
        }
        best = (best>angles.size()? best: angles.size());
    }
    cout << best << endl;
}