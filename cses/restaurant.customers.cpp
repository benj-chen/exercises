#include <iostream>
#include <map>
using namespace std;

int gi() {
    int a;
    cin >> a;
    return a;
}
int main() {
    map<int,int> m;
    int n=gi();
    while (n--) {
        int st=gi(),num=gi();
        while (num-st++) m[st]++;
    }
    n=0;
    for (map<int,int>::iterator i=m.begin();i!=m.end();++i) {
        if (n<i->second) n=i->second;
    }
    cout << n;
    

}