#include<bits/stdc++.h>
using namespace std;
int n,p[10][10],a[11],ans;
bool thesame(int a[],int b[]){
    for(int i=1;i<=5;i++) if(a[i]!=b[i]) return false;
    return true;
}
bool check(int a[],int index){
    int b[10];
    for(int i=1;i<=5;i++) b[i]=p[index][i];
    if(n<=2){
        for(int i=1;i<=5;++i){
            for(int j=1;j<=9;++j){
                a[i]=(a[i]+j)%10;
                if(thesame(a,b)) return 1;
                a[i]=(a[i]+10-j)%10;
            }
        }
        return 0;
    }
    else{
        for(int i=1;i<=5;++i){
            for(int j=1;j<=9;++j){
                a[i]=(a[i]+j)%10;
                if(thesame(a,b)) return 1;
                a[i]=(a[i]+10-j)%10;
            }
        }
        for(int i=1;i<=4;++i){
            for(int j=1;j<=9;++j){
                a[i]=(a[i]+j)%10;
                a[i+1]=(a[i+1]+j)%10;
                if(thesame(a,b)) return 1;
                a[i]=(a[i]+10-j)%10;
                a[i+1]=(a[i+1]+10-j)%10;
            }
        }
        return 0;
    }
}
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    if(n==1){
        cout<<81;
        return 0;
    }
    for(int i=1;i<=n;i++) for(int j=1;j<=5;j++) cin>>p[i][j];
    for(a[1]=0;a[1]<=9;++a[1])
        for(a[2]=0;a[2]<=9;++a[2])
            for(a[3]=0;a[3]<=9;++a[3])
                for(a[4]=0;a[4]<=9;++a[4])
                    for(a[5]=0;a[5]<=9;++a[5]){
                        bool flag=true;
                        for(int index=1;index<=n&&flag;++index)if(!check(a,index)) flag=false;
                        if(flag) ans++;
                    }
    cout<<ans;
    return 0;
}