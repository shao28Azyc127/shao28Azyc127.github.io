#include <bits/stdc++.h>
using namespace std;
int n,k[10],ans;
map<string,int> mp;
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    scanf("%d",&n);
    if(n==1){
        for(int i=1;i<=n;i++) scanf("%d",&k[i]);
        cout<<5*9+4*9;
        return 0;
    }
    for(int i=1;i<=n;i++){
        string s;
        for(int j=1;j<=5;j++){
            int x;
            scanf("%d",&x);
            s=s+char('0'+x);
        }
        for(int j=0;j<5;j++){
            for(int k=0;k<10;k++){
                if(k==s[j]-'0') continue;
                string ss;
                for(int l=0;l<j;l++) ss=ss+s[l];
                ss=ss+char('0'+k);
                for(int l=j+1;l<5;l++) ss=ss+s[l];
                mp[ss]++;
            }
        }
        for(int j=0;j<4;j++){
            for(int k=1;k<=9;k++){
                string ss;
                for(int l=0;l<j;l++) ss=ss+s[l];
                ss=ss+char((s[j]-'0'+k)%10+'0');
                ss=ss+char((s[j+1]-'0'+k)%10+'0');
                for(int l=j+2;l<5;l++) ss=ss+s[l];
                mp[ss]++;
            }
        }
    }
    for(int i=1;i<=99999;i++){
        int ss[10];
        string s;
        int x=i,r=5;
        while(x){
            ss[r]=x%10;
            x/=10;
            r--;
        }
        for(int j=1;j<=5;j++) s=s+char(ss[j]+'0');
        if(mp[s]==n) ans++;
    }
    printf("%d",ans);
    return 0;
}
