#include<bits/stdc++.h>
using namespace std;
const int N = 10;
int n,a[N][N],bz[N],ans[N];
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++){
            cin>>a[j][i];
        }
    }
    if(n==1){
        cout<<81<<endl;
        exit(0);
    }
    if(n==2){
        int cnt=0;
        for(int i=1;i<=5;i++){
            if(a[i][1]!=a[i][2]){
                cnt++;
                bz[cnt]=i;
            }
        }
        if(cnt==5){
            cout<<0<<endl;
            exit(0);
        }
        if(cnt==4){
            if(bz[2]!=bz[1]+1){
                cout<<0<<endl;
                exit(0);
            }
            if(bz[4]!=bz[3]+1){
                cout<<0<<endl;
                exit(0);
            }
            int x=a[bz[2]][1]-a[bz[1]][1],y=a[bz[2]][2]-a[bz[1]][2],z=a[bz[4]][1]-a[bz[3]][1],p=a[bz[4]][2]-a[bz[3]][2];
            if(x<0){
                x=a[bz[1]][1]+10-a[bz[2]][1];
            }
            if(y<0){
                x=a[bz[1]][2]+10-a[bz[2]][2];
            }
            if(z<0){
                z=a[bz[3]][1]+10-a[bz[4]][1];
            }
            if(p<0){
                p=a[bz[3]][2]+10-a[bz[4]][2];
            }
            if(x==y&&z==p){
                cout<<2<<endl;
                exit(0);
            }
            else{
                cout<<0<<endl;
                exit(0);
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}