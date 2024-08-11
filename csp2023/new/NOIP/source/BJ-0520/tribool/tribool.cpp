#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
int a[100010];
int main()
{
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    int C,T;
    cin>>C>>T;
    while(T--)
    {
        memset(a,0,sizeof(a));
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=m;i++)
        {
            char c;
            int x;
            cin>>c;
            cin>>x;
            if(c=='T'||c=='F')
                a[x]=0;
            else
                a[x]=1;
        }
        int ans=0;
        for(int i=1;i<=n;i++)
            if(a[i]==1)
                ans++;
        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
