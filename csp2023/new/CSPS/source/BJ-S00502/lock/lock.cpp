#include<bits/stdc++.h>
#include<cmath>
using namespace std;
int n,a[10][10],b,ans,c,cnt[100100];
int s(int x){
    return a[x][1]*10000+a[x][2]*1000+a[x][3]*100+a[x][4]*10+a[x][5];
    }
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++){
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++){
            for(int v=0;v<=9;v++){
                if(a[i][j]!=v){
                    int mem=a[i][j];
                    a[i][j]=v;
                    cnt[s(i)]++;
                    a[i][j]=mem;
                }
                if(j>1){
                        int w=(v-a[i][j])+a[i][j-1];
                        if(v-a[i][j]!=0){
                            w+=10;
                        w%=10;
                        //cout<<"sing"<<endl;
                        int mem1=a[i][j],mem2=a[i][j-1];
                        a[i][j]=v;a[i][j-1]=w;
                        cnt[s(i)]++;
                        a[i][j]=mem1;a[i][j-1]=mem2;
                        }


                }

            }
        }
        //for(int j=0;j<=99999;j++){
        //    if(cnt[j]>i)cnt[j]--;}

    }
    for(int i=1;i<=n;i++){
        cnt[s(i)]=0;
    }
    for(int j=0;j<=99999;j++){
    if(cnt[j]==n){ans++;
    //cout<<j<<endl;
    }
    }
    cout<<ans;
    return 0;
    }

