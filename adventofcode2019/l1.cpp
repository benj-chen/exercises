#include<iostream>
#include<fstream>
#include<array>
#include<vector>
#define p first
#define v second
using namespace std;
using pos = array<int,3>;
using vel = pos;
using moon = pair<pos,vel>;
vector<moon> moons(4);


// print arrays
std::ostream& operator<<(std::ostream& out, const std::array<int,3>& v){if(!v.empty())out<<"["<<v[0];for(int i=1;i<3;i++)out<<','<<v[i];out<<"]";return out;}

// print pairs
template <typename T,typename Y>
std::ostream& operator<<(std::ostream& out, const std::pair<T,Y>& v){out<< v.first << ":" << v.second;return out;}

// print vectors
template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& v){if(!v.empty())out<<"{"<<v.front();for(int i=1;i<v.size();i++)out<<' '<<v[i];out<<"}";return out;}
void advance() {

}
vector<string> split_delimiter_char(string s, char delim) {
    vector<string> res(1);
    for (char c: s) {
        if (c==delim) res.push_back("");
        else res.back()+=c;
    }
    return res;
}

void step() {
    for (moon& i: moons) {
        for (moon& j: moons) { if (i!=j)
            for (int k=0;k<3;k++) {
                int change = (i.p[k]-j.p[k]); // negative: j is bigger, j--, i++
                                              // positive: j is smaller, j++, i--
                if (change){
                change /= abs(change);
                i.v[k] -= change;
                }
            }
        }
    }
    for (moon& i: moons)
        for (int j=0;j<3;j++)
            i.p[j] += i.v[j];
}

int main(int argc, char** argv) {
    ifstream cin(argv[1]);
    string s;
    for (int i=0;i<4;i++) {
        getline(cin,s);
        vector<string> split = split_delimiter_char(s,',');
        for (int j=0;j<3;j++) {
            s = split_delimiter_char(split[j],'=')[1];
            if (s.back()=='>') s.pop_back();
            moons[i].p[j] = stoi(s);
            moons[i].v[j] = 0;
        }
    }
    // vector<moon> initial
    for (int i=0;i<10;i++) {
        step();
        cout << moons << endl;
    }
    int total = 0, sub1 = 0, sub2 = 0;
    for (moon i: moons) {
        for (int j: i.v) {
            sub1+=abs(j);
        }
        for (int j: i.p) {
            sub2+=abs(j);
        }
        total += sub1*sub2;
        sub1 = 0; sub2 = 0;
    }
    cout << total << endl;
}
// matlab?