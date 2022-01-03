#include <iostream>
#include <vector>
#include <array>
#include <set>
#include <string>
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
    cin >> in;
    while (cin>>in) {
        int n = stoi(in.substr(2));
        bool y = in[0]=='y'; // for each point, retrieve y or x value?
        for (auto& a: graph)
            if (a[y]>n)
                a[y] = n+n-a[y];
        cin >> in >> in;
    }
    int mx=graph[0][1], my = graph[0][0];
    for (auto& a: graph) {
        if (a[0] > my) my = a[0];
        if (a[1] > mx) mx = a[1];
    }
    my++;mx++;
    bool visual[my][mx] = {};
    for (auto& a: graph) {
        visual[a[0]][a[1]] = 1;
    }
    for (int j=0;j<mx;j++){ for (int i=0;i<my;i++) cout << (visual[i][j]? "*": " ") << " "; cout<<endl;}
}