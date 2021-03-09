// with O2 optimization flag, exec time is 0.266s. Almost twice as slow as the py version.

#include <map>
#include <vector>
#include <string>
#include <utility>
#include <iostream>
#include <fstream>
#include <set>


using namespace std;
using st=string;
set<st> res;
void addUniqueParents(map<st,map<st,int> >& dict,st targ) {
    // if the target has no parent, end recursion and return
    // shiny gold bags have other things due to the limitations of the problem part 2.
    if (dict[targ].count("none")) return;
    for (pair<st,map<st,int> > p: dict) {
        
        if (p.second.count(targ)) {
            res.insert(p.first);
            addUniqueParents(dict,p.first);   
        }
    }
}
int getNumBags(map<st,map<st,int> >& dict, st targ) {
    
    if (dict[targ].count("none")) return 1;
    int ct=1;
    for (pair<st,int> p: dict[targ]) {
        ct+=getNumBags(dict,p.first) * p.second;
    }
    return ct;
}
int main() {

    ifstream in("i7");
    st name,flush_input;
    map<st,map<st,int> > input;
    while(in >> name >> flush_input) {
        // revamping what comes from python becuase the formatting sucks
        // experiment between unsorted and sorted
        // by looking at the sample input, it seems like each bag name has two words to it.
        // custom input must contain bag names with two words to each.
        name+=" " + flush_input;
        in >> flush_input >> flush_input; // "bags contain"
        getline(in,flush_input); // x description bags with a space in front. avoid seg fault.

        vector<st> split_input;
        for (char c: flush_input.substr(0,flush_input.length())) {
            if (c==' ') split_input.push_back("");
            else split_input.back()+=st(1,c);
        }
        if (split_input.size()==3)
            // no other bags
            input[name]["none"]=0;
        else
        for (int i=0;i<split_input.size();i+=4) {
            input[name][split_input[i+1] + " " + split_input[i+2]]=stoi(split_input[i]);
        }
    }
    addUniqueParents(input,"shiny gold");
    cout << res.size() << '\n' << getNumBags(input, "shiny gold")-1 << '\n';
    // not including itself. For example, if a shiny bag contained nothing,
    // then the result should be 0, but the real result is 1.
}
