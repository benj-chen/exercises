// with O2 optimization flag, exec time is 0.006s.
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
using namespace std;
using str=string;
using vs = vector<str>;
vs split(str s, char delim) {
    vs ret(1);
    for (char c: s) {
        if (c==delim) ret.push_back("");
        else ret.back()+=str(1,c);
    }
    return ret;
}
const unsigned long long neg1=-1;
int main() {
    ifstream in("i4");
    vs inputs(1);
    str raw_i;
    int validPassCount=0;
    while (getline(in,raw_i)) {
        if (raw_i=="")
            inputs.push_back("");
        else
            inputs.back()+=raw_i+" ";
    }
    vector<map<str,str> > mod_inputs;
    for (str s: inputs) {
        if ((count(s.begin(),s.end(),':')==8) || 
            (count(s.begin(),s.end(),':')==7 && s.find("cid")==neg1))
            validPassCount++;
        // setup part 2
        mod_inputs.push_back({});
        for (str t: split(s,' ')) {
            vs temp=split(t,':');
            if (temp[0]!="cid") mod_inputs.back()[temp[0]]=temp[1];
        }

    }
    // part 1 answer 216
    cout << validPassCount << '\n';
    validPassCount=0;
    const str COLORS="amb blu brn gry grn hzl oth",HEXA="1234567890abcdef";

    for (map<str,str> x: mod_inputs) {
        if (x.size()!=8) continue; // for some reason each size is 1 bigger than in Python
        bool marker1=0,marker2=0;
        for (int i=1;i<x["hcl"].length();i++)  {
            if (HEXA.find(x["hcl"][i])==neg1) {
                marker1=1;
                break;
            }
        }
        for (char i: x["pid"]) {
            if (i<'0' || i>'9') {
                marker2=1;
                break;
            }
        }
        if (!(
            marker1 || marker2 ||
            (x["byr"]>"2002" || x["byr"]<"1920") ||
            (x["iyr"]<"2010" || x["iyr"]>"2020") ||
            (x["eyr"]<"2020" || x["eyr"]>"2030") ||
            (COLORS.find(x["ecl"])==neg1) ||
            (x["pid"].length()!=9) ||
            (x["hgt"].find("cm")==neg1 && x["hgt"].find("in")==neg1) ||
            (x["hgt"].find("cm")!=neg1 && (x["hgt"]<"150cm" || x["hgt"]>"193cm")) ||
            (x["hgt"].find("in")!=neg1 && (x["hgt"]<"59in" || x["hgt"] > "76in")) ||
            (x["hcl"][0]!='#' || x["hcl"].length()!=7)   
        )) validPassCount++;
    }
    // part 2 answer 150
    cout << validPassCount << '\n';
}