// with O2 optimization flag, exec time is 0.004s.
#include <string>
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;
using st = string;

int main() {
    ifstream in("i8");
    st raw_input1,raw_input2;
    vector<bool> vis; // visited
    vector<int> vals, type;// type of command: true if it's acc
    while (in >> raw_input1 >> raw_input2) {
        vis.push_back(0);
        type.push_back(
            (raw_input1=="nop"? 1 : (raw_input1=="jmp" ? 0 : 2)) // jmp is 0, nop is 1, acc is 2
        );
        vals.push_back(stoi(raw_input2)); // stoi accepts signs (+ and -) and converts to ints as needed. neat!
    }
    in.close();
    int acc=0//Some lines in the code add or subtract from the accumulator
    ,cmd=0; //The index number of the current thing to be looked at
    while (1) {
        if (vis[cmd]) {
            // part 1 answer 2034
            cout << acc << '\n';
            break;
        }
        vis[cmd]=1;
        if (type[cmd]==2)acc+=vals[cmd];
        else if (!type[cmd])
            cmd+=vals[cmd]-1; // offset the ++ statement
        cmd++;
    }
    int len=vis.size();
    for (int i=0;i<len;i++) {
        for (int j=0;j<len;j++)vis[j]=0;

        acc=0;cmd=0;
        if (type[i]==2) continue; // not interested in acc
        type[i]=!type[i]; // switch from jmp to nop or vc versa
        while(1) {
            if (cmd==len) {
                cout << acc << '\n';
                return 0;
            }
            if (vis[cmd]) break;
            vis[cmd]=1;
            if (type[cmd]==2)
                acc+=vals[cmd];
            else if (!type[cmd]) // jump
                cmd+=vals[cmd]-1;
            cmd++;
        }
        type[i]=!type[i];
    }

}
