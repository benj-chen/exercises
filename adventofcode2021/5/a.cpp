#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
using vi = vector<int>;
int main() {
    int x,x2,y,y2, ct = 0;
    vector<vi> graph;
    while (cin>>x) {cin.ignore(); cin>>y; cin.ignore(4); cin>>x2; cin.ignore(); cin>>y2; // get input, not very interesting
        int dx = (x<x2) - (x>x2),
        dy = (y<y2) - (y>y2);
        if (!dx || !dy) {
            int xm = fmax(x,x2), ym = fmax(y,y2);
            if (graph.size()<=ym) graph.resize(ym+1);
            int diff = fmax(dx * (x2-x), dy * (y2-y))+1;
            for (int i=0;i<diff;i++){
                if (graph[y].size() <= xm) graph[y].resize(xm+1);
                graph[y][x]++;
                y+=dy;
                x+=dx;
            }
        }
    }
    for (vi& v: graph) for (int i: v) if (i>1) ct++;
    cout << ct << endl;
}