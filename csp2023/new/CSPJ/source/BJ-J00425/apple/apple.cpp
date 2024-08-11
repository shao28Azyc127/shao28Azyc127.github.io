//佛祖保佑
//佛祖保佑
//佛祖保佑
//佛祖保佑
//佛祖保佑
#include <bits/stdc++.h>
using namespace std;
int n,m,rnd,res;
bool b[1000000010];
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    m=n;
    while(m>0){
        rnd++;
        int cnt=2;
        for(int i=1;i<=n;i++){
            if(b[i]==0){
                cnt++;
            }
            if(cnt==3){
                b[i]=1;
                m--;
                cnt=0;
                if(i==n){
                    res=rnd;
                }
                //cout<<i<<' '<<rnd<<endl;
            }
        }
    }
    cout<<rnd<<' '<<res;
    return 0;
}
//7972437
//90811044
