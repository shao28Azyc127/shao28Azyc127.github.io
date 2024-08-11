#include<bits/stdc++.h>
using namespace std;
int n,a[6][6],zyz;
bool b[100000],b1[100000];
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++)scanf("%d",&a[i][j]);
        memset(b1,0,sizeof(b1));
        for(int j=1;j<=9;j++)b1[(a[i][1]+j)%10*10000+a[i][2]*1000+a[i][3]*100+a[i][4]*10+a[i][5]]=1;
        for(int j=1;j<=9;j++)b1[a[i][1]*10000+(a[i][2]+j)%10*1000+a[i][3]*100+a[i][4]*10+a[i][5]]=1;
        for(int j=1;j<=9;j++)b1[a[i][1]*10000+a[i][2]*1000+(a[i][3]+j)%10*100+a[i][4]*10+a[i][5]]=1;
        for(int j=1;j<=9;j++)b1[a[i][1]*10000+a[i][2]*1000+a[i][3]*100+(a[i][4]+j)%10*10+a[i][5]]=1;
        for(int j=1;j<=9;j++)b1[a[i][1]*10000+a[i][2]*1000+a[i][3]*100+a[i][4]*10+(a[i][5]+j)%10]=1;
        for(int j=1;j<=9;j++)b1[(a[i][1]+j)%10*10000+(a[i][2]+j)%10*1000+a[i][3]*100+a[i][4]*10+a[i][5]]=1;
        for(int j=1;j<=9;j++)b1[a[i][1]*10000+(a[i][2]+j)%10*1000+(a[i][3]+j)%10*100+a[i][4]*10+a[i][5]]=1;
        for(int j=1;j<=9;j++)b1[a[i][1]*10000+a[i][2]*1000+(a[i][3]+j)%10*100+(a[i][4]+j)%10*10+a[i][5]]=1;
        for(int j=1;j<=9;j++)b1[a[i][1]*10000+a[i][2]*1000+a[i][3]*100+(a[i][4]+j)%10*10+(a[i][5]+j)%10]=1;
        for(int i=1;i<=99999;i++){
            if(b1[i]==0)b[i]=1;
        }
    }
    for(int i=1;i<=99999;i++){
        if(b[i]==0)++zyz;
    }
    printf("%d",zyz);
    return 0;
}
