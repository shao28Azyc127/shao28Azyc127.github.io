#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,temp = 0,cnt = 0,ans = 1;
    cin >> n;
    bool flag = false;
    while (temp != n)
    {
        cnt++;
        if ((n - temp) % 3 == 0)
        {
            temp = temp + (n - temp) / 3;
        }
        else if ((n - temp) % 3 == 1)
        {
            if(!flag)
            {
                 ans = cnt;
                 flag = true;
            }
            temp = temp + (((n - temp) - (n - temp) % 3) / 3 + 1);
        }
        else
        {
            temp = temp + (((n - temp) - (n - temp) % 3) / 3 + 1);
        }
    }
    cout << cnt << " "<< ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}