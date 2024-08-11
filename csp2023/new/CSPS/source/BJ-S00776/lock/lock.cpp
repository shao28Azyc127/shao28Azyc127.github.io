#include<bits/stdc++.h>
using namespace std;
long long arr[6];
long long a[6];
long long buc[10][10][10][10][10];
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    long long n;
    cin>>n;
    long long temp=n;
    while(temp--){
        for(long long j=1;j<=5;j++){
            cin>>arr[j];
            a[j]=arr[j];
        }
        for(long long i=0;i<=9;i++){
            if(i!=arr[5])buc[arr[1]][arr[2]][arr[3]][arr[4]][i]+=1;
            if(i!=arr[4])buc[arr[1]][arr[2]][arr[3]][i][arr[5]]+=1;
            if(i!=arr[3])buc[arr[1]][arr[2]][i][arr[4]][arr[5]]+=1;
            if(i!=arr[2])buc[arr[1]][i][arr[3]][arr[4]][arr[5]]+=1;
            if(i!=arr[1])buc[i][arr[2]][arr[3]][arr[4]][arr[5]]+=1;
        }
        for(long long i=1;i<=9;i++){
            for(long long k=1;k<=5;k++){
                    long long t=k+1;
                    if(t>5)continue;;
                    a[k]+=i;
                    a[t]+=i;
                    if(a[k]>9){
                        a[k]=(a[k]-1)%9;
                    }
                    if(a[t]>9){
                        a[t]=(a[t]-1)%9;
                    }
                    buc[a[1]][a[2]][a[3]][a[4]][a[5]]++;
                    a[k]=arr[k];
                    a[t]=arr[t];
            }
        }
    }
    long long ans=0;
    for(long long i1=0;i1<=9;i1++){
        for(long long i2=0;i2<=9;i2++){
            for(long long i3=0;i3<=9;i3++){
                for(long long i4=0;i4<=9;i4++){
                    for(long long i5=0;i5<=9;i5++){
                        if(buc[i1][i2][i3][i4][i5]==n){
                            ans++;
                        }
                    }
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
