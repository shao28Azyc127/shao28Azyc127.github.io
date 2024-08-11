#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ld long double
using namespace std;
int n;
int a[11][11];
bool buc[11][100011];
int tmp1;
int ans;
int inline f1(int x,int k,int d){
    int re=0;
    int tmp[11]={};
    for(int i=1;i<=5;i++) tmp[i]=a[x][i];
    tmp[k]=(tmp[k]+d)%10;
    for(int i=5;i>=1;i--){
        re*=10;
        re+=tmp[i];
    }
    return re;
}
int inline f2(int x,int k,int d){
    int re=0;
    int tmp[11]={};
    for(int i=1;i<=5;i++) tmp[i]=a[x][i];
    tmp[k]=(tmp[k]+d)%10;
    tmp[k+1]=(tmp[k+1]+d)%10;
    for(int i=5;i>=1;i--){
        re*=10;
        re+=tmp[i];
    }
    return re;
}
int main(){
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++) for(int j=1;j<=5;j++) cin >> a[i][j];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=9;j++){
            for(int k=1;k<=5;k++){
                tmp1=f1(i,k,j);
                buc[i][tmp1]=true;
            }
            for(int k=1;k<=4;k++){
                tmp1=f2(i,k,j);
                buc[i][tmp1]=true;
            }
        }
    }
    for(int i=0;i<=100000;i++){
        bool can=true;
        for(int j=1;j<=n;j++) can=can&buc[j][i];
        if(can) ans++;
    }
    cout << ans << endl;
	return 0;
}
