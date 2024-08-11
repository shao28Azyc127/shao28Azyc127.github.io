#include<bits/stdc++.h>
using namespace std;
int n,ans,z[10],s[10],a[10][10];
bool pd,cd;
void dfs(int l1,int l2,int l3,int l4,int l5){
    s[1]=l1,s[2]=l2,s[3]=l3,s[4]=l4,s[5]=l5,pd=1;
    for(int i=1;i<=n;i++){
        cd=0;
        for(int j=1;j<=5;j++) z[j]=s[j];
        for(int j=1;j<=5;j++){
            if(z[j]!=a[i][j]){
                cd=1;
                if(j!=5) if(z[j+1]!=a[i][j+1]) z[j+1]-=z[j]-a[i][j];
                if(z[j+1]<0) z[j+1]+=10;
                if(z[j+1]>10) z[j+1]-=10;
                z[j]=a[i][j];
                break;
            }
        }
        for(int j=1;j<=5;j++) if(z[j]!=a[i][j]) pd=0;
        if(cd==0) pd=0;
    }
    if(pd) ans++;
    if(s[5]+1<=9) dfs(s[1],s[2],s[3],s[4],s[5]+1);
    else if(s[4]+1<=9) dfs(s[1],s[2],s[3],s[4]+1,0);
    else if(s[3]+1<=9) dfs(s[1],s[2],s[3]+1,0,0);
    else if(s[2]+1<=9) dfs(s[1],s[2]+1,0,0,0);
    else if(s[1]+1<=9) dfs(s[1]+1,0,0,0,0);
}
int main (){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++) for(int j=1;j<=5;j++) scanf("%d",&a[i][j]);
    dfs(0,0,0,0,0);
    cout<<ans<<endl;
    return 0;
}