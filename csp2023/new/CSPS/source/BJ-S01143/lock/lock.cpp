#include<iostream>
#include<cstdio>
using namespace std;
int a[10][7];
int s[7];
int n,ans=0;
void dfs(int i){
    if(i>5){
        for(int j=1;j<=n;j++){
            int c=0,c1=0,c2=0,x=0;
            for(int k=1;k<=5;k++){
                if(s[k]!=a[j][k]){
                    ++c;
                    if(c1!=0){
                        c2=s[k]-a[j][k];
                        if(x+1!=k)return;
                    }
                    else c1=s[k]-a[j][k],x=k;
                    if(c1<0)c1+=10;
                    if(c2<0)c2+=10;
                }
            }
            if(c>2||c==0)return;
            if(c1!=0&&c2!=0&&c1!=c2)return;
        }
        ++ans;
        //for(int k=1;k<=5;k++)cout<<s[k]<<" ";
        //cout<<endl;
        return;
    }
    for(int j=0;j<=9;j++){
        s[i]=j;
        dfs(i+1);
    }
}
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++)cin>>a[i][j];
    }
    dfs(1);
    cout<<ans;
    return 0;
}
