#include<iostream>
#include <cstring>
#include <string>
using namespace std;

string s;
int letter[50];

int dob(string sx)
{
    for(int i = 1;i < sx.size()-1;i ++)
    {
        if(sx[i] == sx[i+1])
        {
            return i;
        }
    }
    return -1;
}

bool check(string sx)
{
    int len = sx.size() - 1;
    memset(letter,0,sizeof(letter));
    for(int i = 1;i <= len;i ++)
    {
        letter[sx[i] - 'a' +1]++;
    }
    for(int i = 1;i <= 26;i ++)
    {
        if(letter[i] % 2 == 1)
        {
            //cout << sx << " letter\n";
            return false;
        }

    }
    while(sx.size() > 1)
    {
        if(sx.size() == 3)
            return sx[1] == sx[2];
        int pos = dob(sx);
        if(pos == -1)
            return false;
        string sx1 = sx.substr(1,pos- 1) ;
        string sx2 = sx.substr(pos+2 ,len - pos - 2);
        sx = sx1+sx2;
    }
    return true;
}

int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int n;
    cin >> n;
    cin >> s;
    s = " " + s;
    int ans = 0;
    for(int len = 2;len <= n;len += 2)
    {
        for(int st = 1;st <= n - len + 1;st++)
        {
            if(check(" " + s.substr(st,len)))
            {
                ans++;
                //cout << s.substr(st,len) << endl;
            }
        }
    }
    cout << ans;
    return 0;
}
