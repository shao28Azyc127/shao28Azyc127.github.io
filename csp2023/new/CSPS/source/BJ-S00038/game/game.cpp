#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int n;
    char a[2000001];
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<n/2+1<<endl;
    return 0;
}
