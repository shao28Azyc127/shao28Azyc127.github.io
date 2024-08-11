#include<bits/stdc++.h>
using namespace std;
string s;
int flag[8005][8005];
int len;
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin >> len;
    cin >> s;
    int cnt = 0;
    for(int i = 2;i <= len;i+=2)
    {
        for(int j = 0;j < len - i + 1;j++)
        {
            if(s[j] == s[j + i - 1] && i == 2)
            {
                flag[j][j + i - 1] = 1;
                //cout << j << " " << j + i - 1 << endl;
                cnt++;
            }
            if(s[j] == s[j + i - 1] && flag[j + 1][j + i - 2] == 1)
            {

                flag[j][j + i - 1] = 1;
                //cout << j << " " << j + i - 1 << endl;
                cnt++;
            }
            for(int mid = j + 1;mid <= j + i - 3;mid += 2)
            {
                if(flag[j][mid] == 1 && flag[mid + 1][j + i - 1] == 1 &&flag[j][j + i - 1] != 1)
                {
                    flag[j][j + i - 1] = 1;
                    //cout << j << " " << j + i - 1 << endl;
                    cnt++;
                }

            }


        }
    }
    cout << cnt<< endl;
    return 0;
}
