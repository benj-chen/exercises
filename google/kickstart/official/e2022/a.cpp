// a
#include<bits/stdc++.h>
#define f(j) for (int i=0;i<j;i++)
using namespace std;
using vi = vector<int>;
using pii = pair<int,int>;
template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& v){out<<'{';if(!v.empty())out<<v.front();for(int i=1;i<v.size();i++)out<<' '<<v[i];out<<'}';return out;}

template<typename T, typename U>
ostream& operator<<(ostream& out, const pair<T,U> p){out << '(' << p.first << ","<<p.second<<')';return out;}

// int main(int argc, char** argv) {ifstream cin(argv[1]);
int main() {
int T;cin>>T;T++;for(int t=1;t<T;t++) {
    // urinal stall
    int n; cin >> n;
    cout << "Case #" << t << ": " << (n+4)/5 << endl;
}}