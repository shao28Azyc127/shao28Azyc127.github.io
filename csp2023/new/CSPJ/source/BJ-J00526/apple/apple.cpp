#include<bits/stdc++.h>
using namespace std;
int n,ans=0,ans2=0,cnt=0;
bool a[(int)1e9+5]={0};
int main(){
    freopen("apple2.in","r",stdin);
    freopen("apple2.out","w",stdout);
    scanf("%d",&n);
    memset(a,true,sizeof(a));
    while(cnt<n){
        int cur=0;
        for(cur=0;cur<n;){
            while(a[cur]==0)cur++;
            a[cur]=0;
            cnt++;
            int i=0;
            while(i<3){
                cur++;
                if(a[cur]==1) i++;
            }
        }
        if(a[n-1]==1)ans++;
        ans2++;
    }
    printf("%d %d",ans2,ans+1);
    return 0;
}
