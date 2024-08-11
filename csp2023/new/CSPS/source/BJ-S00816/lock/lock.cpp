#include<iostream>
#include<stdio.h>
using namespace std;
int n,a[10][6],cnt=0;
bool b[6]={},g;
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    if(n==1){
        cout<<81;
        return 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++){
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=4;i++){
        int t[5];
        for(int j=1;j<=5;j++){
            if((j!=i)&&(j!=i+1)) t[j]=a[1][j];
        }
        for(int j=0;j<=9;j++){
            for(int l=1;l<=5;l++) b[l]=false;
            g=false;
            int k=(j+a[1][i+1]-a[1][i]+10)%10;
            if(j!=a[1][i]){
                t[i]=j,t[i+1]=k;
                for(int l=2;l<=n;l++){
                    for(int x=1;x<=5;x++){
                        if(t[x]!=a[l][x]) b[x]=true;
                    }
                    if(b[1]+b[2]+b[3]+b[4]+b[5]==1) g=true;
                    if(b[1]+b[2]+b[3]+b[4]+b[5]==2){
                        for(int x=1;x<=4;x++){
                            if(b[x]==true&&b[x+1]==true&&(a[l][x]-a[l][x+1]+10)%10==(t[x]-t[x+1]+10)%10){
                                g=true;
                                break;
                            }
                        }
                    }
                    if(g==false) break;
                    cnt++;
                }
            }
        }
    }
    for(int i=1;i<=5;i++){
        int t[5];
        for(int j=1;j<=5;j++){
            if(j!=i) t[j]=a[1][j];
        }
        for(int j=0;j<=9;j++){
            for(int l=1;l<=5;l++) b[l]=false;
            g=false;
            if(j!=a[1][i]){
                t[i]=j;
                for(int l=2;l<=n;l++){
                    for(int x=1;x<=5;x++){
                        if(t[x]!=a[l][x]) b[x]=true;
                    }
                    if(b[1]+b[2]+b[3]+b[4]+b[5]==1) g=true;
                    if(b[1]+b[2]+b[3]+b[4]+b[5]==2){
                        for(int x=1;x<=4;x++){
                            if(b[x]==true&&b[x+1]==true&&(a[l][x]-a[l][x+1]+10)%10==(t[x]-t[x+1]+10)%10){
                                g=true;
                                break;
                            }
                        }
                    }
                    if(g==false) break;
                    cnt++;
                }
            }
        }
    }
    cout<<cnt;
    return 0;
}
