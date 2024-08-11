#include<iostream>
using namespace std;
int n;
int a[10],b[10][10];
bool solve(){
    int x[10];
    for(int i=1;i<=n;i++){
        int cnt=0;
        for(int j=1;j<=5;j++){
            x[j]=(b[i][j]-a[j]+10)%10;
            if(x[j]!=0) cnt++;
        }
        if(cnt!=1&&cnt!=2) return false;
        bool y=false;
        for(int j=1;j<=4;j++) if(x[j]==x[j+1]&&x[j]!=0) y=true;
        if(cnt==2&&!y) return false;
        cout<<endl;
    }
    return true;
}
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    n--;
    int ans=0;
    cin>>a[1]>>a[2]>>a[3]>>a[4]>>a[5];
    for(int i=1;i<=n;i++) cin>>b[i][1]>>b[i][2]>>b[i][3]>>b[i][4]>>b[i][5];
    for(int i=1;i<=5;i++){
        for(int j=1;j<=9;j++){
            a[i]++;
            a[i]%=10;
            if(solve()) ans++;
        }
        a[i]++;
        a[i]%=10;
    }
    for(int i=1;i<=4;i++){
        for(int j=1;j<=9;j++){
            a[i]++;
            a[i]%=10;
            a[i+1]++;
            a[i+1]%=10;
            if(solve()) ans++;
        }
        a[i]++;
        a[i]%=10;
        a[i+1]++;
        a[i+1]%=10;
    }
    cout<<ans<<endl;
    return 0;
}
