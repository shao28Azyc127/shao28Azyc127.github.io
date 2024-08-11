#include <iostream>
#include <cstdio>
#define int long long
using namespace std;
const int N=10;
int n,a[6],cnt[N][N][N][N][N],b[N][N][N][N][N],ans;
signed main() {
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[1]>>a[2]>>a[3]>>a[4]>>a[5];
        b[a[1]][a[2]][a[3]][a[4]][a[5]]=true;
        for(int j=1;j<=9;j++)
            cnt[(a[1]+j)%10][a[2]][a[3]][a[4]][a[5]]++,cnt[(a[1]+j)%10][(a[2]+j)%10][a[3]][a[4]][a[5]]++;
        for(int j=1;j<=9;j++)
            cnt[a[1]][(a[2]+j)%10][a[3]][a[4]][a[5]]++,cnt[a[1]][(a[2]+j)%10][(a[3]+j)%10][a[4]][a[5]]++;
        for(int j=1;j<=9;j++)
            cnt[a[1]][a[2]][(a[3]+j)%10][a[4]][a[5]]++,cnt[a[1]][a[2]][(a[3]+j)%10][(a[4]+j)%10][a[5]]++;
        for(int j=1;j<=9;j++)
            cnt[a[1]][a[2]][a[3]][(a[4]+j)%10][a[5]]++,cnt[a[1]][a[2]][a[3]][(a[4]+j)%10][(a[5]+j)%10]++;
        for(int j=1;j<=9;j++)
            cnt[a[1]][a[2]][a[3]][a[4]][(a[5]+j)%10]++;
    }
    for(int a1=0;a1<=9;a1++)
        for(int a2=0;a2<=9;a2++)
            for(int a3=0;a3<=9;a3++)
                for(int a4=0;a4<=9;a4++)
                    for(int a5=0;a5<=9;a5++)
                        if(!b[a1][a2][a3][a4][a5]&&cnt[a1][a2][a3][a4][a5]==n) ans++;
    cout<<ans;
    return 0;
}
