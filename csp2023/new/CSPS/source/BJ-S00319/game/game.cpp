#include <iostream>
//#include <set>
using namespace std;

//set<string> S;
//bool f[2000005];
int main()
{
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);

    int n;
    cin >> n;
    string s;
    cin >> s;
    string t = s;

    //n=s.length();
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        while(t[i] == t[i + 1])
        {
            //f[i] = f[i + 1] = true;
            //S.insert(t.substr(i, 2));
            t.erase(i, 2);
            ans++;
            if(i > 0)
                i--;
        }
        //for()
    }
    cout << ans << endl;

    //for(int i = 0; i < n; i++)
    //{
        //for(int j )
    //}
    return 0;
}
