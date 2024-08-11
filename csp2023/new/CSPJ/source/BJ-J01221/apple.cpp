#include <bits/stdc++.h>

using namespace std;

bool a[1000050];

int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    memset(a,true,sizeof(a));
    int n,ans2;
    scanf("%d",&n);
    for(int tt=1;;tt++){
        int cnt=3,pos=0;
        bool check=false;
        for(int i=1;i<=n;i++){
            if(a[i]==0)
                continue;
            if(cnt==3){
                a[i]=0;
                //cout<<i<<" ";
                cnt=0;
                if(i==n){
                    ans2=tt;
                }
                check=true;
            }
            cnt++;
        }
        if(check==false){
            printf("%d %d",tt-1,ans2);
            return 0;
        }
    }
    return 0;
}
