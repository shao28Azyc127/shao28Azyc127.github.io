# include <string>
# include <iostream>
# include <algorithm>
using namespace std;

string s[3001];
int n, m;

bool cmp(string s, string t){
    for (int i = 1; i <= m; i++){
        if (s[i] > t[i])
            return false;
        if (s[i] < t[i])
            return true;
    }
    return false;
}

int main(){
    ios :: sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    cin >> n >> m;
    if (n == 1){
        cout << 1 << endl;
        return 0;
    }
    string minn = "", secn = "";
    for (int i = 1; i <= m; i++){
        minn += 'z';
        secn += 'z';
    }
    int pos = 0;
    for (int i = 1; i <= n; i++){
        cin >> s[i];
        sort(s[i].begin(), s[i].end());
        string tmp = s[i];
        reverse(tmp.begin(), tmp.end());
        if (cmp(tmp, minn)){
            secn = minn;
            minn = tmp;
            pos = i;
        }
        else if (cmp(tmp, secn))
            secn = tmp;
    }
    for (int i = 1; i <= n; i++){
        if (pos != i)
            cout << (s[i] < minn);
        else
            cout << (s[i] < secn);
    }
    return 0;
}
/*
This might be the last problem I get AC on a formal contest.
I would AFO in a few days...probably.
No, I won't leave the Olympiad contests.
ChO is waiting for me, just here and now.
I might return, about a year later, when I will still express my love for OI.

By Ja50nY0un9 on 2023.11.18
*/