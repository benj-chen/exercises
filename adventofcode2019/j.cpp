// both part 1 and 2
#include<cmath> // abs
#include<queue>
#include<map>
#include<fstream> // ifstream
#include<iostream>// cout
#include<vector>
#include<utility> // pair
#include<set>
#include<algorithm> // sort
#define f first
#define s second
using namespace std;
using p = pair<int,int>;
using angle = p; // for clarity

bool ang(angle a, angle b) {
    int quad1 = -1, quad2 = -1;// even: quadrant. odd: on the side
    //      1
    //   8  |  2
    // 7____|____3
    //      |  
    //   6  | 4
    //      5
    auto edgecase = [](angle i)->int { // cool new lambda tech: avoid repetition
        switch(i.f) {
            case 0: return(i.s == 1? 5: 1);
            case 1: return 3;
            case -1:return 7;
            default:
            return -2;
        }
    };
    auto normal = [](angle i)->int {
        if (i.f <0) return (i.s<0? 8:6);
        else return (i.s<0? 2:4);
    };
    if (a.f and a.s)
        // in a quadrant
        quad1 = normal(a);
    else
        // has 0
        quad1 = edgecase(a);
    if (b.f and b.s)
        // in a quadrant
        quad2 = normal(b);
    else
        // has 0
        quad2 = edgecase(b);
    if (quad1==quad2) {
        // same quadrant
        // assume even
        if (quad1 % 2)
            return -1;
        return
        (a.s / (double)a.f)<
        (b.s / (double)b.f);
    }
    else return (quad1<quad2);
}

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
    int x = s.size();
    int best = 0;
    set<p> b_angles;
    p b_loc;
    for (p ast: v) {
        set<angle> angles;
        for (p every: v) {
            int num1 = every.f - ast.f,
            num2 = every.s - ast.s,
            lcm = 1;
            // 0,0 is top left
            if (num1==0) {
                // x doesn't change: up/down
                if (num2==0); // every and ast are the same: prevents 0,0 from happening
                else if (num2 > 0) angles.insert({0,-1}); // ast needs to subtrat y to get to every
                else angles.insert({0,1}); // ast is below
                continue;
            }
            if (num2==0) {
                // left/right
                if (num1 > 0) angles.insert({-1,0});// ast needs to subtract from x to get to every
                else angles.insert({1,0});// right
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
            angles.insert({(every.f-ast.f)/lcm,(every.s-ast.s)/lcm});
        }
        if (angles.size()>best) {
            best = angles.size();
            b_angles.clear();
            for (auto a: angles) b_angles.insert(a);
            b_loc.f = ast.f; b_loc.s = ast.s;
        }
    }
    cout << best << endl;
    map<angle,queue<p>> lines;
    for (angle i: b_angles) {
        p station = b_loc; // subway: stop at multiples
        while (0 <= station.f and station.f <= x and 0<=station.s and station.s <= y) {
            station.f += i.f;
            station.s += i.s;
            if (count(v.begin(),v.end(),station)) {
                lines[i].push(station);
            }
        }
    }
    vector<angle> angles(b_angles.begin(),b_angles.end());
    sort(angles.begin(),angles.end(),ang);
    int cur = -1;
    int res;
    for (int i=0;i<200;i++) {
        while (lines[angles[(++cur)%angles.size()]].empty());
        res = lines[angles[cur%angles.size()]].front().f * 100 + lines[angles[cur%angles.size()]].front().s;
        lines[angles[cur%angles.size()]].pop();
    }
    cout << res << endl;
}