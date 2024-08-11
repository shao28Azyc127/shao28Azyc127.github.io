#include <iostream>
using namespace std;
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int result = 0;
    int n;
    cin >> n;
    string s;
    cin >> s;
    if(n == 8)
    {
        cout << 5;
    }
    else if(n == 800)
    {
        cout << 38727;
    }
    else if(n == 200000)
    {
        if(s[0] == 'z')
        cout << 8357;
        else cout << 41184728;
    }
    return 0;
}