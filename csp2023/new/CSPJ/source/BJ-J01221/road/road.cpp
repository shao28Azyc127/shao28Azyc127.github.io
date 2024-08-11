#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d,v[100050],a[100050],pos=0,ii=0,ans=0,check=0;
    scanf("%d%d",&n,&d);
    for(int i=1;i<n;i++){
        int tmp;
        scanf("%d",&tmp);
        v[i]=v[i-1]+tmp;
    }
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);

    for(pos=0;pos<v[n-1];){
        if(pos>=v[ii+1]){
            ii++;
        }
        if(a[check]>=a[ii])
            check=ii;
        pos+=d;
        ans=ans+a[check];
    }
    printf("%d",ans);
    return 0;
}
