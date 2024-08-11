#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5;
int a[N][6];
int p[6];
int sum=0;
int n;
void dfs(int k){
    if(k==6){
        bool flag=1;
        for(int i=1;i<=n;i++){
            int last=-1,cnt=0,last_id;
            bool flag1=1;
            for(int j=1;j<=5;j++){
                if(a[i][j]!=p[j]){
                    flag1=0;
                    if(last==-1){
                        cnt++;
                        last=(p[j]-a[i][j]+10)%10;
                        last_id=j;
                    }
                    else{
                        if((p[j]-a[i][j]+10)%10!=last||last_id+1!=j)flag=0;
                        cnt++;
                    }
                }
            }
            if(flag1)flag=0;
            if(cnt>2)flag=0;
        }
        if(flag)sum++;
        return;
    }
    for(int i=0;i<=9;i++){
        p[k]=i;
        dfs(k+1);
        p[k]=-1;
    }
}
signed main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++){
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=5;i++)p[i]=-1;
    dfs(1);
    cout<<sum<<"\n";
    return 0;
}