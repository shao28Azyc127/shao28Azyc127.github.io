#include<bits/stdc++.h>
using namespace std;
int ans=0;
int n;
int a[15][15],t[8],f,f2;
bool check(){
    for(int i = 1;i<=n;i++){
        int m1,m2,cnt=0,flag=1;
        for(int j = 1;j<=5;j++){
            if(a[j][i]!=t[j]){
                if(cnt==2){
                    flag=0;
                    break;
                }
                if(cnt==1) m2=j;
                else m1=j;
                cnt++;
            }
        }
        if(cnt==0) return false;
        if(flag==0) return false;
        if(cnt==1) {continue;}
        if(m1+1!=m2) return false;
        if(!(t[m1]-a[m1][i]==t[m2]-a[m2][i]||t[m1]-a[m1][i]==10-a[m2][i]+t[m2]))
           return false;
    }
    return true;
}
void dfs(int x){
    if(x==6){
        if(check()){/*
            for(int i = 1;i<=5;i++){
                cout<<t[i]<<" ";
            }
            cout<<endl;*/
            ans++;
        }
        return ;
    }
    for(int i = 0;i<=9;i++){
        t[x]=i;
        dfs(x+1);
    }
}
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=5;j++){
            cin>>a[j][i];
        }
    }
    dfs(1);
    cout<<ans<<endl;
    return 0;
}
