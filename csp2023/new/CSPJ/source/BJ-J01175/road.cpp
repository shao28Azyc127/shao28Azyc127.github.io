#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    long long n,p,a[100010],b[100010];
    long long ans = 0;
    cin>>n>>p;
    for(int i = 1;i <= n-1;i++)
    {
        cin>>a[i];
    }
    for(int i = 1;i <= n;i++)
    {
        cin>>b[i];
    }
    int can_move = 0;
    for(int i = 1;i < n;i++)
    {
        int h = i;
        int j = i+1;
        int ij = 0;
        int must_move = a[i];
        while(j < n && b[j] > b[i])
        {
            must_move += a[j];
            j++;
            ij++;
        }
        i+=ij;
        int must_get = (must_move-can_move) / p;
        if((must_move-can_move) % p > 0)
        {
            must_get+=1;
        }
        ans += must_get * b[h];
        can_move = must_get * p + can_move - must_move;
    }
    cout<<ans;
    return 0;
}