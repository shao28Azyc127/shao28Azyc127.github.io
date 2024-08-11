#include<bits/stdc++.h>
using namespace std;

int n,cnt,a[10][10];
bool ch(int a[],int b[]){
    int tmp=0,sum=0;
    for(int i=0;i<=5;i++){
        if(a[i]-a[i+1]!=b[i]-b[i+1]){
            if(!(a[i]>a[i+1]&&b[i]-b[i+1]+10==a[i]-a[i+1])){
                if(!(a[i]<a[i+1]&&b[i]-b[i+1]-10==a[i]-a[i+1]))tmp++;
            }
        }
        if(a[i]!=b[i])sum++;
    }
    return tmp==2&&sum<=2&&sum;
}
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++)cin>>a[i][j];
        a[i][0]=10;
        a[i][6]=10;
    }
    int b[10];
    for(int i=0;i<=99999;i++){
        b[0]=10;
        b[1]=i%10;
        b[2]=(i/10)%10;
        b[3]=(i/100)%10;
        b[4]=(i/1000)%10;
        b[5]=(i/10000)%10;
        b[6]=10;
        bool f=1;
        for(int o=1;o<=n;o++){
            if(!ch(a[o],b)){
                f=0;
                break;
            }
        }
        if(f){
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
