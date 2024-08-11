#include<bits/stdc++.h>
using namespace std;
int n,ans,p,flag;
char a[2000005],b[1005],c[1005];
bool check(){
    while(b[0]>0){
        flag=0;
        for(int i=1;i<=b[0]-1;i++){
            if(b[i]==b[i+1]){
                b[0]-=2;
                flag=1;
                memset(c,0,sizeof(c));
                for(int j=i+2;j<=n;j++){
                    c[j-2]=b[j];
                }
                for(int j=i;j<=n-2;j++){
                    b[j]=c[j];
                }
            }
        }
        if(flag==0){
            return 0;
        }
    }
    return 1;
}
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;
    cin>>a;
    for(int i=0;i<=n-2;i++){
        if(a[i]==a[i+1]){
            ans++;
        }
    }
    for(int i=4;i<=n;i+=2){
        for(int j=0;j<=n-i;j++){
            memset(b,0,sizeof(b));
            b[0]=i;
            for(int k=j;k<=j+i-1;k++){
                b[k-j+1]=a[k];
            }
            if(check()==1)ans++;
            p++;
        }
    }
    cout<<ans;
    return 0;
}
