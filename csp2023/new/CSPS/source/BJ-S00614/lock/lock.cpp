#include<bits/stdc++.h>
using namespace std;
map<int, int> m;
int a[10][10];
int trunone(int id, int x, int nx){
    int cnt=0;
    for(int i=1;i<=5;i++){
        if(i==x) cnt=cnt*10+nx;
        else cnt=cnt*10+a[id][i];
    }
    return cnt;
}
int truntwo(int id, int x, int y, int nx, int ny){
    int cnt=0;
    for(int i=1;i<=5;i++){
        if(i==x) cnt=cnt*10+nx;
        else if(i==y) cnt=cnt*10+ny;
        else cnt=cnt*10+a[id][i];
    }
    return cnt;
}
int main(){
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    int n, ans=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++){
            cin>>a[i][j];
        }
    }
    int num;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++){
            num=0;
            for(int k=1;k<=9;k++){
                num=trunone(i, j, (a[i][j]+k)%10);
                m[num]++;
                if(i==n&&m[num]==n) ans++;
            }
        }
        for(int j=1;j<5;j++){
            num=0;
            for(int k=1;k<=9;k++){
                int nx=(a[i][j]+k)%10, ny=(a[i][j+1]+k)%10;
                num=truntwo(i, j, j+1, nx, ny);
                m[num]++;
                if(i==n&&m[num]==n) ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}
