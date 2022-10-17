
#include<iostream>
#include<algorithm>
#include<fstream>
#include<array>
#include<vector>
#include<set>
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
vector<string> split_delimiter_char(string s, char delim) {
    vector<string> res(1);
    for (char c: s) {
        if (c==delim) res.push_back("");
        else res.back()+=c;
    }
    return res;
}
int get(int typ) { // 0 for x, 1 for y, 2 for z
    vector<pair<int,int>> just1;
    set<vector<pair<int,int>>> all;
    for (moon i: moons) {
        just1.push_back({i.p[typ],i.v[typ]}); // 0 for x, 1 for y, 2 for z
    }

    for (int t=0;true;t++) {
        // find repeats
        if (count(all.begin(),all.end(),just1)) {
            cout << "repeat found at step " << t << ": " << just1 << endl;
            return t;
            break;
        }
        else all.insert(just1);
        // upd velocity
        for (int i=0;i<3;i++) for (int j=i+1;j<4;j++) {
            if (just1[i].first<just1[j].first) {
                just1[i].second++;
                just1[j].second--;
            }
            if (just1[i].first>just1[j].first) {
                just1[i].second--;
                just1[j].second++;
            }
        }
        // move
        for (int j=0;j<4;j++){ 
            just1[j].first+=just1[j].second;
        }

    }
}
using vi = vector<int>;
vi sieve(int q) {
    // find all unique prime numbers under the int q, has to be in int range because vectors can't hold that large
    vector<bool> prime;
    prime.resize(q+3);
    for (int i=2;i<q;i++) {
        prime[i]=1;
    }
    vi res;
    for (int i=2;i<q;i++) {
        if (prime[i]) {
            // start from i*i
            for (int j=i;j<q;j+=i) prime[j]=0; // int max * int max obviously goes over int range, this can be solved by resizing the vector but that's sorta pointless
            res.push_back(i);
        }
    }
    return res;
}
vi prime_factors(int q) {
    // import sieve with this
    vi f = sieve(q);
    vi res;
    start:;
    for (int i: f) {
        if (!(q%i)) {
            q/=i;
            res.push_back(i);
            goto start;
        }
    }
    return res;
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


    int x = get(0), y = get(1), z = get(2);
    cout << x << " " << y << " " << z << endl;
    vi px = prime_factors(x), py = prime_factors(y), pz = prime_factors(z);
    
    // lcm
    set<int> factors;
    for (int i: px) factors.insert(i);
    for (int i: py) factors.insert(i);
    for (int i: pz) factors.insert(i);
    long long res = 1;
    for (int i: factors) res*=i;
    cout << res << endl;
    /*
    // indiv
    vector<pair<int,int>> just1;
    set<vector<pair<int,int>>> all;
    for (moon i: moons) {
        just1.push_back({i.p[0],i.v[0]}); // 0 for x, 1 for y, 2 for z
    }

    for (int t=0;true;t++) {
        // find repeats
        if (count(all.begin(),all.end(),just1)) {
            cout << "repeat found at step " << t << ": " << just1 << endl;
            break;
        }
        else all.insert(just1);
        // upd velocity
        for (int i=0;i<3;i++) for (int j=i+1;j<4;j++) {
            if (just1[i].first<just1[j].first) {
                just1[i].second++;
                just1[j].second--;
            }
            if (just1[i].first>just1[j].first) {
                just1[i].second--;
                just1[j].second++;
            }
        }
        // move
        for (int j=0;j<4;j++){ 
            just1[j].first+=just1[j].second;
        }

    }
    */
    /* every (slow)
    set<vector<moon>> all;
    for (int i=0;i<3000;i++) {
        step();
        cout << moons << endl;
        if (count(all.begin(),all.end(),moons)){ 
            cout << i << endl;
            return 0;
        }
        else {
            all.insert(moons);
        }
    }
    */
}