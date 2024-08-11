#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
int n,m;
string ss[3010],sd[3010];
priority_queue<string,vector<string>,greater<string> > s;
int main(void) {
    FILE *r=freopen("dict.in","r",stdin);
    FILE *d=freopen("dict.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i=1;i<=n;i++) {
        cin >> ss[i];
        string sss=ss[i];
        sort(sss.begin(),sss.end());
        reverse(sss.begin(),sss.end());
        s.push(sss);
        sd[i]=sss;
    }
    for (int i=1;i<=n;i++) {
        if (s.top()==sd[i]) {
            s.pop();
            string g=s.top();
            string y=ss[i];
            sort(y.begin(),y.end());
            sort(g.begin(),g.end());
            reverse(g.begin(),g.end());
            if (y<g) cout << 1;
            else cout << 0;
            s.push(sd[i]);
        } else {
            string g=s.top();
            string y=ss[i];
            sort(y.begin(),y.end());
            sort(g.begin(),g.end());
            reverse(g.begin(),g.end());
            if (y<g) cout << 1;
            else cout << 0;
        }
    }
    return 0;
}