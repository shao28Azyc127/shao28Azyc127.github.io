#include <iostream>
using namespace std;
const int N=10;
int a[N][10];
int res[N];
int n;
bool check(){
    for(int i=2;i<=n;i++){
        int cnt=0;
        for(int j=1;j<=5;j++){
            if(res[j]!=a[i][j]){
                cnt++;
            }
        }
        if(cnt!=1&&cnt!=2) return false;
        if(cnt==2){
            int f;
            for(int j=1;j<=4;j++){
                if(res[j]!=a[i][j]){
                    f=a[i][j]-res[j];
                    if((res[j+1]+f)%10!=a[i][j+1]) return false;
                }
            }
        }
    }
    return true;
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
    int ans=0;
    for(int i=1;i<=5;i++){
        res[i]=a[1][i];
    }
    for(int i=1;i<=5;i++){
        for(int j=0;j<=9;j++){
            if(j==a[1][i]) continue;
            res[i]=j;
            if(check()) ans++;
            res[i]=a[1][i];
        }
    }
    //cout<<ans<<endl;
    for(int i=1;i<=4;i++){
        for(int j=1;j<=9;j++){ //×ª¶¯·ù¶È
            res[i]=(a[1][i]+j)%10;
            res[i+1]=(a[1][i+1]+j)%10;
            if(check()) ans++;
            res[i]=a[1][i];
            res[i+1]=a[1][i+1];
        }
    }
    cout<<ans<<endl;
    return 0;
}
