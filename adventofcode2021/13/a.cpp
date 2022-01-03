#include <iostream>
#include <vector>
#include <set>
#include <array>
#include <string>
using namespace std;
using namespace std;
array<int,2> split_delimiter_char(string s, char delim) {
    array<int,2>  res;
    string cur_num="";
    for (char c: s) {
        if (c==delim) {res[0] = (stoi(cur_num)); cur_num = "";}
        else cur_num+=string(1,c);
    }
    if (cur_num!="") res[1] = stoi(cur_num);
    return res;
}
int main() {
    vector<array<int,2>> graph; // {y,x}
    string in;
    while (true) {
        cin>>in;
        if (in=="fold") break;
        graph.push_back(split_delimiter_char(in,','));
    }
    cin >> in >> in;
    int n = stoi(in.substr(2));
    bool y = in[0]=='y'; // for each point, retrieve y or x value?
    for (auto& a: graph) {
        if (a[y]>n) {
            a[y] = n+n-a[y];
        }
    }
    set<array<int,2>> s(graph.begin(),graph.end());
    cout << s.size() << endl;
}