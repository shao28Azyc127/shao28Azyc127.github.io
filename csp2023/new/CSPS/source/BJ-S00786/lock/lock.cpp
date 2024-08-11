#include <iostream>
#include<cstdio>
using namespace std;
int n,a[10],last,x,ans;
bool ap[100005];
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;


    int cnt=1;
    for(int j=1;j<=5;j++){
        a[j]=0;
        cin>>a[j];

        x*=10;
        x+=a[j];

    }

    for(int j=1;j<=5;j++){
        int y=x;
        for(int k=1;k<=9;k++){
            y+=cnt;
            if(!ap[y]){
                ans++;
                ap[y]=1;
            }
        }
        cnt*=10;
    }
    cnt=11;
    for(int j=1;j<=4;j++){
        int y=x;
        for(int k=1;k<=9;k++){
            y+=cnt;
            if(!ap[y]){
                ans++;
                ap[y]=1;
            }
        }
        cnt*=10;
    }


    for(int i=2;i<=n;i++){
            cnt=1;
        for(int j=1;j<=5;j++){
        a[j]=0;
        cin>>a[j];

        x*=10;
        x+=a[j];

    }
    bool bp[100005];
    for(int j=1;j<=5;j++){

        int y=x;
        for(int k=1;k<=9;k++){
            y+=cnt;
            if(!bp[y]){
                bp[y]=1;
            }
        }
        cnt*=10;
    }
    cnt=11;
    for(int j=1;j<=4;j++){
        int y=x;
        for(int k=1;k<=9;k++){
            y+=cnt;
            if(!bp[y]){
                bp[y]=1;
            }
        }
        cnt*=10;
    }
    for(int j=0;j<=99999;j++){
        if(ap[j]!=1||bp[j]!=1){
            ans--;
            ap[j]=0;
        }
    }
    }
    cout<<ans;

    return 0;
}
