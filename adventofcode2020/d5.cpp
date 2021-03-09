// with O2 optimization flag, exec time is 0.004s.
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int main() {
    ifstream in("i5");
    string line;
    int best=0,llim,ulim;
    vector<int> part2;
    while (in >> line) {
        llim=0;
        ulim=127;
        for (char c: line.substr(0,7)) {
            if (c=='F') ulim-=((ulim-llim)/2+(ulim-llim)%2);
            else llim+=((ulim-llim)/2+(ulim-llim)%2);
        }
        int lflim=0, rlim=7,score;
        // ulim and llim are the same, lflim and rlim are the same. No need for row and col variables.
        for (char c: line.substr(7,10)) {
            if (c=='L') rlim-=(rlim-lflim)/2+(rlim-lflim)%2;
            else lflim+=(rlim-lflim)/2+(rlim-lflim)%2;
        }
        
        score=ulim*8+rlim;
        part2.push_back(score);
        if (score>best) best=score;
    }
    // part 1 answer 896
    cout << best << '\n';
    sort(part2.begin(),part2.end());
    for (int i=part2[0];i<part2[part2.size()-1];i++) {
        if (count(part2.begin(),part2.end(),i-1)>0 &&
        count(part2.begin(),part2.end(),i+1)>0 &&
        count(part2.begin(),part2.end(),i)==0) {
            // part 2 answer 659
            cout << i << '\n';
            return 0;
        }
    }
    cout << "invalid\n";
    return 1;
}