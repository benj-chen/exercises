#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;
using vi = vector<ll>;
vector<string> split(string s, char delim) {
    vector<string> res(1);
    for (char c: s) {
        if (c==delim) res.push_back("");
        else res.back()+=c;
    }
    return res;
}
void strip(string& s) {
	int i=-1,j=s.size();
	while (s[++i]==' ');
	while (s[--j]==' ');
	s = s.substr(i,j-i+1);
}
struct monkey;
vector<monkey> m;
vi totals;
struct monkey {
	vi items;
	// either add or multiply
	int id;
	int typ = -1; // 0 for add, 1 for multiply
	// 2 operands are old and (number or old)
	int div = -1; // to test for divisibility
	ll op1 = -1, op2 = -1; // by default, -1 is "old"
	int t_pass = -1, f_pass = -1; // who to pass to if true and false
	monkey(string str0,string str1, string str2, string str3, string str4, string str5) {
		strip(str0);
		strip(str1);
		strip(str2);
		strip(str3);
		strip(str4);
		strip(str5);
		str0 = split(str0,' ')[1];
		id = stoi(str0.substr(0,str0.size()-1));

		vector<string> s1 = split(str1,' ');
		for (int i=2;i<s1.size();i++) {
			items.push_back(stoll(split(s1[i],',')[0]));
		}

		auto s2 = split(str2,' ');
		// take last 3 items
		switch(s2[s2.size()-2][0]) {
			case '*':
				typ = 1;
				break;
			case '+':
				typ = 0;
				break;
			default:
				cout << "Type was" << s2[s2.size()-2] << endl;
		}
		if (s2[s2.size()-3]!="old") {
			op1 = stoll(s2[s2.size()-3]);
		}
		if (s2[s2.size()-1]!="old") {
			op2 = stoll(s2[s2.size()-1]);
		}
		
		div = stoi(split(str3,' ').back());
		t_pass = stoi(split(str4,' ').back());
		f_pass = stoi(split(str5,' ').back());

	}
	void op() {

		//cout << "sz" << m.size() << endl;
		totals[id]+=items.size();
		for (ll i: items) {
			//cout << "init " << i << endl;
			bool go = false;
			if (typ==0) {
				int a =  (op1==-1? i: op1),
				    b =  (op2==-1? i: op2);
				i = (a%div + b%div);
			}
			else {
				int a =  (op1==-1? i: op1),
				    b =  (op2==-1? i: op2);
				i = (a%div)*(b%div);
			}
			i%=div;
			//cout << "post op " << i << endl;
			//i /=3;
			//cout << "bored  " << i << endl;
			if (i<0) cout << "neg"<<i << endl;
			if (i){
				//cout << "is not";
				//cout << "div by " << div << endl;
				//cout << "thrown to " << f_pass << endl;
				m[f_pass].items.push_back(i);
			}
			else{
				//cout << "is";
				//cout << "div by " << div << endl;
				//cout << "thrown to " << t_pass << endl;
				// assume that a monkey doesn't throw to itself
				m[t_pass].items.push_back(i);
			}	
			//cout<<i<<" ";
		}
		items.clear();
	}
};

int main() {
	vector<string> inputs;
	string s;
	while (getline(cin,s)) {
		if (s=="") {
			// inputs.size(). should be 6	
			monkey q(inputs[0],inputs[1],inputs[2],inputs[3],inputs[4],inputs[5]);
			m.push_back(q);
			inputs.clear();
		}
		else inputs.push_back(s);
	}
	totals.resize(m.size());
	for (int i=0;i<2010;i++) {
		if (i==1 or i==18 or i==19 or i==20 or i==21 or i==22 or i==1000 or i==2000) {
		cout << "q" << i << endl;
		for (int i: totals) {
			cout << i << endl;
		}
		cout << endl;
		}
		for (int j=0;j<m.size();j++) {
			m[j].op();
		}
	}
	sort(totals.begin(),totals.end());
	cout << totals[totals.size()-2]*totals.back() << endl;
}
