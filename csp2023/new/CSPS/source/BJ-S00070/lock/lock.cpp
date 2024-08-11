#include<bits/stdc++.h>
using namespace std;
const int N=2100000,M=131;
int flag[N];
int n,a[10][10],b[10],diff[10],ans;
inline int read(){
    int x=0,w=1;
    char ch=0;
    while(ch<'0'||ch>'9'){
        if(ch=='-') w=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+(ch-'0');
        ch=getchar();
    }
    return x*w;
}
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    n=read();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++){
            a[i][j]=read();
        }
    }
    for(int i=0;i<=99999;i++){
        b[1]=i/10000%10,b[2]=i/1000%10,b[3]=i/100%10,b[4]=i/10%10,b[5]=i%10;
        for(int j=1;j<=n;j++){
            for(int k=1;k<=5;k++) diff[k]=0;
            int cnt=0,flag2=0;
            for(int k=1;k<=5;k++){
                if(b[k]!=a[j][k]){
                    diff[k]=1;
                    cnt++;
                }
            }
            if(cnt==0) flag[i]=1;
            if(cnt>=3){
                flag[i]=1;
                break;
            }
            if(cnt==2){
                    //
                for(int k=1;k<=4;k++){
                    if(diff[k]==1&&diff[k+1]==1){
                        flag2=1;
                        if((b[k+1]-b[k]-(a[j][k+1]-a[j][k]))%10!=0){
                            flag[i]=1;
                            break;
                        }
                    }
                }
                if(flag2!=1) flag[i]=1;
            }
            if(cnt==1) continue;
        }
    }
    for(int i=0;i<=99999;i++){
        if(!flag[i]) {
        ans++;
        }
    }
    cout << ans;
    return 0;
}
