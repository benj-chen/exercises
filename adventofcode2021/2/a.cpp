#include <iostream>
using namespace std;
int main() {
    string s;
    int in,x=0,y=0;
    while (cin>>s>>in) {
        if (s=="forward")
            x+=in;
        else if (s=="down")
            y+=in;
        else if (s=="up")
            y-=in;
    }
    cout << x*y << endl;
}