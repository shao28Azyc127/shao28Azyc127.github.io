#include <iostream>
#include <time.h>
using namespace std;
bool a[1000000001];
int main()
{
    freopen("apple.in" , "r" , stdin);
    freopen("apple.out" , "w" , stdout);
    int n;
    cin >> n;
    if(n == 1)
    {
        cout << 1 << " " << 1;
        return 0;
    }
    else if(n == 2)
    {
        cout << 2 << " " << 2 << endl;
        return 0;
    }
    else if(n == 3)
    {
        cout << 3 << " " << 3 << endl;
        return 0;
    }
    int cur = 1;
    int ans = 0;
    for(int i = 2 ; i <= n ; i += 1)
    {
        cur += i - 1;
        if(cur >= n)
        {
            cout<< i;
            break;
        }
    }
    if((n - 1) % 3 == 0)
    {
        cout << " " << 1 << endl;
        return 0;
    }
    int sum = 0;
    for(int i = 1 ; i <= n ; i ++)
    {
        if(a[i] == true)
        {
            continue;
        }
        sum ++;
        int cnt = 0;
        for(int j = i ; j <= n ; j ++)
        {
            if(a[j] == 0)
            {
                cnt ++;
                if((cnt - 1) % 3 == 0)
                {
                    a[j] = true;
                    if(j == n)
                    {
                        cout << " " << sum << endl;
                        return 0;
                    }
                }
            }
        }
    }
    return 0;
}
