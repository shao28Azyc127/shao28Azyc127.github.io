#include<bits/stdc++.h>
using namespace std;
int s[10][10][10][10][10];
int n;
int abss(int x){
    if(x<0) return x+10;
    return x;
}
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int a,b,c,d,e;
    memset(s,0,sizeof(s));
    scanf("%d",&n);
    int cnt=0;
    for(int ss=1;ss<=n;ss++){
        scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
        s[a][b][c][d][e]=-1e9;
        for(int i=0;i<=9;i++){
            s[i][b][c][d][e]++;
            if(s[i][b][c][d][e]==n) cnt++;
        }
        for(int i=0;i<=9;i++){
            s[a][i][c][d][e]++;
            if(s[a][i][c][d][e]==n) cnt++;
        }
        for(int i=0;i<=9;i++){
            s[a][b][i][d][e]++;
            if(s[a][b][i][d][e]==n) cnt++;
        }
        for(int i=0;i<=9;i++){
            s[a][b][c][i][e]++;
            if(s[a][b][c][i][e]==n) cnt++;
        }
        for(int i=0;i<=9;i++){
            s[a][b][c][d][i]++;
            if(s[a][b][c][d][i]==n) cnt++;
        }
        for(int k=1;k<=9;k++){
            s[abss(a-k)][abss(b-k)][c][d][e]++;
            if(s[abss(a-k)][abss(b-k)][c][d][e]==n) cnt++;
            s[a][abss(b-k)][abss(c-k)][d][e]++;
            if(s[a][abss(b-k)][abss(c-k)][d][e]==n) cnt++;
            s[a][b][abss(c-k)][abss(d-k)][e]++;
            if(s[a][b][abss(c-k)][abss(d-k)][e]==n) cnt++;
            s[a][b][c][abss(d-k)][abss(e-k)]++;
            if(s[a][b][c][abss(d-k)][abss(e-k)]==n) cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}
