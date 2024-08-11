#include <bits/stdc++.h>
using namespace std;
const int N=15;
int n,a[N][5],pw[6];
unordered_set <int> P;
unordered_map <int,int> S;
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=0;j<5;j++)
            cin>>a[i][j];
    pw[0]=1;
    for(int j=1;j<=5;j++)
        pw[j]=pw[j-1]*10;
    int tot=0;
    for(int i=1;i<=n;i++){
        P.clear();
        for(int j=0;j<5;j++){
            int now=0;
            for(int k=0;k<5;k++){
                if(k!=j)now+=pw[k]*a[i][k];
            }
            for(int k=0;k<=9;k++){
                if(k==a[i][j])continue;
                now+=pw[j]*k;
                tot++;
                P.insert(now);
                now-=pw[j]*k;
            }
        }
        for(int j=0;j<4;j++){
            int now=0;
            for(int k=0;k<5;k++){
                if(k!=j&&k!=j+1)now+=pw[k]*a[i][k];
            }
            for(int k=1;k<=9;k++){
                now+=pw[j]*((a[i][j]+k)%10)+pw[j+1]*((a[i][j+1]+k)%10);
                P.insert(now);
                now-=pw[j]*((a[i][j]+k)%10)+pw[j+1]*((a[i][j+1]+k)%10);
            }
        }
        for(auto it:P)S[it]++;
    }
    //cout<<tot<<endl;
    int cnt=0;
    for(auto it:S){
        //cout<<it.first<<" "<<it.second<<endl;
        if(it.second==n){
            cnt++;
        }
    }
    cout<<cnt<<endl;
	return 0;
}
