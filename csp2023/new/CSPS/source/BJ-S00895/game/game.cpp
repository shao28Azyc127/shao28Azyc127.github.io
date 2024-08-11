#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
const int maxn=2e5+5;
vector<char>a;
int f(int a,int b){
    if(a>b)
        return a-b;
    return b-a;
}
int main(){
  freopen("game.in","r",stdin);
 freopen("game.out","w",stdout);
    int n;
    cin>>n;
    int cnt[maxn][4];
    a.push_back('A');
    for(int i=0;i<n;i++){
        char x;
        cin>>x;
        a.push_back(x);
    }
    a.push_back('Z');
    long long ans=0;
    long long brick=0;
    for(int i=1;i<=n;i++){
        if(a[i]==a[i-1]){
                ans++;
            brick++;
            int left=i-2;
            int right=i+1;
            while(left>0&&right<n+1&&a[left]==a[right]){
                ans++;
                left--;
                right++;
            }
            cnt[brick][0]=left+1;
            cnt[brick][1]=right-1;
            cnt[brick][2]=i-1;
            cnt[brick][3]=i+1;
        }
    }

  //  for(int i=1;i<=brick;i++){
        int x=1;
        while(x<=brick){
            int m=x+1;
            while(cnt[x][1]>=cnt[m][0]-1&&cnt[x][1]<=cnt[m][2]-1&&cnt[m][0]>=cnt[x][3]+1&&m<=brick){
               m++;
                ans+=f(cnt[m][1],cnt[x][0]);
            }
            x++;
        }
 //   }
  //   ans+=sum;
     cout<<ans<<endl;
    return 0;
}
