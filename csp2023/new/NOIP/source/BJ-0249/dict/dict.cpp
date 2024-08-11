#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
    int n,m,maxs[3005]={0},mins[3005];
    string s[3005];
    memset(mins,0x3f,sizeof(mins));
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>s[i];
        for(int j=0;j<m;j++){
            maxs[i]=max(maxs[i],(int)(s[i][j]));
            mins[i]=min(mins[i],(int)(s[i][j]));
        }
    }
    for(int i=1;i<=n;i++){
        int ans=1;
        for(int j=1;j<=n;j++){
            if(i!=j&&mins[i]>=maxs[j]){
                ans=0;
                break;
            }
        }
        cout<<ans;
    }
    return 0;
}
