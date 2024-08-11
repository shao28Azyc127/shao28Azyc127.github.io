#include <iostream>
using namespace std;

int k[1000005];
int m[1000005];
int id[1000005];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d;
    int sum = 0;
    cin >>n>>d;
    int nu = 0;
    for(int i = 1;i <= n-1;i++)
    {
        cin >>k[i];
        nu += k[i];
    }
    bool flag = true;
    for(int i = 1;i <= d;i++)
    {
        cin >>m[i];
        if(m[i] > m[1]) flag = false;
    }
    id[1] = m[1];
    for(int i = 2;i <= n-1;i++)
    {
        if(m[i] < id[i-1])
        {
            id[i] = m[i];
        }
        else
        {
            id[i] = 0;
            id[i] += id[i-1];
        }
    }
    int ans = 0;
    sum = 1;
    int rs = k[1];
    for(int i = 2;i <= n;i++)
    {
        if(id[i] == id[i-1])
        {
            sum++;
            rs+=k[i];
        }
        else
        {
            ans += (rs/d)*id[i-1];
            rs = 0;
            sum = 1;
        }
    }
    if(flag) cout <<ans+id[1]<<endl;
    else cout <<nu /d*m[1]<<endl;
    return 0;
}
