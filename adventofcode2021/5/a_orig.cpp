#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
using vi = vector<int>;
int main() {
    string a,b;
    int x1,x2,y1,y2, ct = 0;
    vector<vi> graph;
    while (cin>>x1) { cin.ignore(); cin>>y1; cin.ignore(4); cin>>x2; cin.ignore(); cin>>y2; // get input, not very interesting
        int xm = fmax(x1,x2), ym = fmax(y1,y2);
        if (x1==x2) {
            if (graph.size() <= ym) {
                graph.resize(ym+1);
            }
            for (int i=fmin(y1,y2)/*only calculated once*/;i<=ym;i++) {
                if (graph[i].size() <= xm) {
                    graph[i].resize(xm+1);
                }
                graph[i][x1]++;
            }
        }
        else if (y1==y2) {
            if (graph.size() <= y1) graph.resize(y1+1);
            if (graph[y1].size() <= xm) graph[y1].resize(xm+1);
            for (int i=fmin(x1,x2);i<=xm;i++) {
                graph[y1][i]++;
            }
        }
    }
    for (vi& v: graph) for (int i: v) if (i>1) ct++;
    cout << ct << endl;
}