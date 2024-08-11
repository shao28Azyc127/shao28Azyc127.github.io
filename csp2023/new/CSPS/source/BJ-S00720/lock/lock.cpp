#include<bits/stdc++.h>
#define MAX 100000
using namespace std;

int n;
int lock_[10][5];
int a[10][10][10][10][10];

int ax(int x){
    int y=1;
    for(int i=0;i<x;i++) y*=10;
    return y;
}

int f(int num[]){
    for(int i=1;i<10;i++){
        a[(num[0]+i)%10][(num[1])%10][(num[2])%10][(num[3])%10][(num[4])%10]++;
        a[(num[0])%10][(num[1]+i)%10][(num[2])%10][(num[3])%10][(num[4])%10]++;
        a[(num[0])%10][(num[1])%10][(num[2]+i)%10][(num[3])%10][(num[4])%10]++;
        a[(num[0])%10][(num[1])%10][(num[2])%10][(num[3]+i)%10][(num[4])%10]++;
        a[(num[0])%10][(num[1])%10][(num[2])%10][(num[3])%10][(num[4]+i)%10]++;

        a[(num[0]+i)%10][(num[1]+i)%10][(num[2])%10][(num[3])%10][(num[4])%10]++;
        a[(num[0])%10][(num[1]+i)%10][(num[2]+i)%10][(num[3])%10][(num[4])%10]++;
        a[(num[0])%10][(num[1])%10][(num[2]+i)%10][(num[3]+i)%10][(num[4])%10]++;
        a[(num[0])%10][(num[1])%10][(num[2])%10][(num[3]+i)%10][(num[4]+i)%10]++;
    }
    return 0;
}

int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);

    cin>>n;
    for(int i=1;i<=n;i++) for(int j=4;j>=0;j--) cin>>lock_[i][j];
    if(n==1){
        cout<<81;
        return 0;
    }
    for(int i=1;i<=n;i++){
        f(lock_[i]);
    }
    int ans=0;
    for(int b=0;b<10;b++) for(int c=0;c<10;c++) for(int d=0;d<10;d++) for(int e=0;e<10;e++) for(int g=0;g<10;g++) if(a[b][c][d][e][g]==n) ans++;
    cout<<ans;

    return 0;
}
