#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
struct Cow {
    bool dir;
    int x,y,u=1000000000;

    Cow(char diri, int xi, int yi)
    {
        dir=(diri=='E');
        x=xi;
        y=yi;
    }
    void move(const Cow& ocow)
    {
        if (x==ocow.x && y==ocow.y) return;
        if (dir==ocow.dir)
        {
            if (x==ocow.x && y<ocow.y) u=fmin(u,y-ocow.y);
            else if (y==ocow.y && x<ocow.x) u=fmin(u,x-ocow.x);
            return;
        }
        if (dir)
        {
            if (ocow.x < x || ocow.x>x+u ||
            y < ocow.y || y>ocow.y+ocow.u)
                return;
        }
        else
        {
            if ((ocow.y < y || ocow.y>y+u) ||
            (x < ocow.x || x>ocow.x+ocow.u))
                return;
        }
        int xd = abs(x-ocow.x);
        int yd = abs(y-ocow.y);
        vector<int> dord(2);
        if (dir)
        {
            dord[0]=xd;
            dord[1]=yd;
        }
        else
        {
            dord[0]=yd;
            dord[1]=xd;
        }
        if (dord[0]>dord[1]) u=fmin(u,dord[0]);
    }
};
bool isIn(vector<Cow> &c, Cow &target)
{
    for (Cow &i: c)
    {
        if (i.x==target.x && i.y==target.y) return true;
    }
    return false;
}
void extractTrueU(Cow& cow, vector<Cow>& inf, vector<Cow> &cows)
{
    if (isIn(inf,cow)) return;
    vector<Cow> retTo;
    for (Cow &i: cows) {
        int prevu=cow.u;
        cow.move(i);
        if (cow.u!=prevu) {
            extractTrueU(i,inf,cows);
            retTo.push_back(i);
            cow.u=prevu;
        }
    }
    for (Cow &i: retTo) cow.move(i);
    if (cow.u==1000000000) inf.push_back(cow);
}
int main()
{
    int len;
    cin >> len;
    vector<Cow> cows;
    for (int i=0;i<len;i++) {
        char dir;
        int x,y;
        cin >> dir >> x >> y;
        cows.push_back(Cow(dir,x,y));
    }
    vector<Cow> inf;
    for (Cow &i: cows)
    {
        extractTrueU(i,inf,cows);
        if (i.u!=1000000000) cout << i.u;
        else cout << "Infinity";
        cout << endl;
    }
}