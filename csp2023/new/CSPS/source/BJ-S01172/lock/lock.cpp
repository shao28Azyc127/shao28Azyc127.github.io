#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,a[10],haxi[N],x,b[10],t1,t2,ans;
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=0;j<5;j++)scanf("%d",&a[j]);
        for(int j=0;j<5;j++){
            for(int k=1;k<=9;k++){
                x=0;
                t1=a[j];a[j]=(a[j]+k)%10;
                for(int l=0;l<5;l++){
                    x=x*10+a[l];
                }
                a[j]=t1;haxi[x]++;
            }
        }
        for(int j=0;j<4;j++){
            for(int k=1;k<=9;k++){
                x=0;t2=a[j+1];a[j+1]=(a[j+1]+k)%10;
                t1=a[j];a[j]=(a[j]+k)%10;
                for(int l=0;l<5;l++){
                    x=x*10+a[l];
                }
                a[j]=t1;a[j+1]=t2;haxi[x]++;
            }
        }
    }
    for(int i=0;i<=99999;i++){
        if(haxi[i]>=n)ans++;
    }
    printf("%d",ans);
    return 0;
}
