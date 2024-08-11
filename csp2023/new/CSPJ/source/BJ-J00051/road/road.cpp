#include <bits/stdc++.h>

using namespace std;
int n,d,s_sum,s[100000],m[100000];
bool fm, fs;

int main()
{
    freopen("road.in","r", stdin);
    freopen("road.out","w", stdout);

    cin >> n >> d;
    fs = true;
    s_sum = 0;
    for (int i=0; i<n-1; i++) {
        cin >> s[i];
        if (i > 0) fs = fs & (s[i]==s[i-1]);
        s_sum += s[i];
    }

    fm = true;
    for (int i=0; i<n; i++) {
        cin >> m[i];
        if (i > 0) fm = fm & (s[i]==s[i-1]);
    }


    cout << (s_sum + d - 1)/ d  * m[0];




    return 0;
}

