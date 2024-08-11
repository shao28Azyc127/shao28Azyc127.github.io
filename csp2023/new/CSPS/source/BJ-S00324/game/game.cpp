#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
int n,frt[30][8005],cnt[30],id[8005];
string s;
bool check[8005][8005];
long long ans=0;
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    scanf("%d",&n);
    cin>>s;
    for(int l=2;l<=s.size();l+=2){
        for(int i=0;i+l-1<s.size();i++){
            if(l==2&&s[i]==s[i+l-1]){
                check[i][i+l-1]=1;
                ans++;
                //printf("%d %d\n",i,i+l-1);
                continue;
            }
            if(s[i]==s[i+l-1]&&check[i+1][i+l-2]==1){
                check[i][i+l-1]=1;
                ans++;
                //printf("%d %d\n",i,i+l-1);
                continue;
            }
            for(int j=i+1;j<i+l-1;j++){
                if(check[i][j]==1&&check[j+1][i+l-1]==1){
                    check[i][i+l-1]=1;
                    ans++;
                    //printf("%d %d\n",i,i+l-1);
                    break;
                }
            }
        }
    }
    printf("%lld",ans);
    return 0;
}
/*
8
accabccb
*/
