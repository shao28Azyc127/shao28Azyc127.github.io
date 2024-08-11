#include<bits/stdc++.h>
using namespace std;
bool flag[100000010];
int main()
{
    memset(flag,1,sizeof(flag));
    int n,day = 0,cur = 0;
    cin >> n;
    int cnt = n;
    while(cnt != 0)
    {
        int sum = 0,a = 0;
        for(int i = 1; i <= n; i++)
        {
            if(a % 3 == 0)
            {
                 if(flag[i] != 0)
                 {
                     flag[i] = 0;
                     sum++;
                     if(i == n) cur = day;
                     a++;
                 }
                 else continue;
            }
        }
        day++;
        cnt -= sum;
    }
    cout << day << " " << cur << endl;
    return 0;
}
