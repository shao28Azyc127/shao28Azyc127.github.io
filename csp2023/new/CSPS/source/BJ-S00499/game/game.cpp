#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
//f[i],ans end up with i ,

long long jmp[2000050];//must abbccdda
long long sz[2000050];
// merge:[abba][acca]does not merge
long long f[2000050];
string s;
long long a[2000050];
long long ans=0;
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    long long n;
    cin>>n;
    cin>>s;
    for(long long i=1;i<=n;i++){
        a[i]=s[i-1];
        jmp[i]=0;
    }
    for(long long i=2;i<=n;i++){
        jmp[i]=0;
        if(a[i]==a[i-1]){
            jmp[i]=i-1;
        }else{
            long long u,v=i;
            while(true){
                u=jmp[v-1];
                if(u==0)break;
                if(a[u-1]==a[i]){
                    jmp[i]=u-1;
                    break;
                }
                v=u;
            }
            if(jmp[i]==0){
                    continue;
            }
        }
        f[i]=1+f[jmp[i]-1];
        ans+=f[i];
    }
    cout<<ans;
    return 0;
}
