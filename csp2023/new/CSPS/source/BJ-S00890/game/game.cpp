#include<bits/stdc++.h>
using namespace std;
string s;

void helpcheck(int st, int en, string tmp){
    for (int i = st; i <= en - 1; i++)
        if (tmp[i] == tmp[i + 1]){
            tmp[i] = ' ';
            tmp[i + 1] = ' ';
            for (int j = i + 2; j <= en; j++)
                tmp[j - 2] = tmp[j];
            helpcheck(st, en, tmp);
        }
}

bool check(int st, int en){
    string tmp = s;
    if (st == (en - 1))
        if (s[st] == s[en])
            return true;
        else
            return false;
    helpcheck(st, en, tmp);
    if (tmp[1] == ' ')
        return true;
    else
        return false;
}

int main(){
   freopen("game.in", "r", stdin);
   freopen("game.out", "w", stdout);
    int n, num = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> s[i];

    for (int i = 1; i <= n - 1; i++)
        for (int j = i + 1; j <= n; j++)
            if (check(i, j))
                num++;

    cout << num;

    return 0;
}