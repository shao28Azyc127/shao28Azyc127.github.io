#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector <ll> v;

int main()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);


    int n, a = 0, b = 0;
    bool flag = false;
    cin>>n;

    for(ll i = 1; i <= n; i++)
        v.push_back(i);

    while(v.size() != 0)
    {
        int cnt = 2;
        for(vector<ll>::iterator iter = v.begin(); iter != v.end(); )
        {
            if(cnt == 2)
            {
                if(*iter == n)
                {
                    flag = true;
                    b++;
                }
                cnt = 0;
                iter = v.erase(iter);
            }
            else
            {
                cnt++;
                iter++;
            }
        }
        a++;
        if(!flag)
            b++;
    }

    cout<<a<<" "<<b;

    fclose(stdin);
    fclose(stdout);

    return 0;
}
/*
·ð×æ±£ÓÓAC£¡£¡£¡£¡£¡
*/
