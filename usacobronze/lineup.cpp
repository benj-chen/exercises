#include <bits/stdc++.h>
using namespace std;
#define pss pair<str,str>
#define vt vector
#define str string
#define f first
#define s second
#define b begin()
#define e end()
#define gb groups.back()

vt<str> half1,half2; // reverse half2 when combining
void strip_ends(vt<str> group, str adj_left, str adj_right) {
    // what is originally to the left and right of the list, these numbers would be in group
    // the base case would look like {a,b,b,c,c,d} or {a,b,b,c}
    // base case 1 can be reduced to {b,c,c,d} after adding b to half1
    // this works for cow lines of length 3 and above.
    // length 2 is an edge case
    for (str i: group) cout << i << "\" \"";
    cout << endl;
    if (group.size()==4) {
        for (int i=0;i<4;i++) {
            if (group[i]==adj_left) {
                // if the index is even, then add the next one, else add the previous one
                half1.push_back(group[i+(i%2? 1:-1)]);
            }
            if (group[i]==adj_right) {
                half2.push_back(group[i+(i%2? 1:-1)]);
            }
        }
        return;
    }
    if (group.size()==6) {
        for (int i=0;i<6;i++) {
            if (group[i]==adj_left) {
                half1.push_back(group[i+(i%2? 1:-1)]);
                group.erase(group.begin()+i);
                group.erase(group.begin()+i+(i%2? 0:-1));
                strip_ends(group,half1.back(),adj_right);
                return;
            }
        }
    }
    // find the two ends, cut them off and carry on
    str new_left="-";
    str new_right="-";
    for (int i=0;i<group.size();i++) {
        if (group[i]==adj_left) {
            half1.push_back(group[i+(i%2? 1:-1)]);
            new_left=half1.back();
            group.erase(group.begin()+i);
            group.erase(group.begin()+i+(i%2? 0:-1));
        }
        if (group[i]==adj_right) {
            half2.push_back(group[i+(i%2? 1:-1)]);
            new_right=half2.back();
            group.erase(group.begin()+i);
            group.erase(group.begin()+i+(i%2? 0:-1));
        }
    }
    assert (new_left!="-" && new_right!="-");
    strip_ends(group,new_left,new_right);
    

}
int main() {
    ifstream cin("lineup.in");
    // ofstream cout("lineup.out");
    int n;
    cin >> n;
    vt<pss> beside(n);
    str raw_input;
    for (int i=0;i<n;i++) {
        cin >> raw_input;
        beside[i].f=raw_input;
        cin >> raw_input >> raw_input >> raw_input >> raw_input >> raw_input; // get the fifth word after the first name, alternatively use cin.ignore()
        beside[i].s=raw_input;
    }

    // among each group of adjacent cows there would only be one cow name present on each edge. Max 3 groups
    vt<vt<str> > groups={{beside.back().f,beside.back().s}};
    beside.pop_back();
    // we can just look through, and if there are none to add then pop back the next one - the list is short enough that this is alright

    while (!beside.empty()) {
        // look at each pair and see if it's in the back group
        vt<int> to_remove;
        for (int i=0;i<beside.size();i++) {
            pss p=beside[i];
            if (count(gb.b,gb.e, p.f)==1) {
                // the first elem appears in the back group. Add the second one and the first to know where the ends are
                gb.push_back(p.f);
                gb.push_back(p.s);
                to_remove.push_back(i);
            }
            else if (count(gb.b,gb.e,p.s)==1) {
                // same story
                gb.push_back(p.f);
                gb.push_back(p.s);
                to_remove.push_back(i);
            }
        }
        if (to_remove.empty()) {
            // the group has finished
            groups.push_back({beside.back().f,beside.back().s});
            beside.pop_back();
        }
        for (int i=0;i<to_remove.size();i++) {
            beside.erase(beside.b+to_remove[i]-i); // big brain - account for the fact that size decreases by 1 every time
        }
    }
    vt<vt<str> > res;
    for (vt<str> v: groups) {

        // v.insert(v.begin(),v.front());
        // v.insert(v.begin(),"a");
        // v.push_back(v.back());
        // v.push_back("a");
        if (v.size()==2) {
            res.push_back(v);
            continue;
        }
        map<str,int> appear;
        for (auto i: v) appear[i]++;
        vt<str> edges;
        for (auto i: v) if (appear[i]==1) {
            edges.push_back(i);
        }
        assert (edges.size()==2);
        strip_ends(v,edges[0],edges[1]);
        res.resize(res.size()+1);
        for (int i=0;i<half2.size();i++) {
            res.back().push_back(half1[i]);
            res.back().push_back(half2[half2.size()-i]);
        }
        if (half1.size()!=half2.size()) {
            res.back().push_back(half1.back());
        }

        half1.clear();
        half2.clear();

    }
    for (auto i: res) {
        for (auto j: i) cout << j << endl;
        cout << endl;
    }
    // const str alpha_names[] = {"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"};
    // for (auto v: groups) {
    //     assert (v.size()%2==0);
    //     vt<str> new_group;
    //     // find a string that appears once - there should be two
    //     // get the original back name, use to avoid confusion later and add to new_group
    //     map<str,int> appear;
    //     for (str s: v) appear[s]++;
    //     str orig_end="\n";
    //     for (int i=v.size()-1;i>-1;i--) {
    //         if (appear[v[i]]==1) {
    //             orig_end=v[i];
    //             break;
    //         }
    //     }
    //     assert (orig_end!="\n");
    //     // watch out for the single group edge case, see if this works first though
    //     while (v.size()>1) {
    //         map<str,int> appear;
    //         for (str s: v) {
    //             appear[s]++;
    //         }
    //         for (int i=0;i<v.size();i++) {
    //             if (appear[v[i]]==1 && v[i]!=orig_end) {
    //                 new_group.push_back(v[i]);
    //                 new_group.push_back(v[i+1]);
    //                 // delete those two from the array and carry on
    //                 v.erase(v.begin()+i);
    //                 v.erase(v.begin()+i); // previous index doesn't exist enymore
    //                 break;
    //             }
    //         }
    //     }
    //     new_group.push_back(orig_end);
    //     std::cout << "one iter done";
    // }
    
}