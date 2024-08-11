#include<bits/stdc++.h>
using namespace std;
const int N=9;
int n,ans;
int a[N][6],b[6];
void dfs(int x){
    if(x>5){
        int f=1;
        for(int i=1;i<=n;i++){
            int f1=0,f2=0;
            for(int j=1;j<=5;j++){
                for(int k=1;k<=9;k++){
                    int flag=1;
                    b[j]=(b[j]+k)%10;
                    for(int o=1;o<=5;o++) if(a[i][o]!=b[o]) flag=0;
                    if(flag) f1=1;
                    b[j]=(b[j]-k+10)%10;
                }
            }
            for(int j=1;j<=4;j++){
                for(int k=1;k<=9;k++){
                    int flag=1;
                    b[j]=(b[j]+k)%10;
                    b[j+1]=(b[j+1]+k)%10;
                    for(int o=1;o<=5;o++) if(a[i][o]!=b[o]) flag=0;
                    if(flag) f2=1;
                    b[j]=(b[j]-k+10)%10;
                    b[j+1]=(b[j+1]-k+10)%10;
                }
            }
            if(!f1&&!f2) f=0;
        }
        ans+=f;
        return;
    }
    for(int i=0;i<=9;i++){
        b[x]=i;
        dfs(x+1);
        b[x]=-1;
    }
}
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++) for(int j=1;j<=5;j++) scanf("%d",&a[i][j]);
    for(int i=1;i<=5;i++) b[i]=-1;
    dfs(1);
    printf("%d\n",ans);
    return 0;
}
