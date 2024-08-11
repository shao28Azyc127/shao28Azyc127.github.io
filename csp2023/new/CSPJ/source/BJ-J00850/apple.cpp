#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
int n,bz[N],cnt,now,tot,ans,siz,siz_2;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    siz=n;
    for(int i=1;i<=n;i++) bz[i]=i;
    while(cnt<n){
        tot++;
        int p=0,f=0,siz_2=0;
        for(int i=1;i<=siz;i++){
            if(p%3==0){
                f++;
                p++;
                if(bz[i]==n) ans=tot;
            }
            else{
                p++;
                bz[i-f]=bz[i];
                siz_2=max(siz_2,i-f);
            }
        }
        siz=siz_2;
        cnt=cnt+f;
    }
    cout<<tot<<" "<<ans<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
