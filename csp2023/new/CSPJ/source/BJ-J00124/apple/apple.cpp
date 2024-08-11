#include <bits/stdc++.h>
using namespace std;

bool a[1000000000];
int main()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    
    int n;
    cin >> n;
    int cnt=0, d=-1, num=0;

    while (num < n) {
        cnt++;
        int pos;
        for (int i=0; i<n; i++)
            if (! a[i]) {
                pos = i;
                break;
            }

        int t=0;
        for (int i=pos; i<n; i++) {
            if (t==2 || i==pos) {
                if (a[i] == false) {
                    if (i==n-1 && d==-1)
                        d = cnt;
                    num++;
                    a[i] = true;
                    t=0;
                }
            }
            else if (a[i] == false)
              t++;
        }
    }

    cout << cnt << ' ' << d;
    return 0;
}
