//unfinished
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ul = unsigned long;
using ull = unsigned long long;
using pii = pair<int,int>;
#define FOR(a,st,b) for (int a=st;a<b;a++)
#define EACH(a,b) for (auto& a: b)
#define vt vector
#define vi vector<int>
#define alg_type vi // default is int, may be ll or my_class etc
#define alg_vec_type vt<alg_type>
#define f first
#define s second
    /*months:
    January (31)
    February (28, 29)
    March (31)
    April (30)
    May (31)
    June (30)
    July (31)
    August (31)
    September (30)
    October (31)
    November (30)
    December (31)
    */
bool is_leap(int year) {
    if (!(year%100)) year/=100;// year is a mult of 100
    return year%4;
}
int new_year_day,ct=0; // [0,7) - 0 is Sunday, 1 is Monday, 2 is Tuesday etc
void day1sundays(int year, int start) {
    // Start for Jan 1 is 1
    int month_days[12]; // for example, Feb 1 is 32 since it's one day after the 31st day
    bool leap = is_leap(year);
    month_days[1]=28;
    for (int i: (vi) {0,2,4,6,7,9,11}) month_days[i]=31;
    for (int i: (vi) {3,5,8,10}) {
        month_days[i]=30;
    }
    for (int i=1;i<12;i++) {
        month_days[i]+=month_days[i-1];
    }
    if (leap) {
        for (int i=1 /*Jan left out because leap years don't affect*/; i<12;i++) {
            month_days[i]++;
        }
    }
    // prefix sum
    new_year_day=(1+start+365+leap)%7; // 1 day after dec 31
    // calculate first month sundays
    for (int i: month_days) {
        if ((i+1)%7==start) {
            ct++;
        }
    }
}
int main() {
    // 1 jan 1900 was a monday
    day1sundays(1900,1);
    ct=0; // reset count
    for (int i=1901;i<2001;i++) {
        day1sundays(i,new_year_day);
    }
    cout << ct << endl;
    ct=0;
    day1sundays(2021,0);
    cout << ct << endl;
    ct=0;
    day1sundays(2021,1);
    cout << ct << endl;
    ct=0;
    day1sundays(2021,2);
    cout << ct << endl;
    ct=0;
    day1sundays(2021,3);
    cout << ct << endl;
    ct=0;
    day1sundays(2021,4);
    cout << ct << endl;

    ct=0;
    day1sundays(2021,5);
    cout << ct << endl;
    ct=0;
    day1sundays(2021,6);
    cout << ct << endl;
    ct=0;
}