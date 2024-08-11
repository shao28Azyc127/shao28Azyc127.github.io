#include<bits/stdc++.h>
//const int maxn=;
using namespace std;
int n;
int a[10][5],b[6];
int cnt;
bool check(int cur){
    int dif[6],tot=0;
    for(int i=1;i<=5;i++)
        if(a[cur][i]!=b[i])dif[++tot]=i;
    if(tot>=3)return false;
    if(tot==1){return true;}
    if(dif[1]+1!=dif[2])return false;
    if(b[dif[1]]-b[dif[2]]==a[cur][dif[1]]-a[cur][dif[2]]){return true;}
    b[dif[1]]+=10;
    if(b[dif[1]]-b[dif[2]]==a[cur][dif[1]]-a[cur][dif[2]]){return true;}
    b[dif[1]]-=10;
    b[dif[2]]+=10;
    if(b[dif[1]]-b[dif[2]]==a[cur][dif[1]]-a[cur][dif[2]]){return true;}
    return false;
}
int main(){
  freopen("lock.in","r",stdin);
  freopen("lock.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=5;j++)scanf("%d",&a[i][j]);
    for(int i=0;i<=99999;i++){
            int fi=i;
        for(int j=5;j>=1;j--){
            b[j]=fi%10;
            fi/=10;
        }
        int f=0;
        for(int j=1;j<=n;j++)if(!check(j)){
            f=1;continue;
        }
  //      for(int j=1;j<=5;j++){
  //          cout<<b[j]<<' ';
  //      }
   //     cout<<endl;
        if(f==0){
            cnt++;
 //           for(int j=1;j<=5;j++){
 //               cout<<b[j]<<' ';
 //           }
 //           cout<<endl;
        }
    }
//    cout<<cnt1<<' '<<cnt2<<endl;
    printf("%d\n",cnt);
    return 0;
}
