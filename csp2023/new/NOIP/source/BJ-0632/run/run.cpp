#include<iostream>
#include<algorithm>
#include<string>
#include<fstream>
using namespace std;
#define N 1001
int c,t;
int dp[N][100001];
struct work{
int start;
int time;
int award;

};int ans;
work works[N];
bool cmp(work a,work b){
 return a.time<b.time;
}
int main(){
    in.open("run.in");
    out.open("run.out");
//dp[i][j] 这次激活 ·持续(谁的)步数
//dp[i][j]=dp[i-1][j-(x(i)-x(i-1))]-v*(x(i)-x(i-1))+reward[i];
//=dp[i-2][j-(x(i)-x(i-2))]-v*(x(i)-x(i-2))+reward[i];

in>>c>>t;
for(int ii=0;ii<t;ii++){
    int n,m,k,d;
    in>>n>>m>>k>>d;
    for(int j=1;j<=m;j++){
        in>>works[j].start>>works[j].time>>works[j].award;
    }
    sort(works,works+m,cmp);

    for(int i=1;i<=m;i++){
        for(int jj=i;jj>=1;jj--){
            int delta_x=works[i].start-works[jj].start;
          for(int j=delta_x;j<=k;j++){
            dp[i][j]=dp[jj][j-delta_x]-delta_x*d;
            if(j>=works[i].time) dp[i][j]+=works[i].award;
            ans=max(ans,dp[i][j]);
         }
        }
    }
    out<<ans<<endl;
}






}
