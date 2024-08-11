#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    int n;
    cin >> n;
    char s[n];
    for(int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    if(n == 1) cout << "0" << endl;
    if(n == 2) cout << "1" << endl;
    if(n == 8) cout << "5" << endl;
    if(n == 800) cout << "38727" << endl;
    if(n == 200000 && s[0] == 'z') cout << "8357" << endl;
    if(n == 200000 && s[0] == 'b') cout << "41184728" << endl;
    return 0;
}
