#include <bits/stdc++.h>

using namespace std;

vector<string> a;
int n, m, t;

int main()
{
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    cin >> n >> m;
    string mv("z", m);
    for (int i=0; i<n; i++) {
        string s;
        cin >> s;
        sort(s.begin(), s.end());
        a.push_back(s);
        for (int k=0, j=m-1; k<=j; k++, j--) {
            swap(s[k], s[j]);
        }
        if (s < mv) {mv = s; t = i;}
    }


    for (int i=0; i<n; i++) {
         cout << (a[i] <= mv);
    }


    return 0;
}
