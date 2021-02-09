#include <iostream>
#include <vector>
using namespace std;
int avg(const vector<int>& a)
{
    int sum=0;
    for (int x: a) sum+=x;
    double av=double(sum)/a.size();
    if (!(av-int(av))) return av;
    return -1;
}
vector<int> subvector(const vector<int>& vec, int st, int e)
{
    vector<int> res;
    for (st;st<e;st++) res.push_back(vec[st]);
    return res;
}
bool isIn(const vector<int>& vec, int target)
{
    for (int i: vec)
    {
        if (i==target) return true;
    }
    return false;
}
int main()
{
    int avgf;
    cin >> avgf;
    vector<int> inp(avgf);
    for (int i=0;i<avgf;i++) cin >> inp[i];
    for (int cur=0;cur<avgf-1;cur++) {
        for (int targ=cur+1;targ<inp.size();targ++) {
            vector<int> targs=subvector(inp,cur,targ+1);
            avgf+=isIn(targs,avg(targs));
        }
    }
    cout << avgf << endl;

}