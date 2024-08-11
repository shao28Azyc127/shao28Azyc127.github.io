#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e6+10;
int n,m;
ll a[maxn],pos[maxn],newpos[maxn];
char c[maxn],s[maxn];

int main(){
    memset(pos,0,sizeof(pos));
    memset(newpos,0,sizeof(newpos));
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);

    scanf("%d",&n);
    scanf("%s",c+1);

    ll ans=0;
    while(1){
        int cnt=0;
        ll sum1=0,sum2=0;
        int ps1=0,ps2=0;
        int ls=0;
        for(int i=1;i<=n;i++){
            if(c[i]==c[i+1]&&i<n){
                //cout<<ls<<" "<<c[i]<<" "<<i<<endl;
                newpos[cnt+1]+=pos[i];
                if(ls!=i-1||i==1) newpos[cnt+1]++,ls=i;
                if(i%2==0) ans+=sum2+1,sum2++;
                else ans+=sum1+1,sum1++;
                if(i%2==0&&ps2==0) ps2=i;
                if(i%2==1&&ps1==0) ps1=i;
                //cout<<i<<" "<<newpos[cnt+1]<<" "<<cnt<<endl;
                //ls=i;
                continue;
            }
            ls=0;
            //cout<<pos[i]<<" "<<ans<<" ";
            if(i%2==0) ans+=pos[i]*pos[ps2]+(pos[i]+pos[ps2])*sum2,sum2=0,ps2=0;
            else ans+=pos[i]*pos[ps1]+(pos[i]+pos[ps1])*sum1,sum1=0,ps1=0;
            //cout<<ans<<" "<<i<<endl;
            if(c[i]==c[i-1]) continue;
            s[++cnt]=c[i];
        }
        //cout<<pos[n+1]<<" "<<pos[ps2]<<" ";
        if(n%2==0) ans+=(pos[n+1]+pos[ps1])*sum1+pos[n+1]*pos[ps1];
        else ans+=(pos[n+1]+pos[ps2])*sum2+pos[n+1]*pos[ps2];
        //cout<<ans<<" "<<n+1<<endl;
        if(cnt==n||cnt==0) break;

        for(int i=1;i<=cnt;i++){
            c[i]=s[i];
            pos[i]=newpos[i];
            //if(pos[i]) pos[i]++;
            newpos[i]=0;
        }
        pos[cnt+1]=newpos[cnt+1];
        //pos[cnt+1]++;
        n=cnt;
    }
    printf("%lld",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
//Ranger_HoFr AK IOI!!!!
//zyctc AK IOI!!!!!
//CZT AK IOI!!!!!
