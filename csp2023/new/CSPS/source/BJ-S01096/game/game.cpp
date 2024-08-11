//Orz dls
//Orz wsc
//Orz lhk
//Orz lzc
//Orz xht
//Orz dyh
//Orz xhr
//Orz dhx
#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
string s;
int q_pow(int a,int b){
    int ans=1,p=1000000007;
    while(b){
        if(b&1) ans*=a,ans%=p;
        a=a*a%p,b>>=1;
    }
    return ans;
}
//n<=800
void bf(){
    int sum[30][805];

    memset(sum,0,sizeof sum);
    for(int i=0;i<n;++i){
        for(int j=0;j<26;++j){
            sum[j][i]=sum[j][i-1]+(s[i]==((char)j+'a'));
        }
    }
    int ans=0;
    for(int i=0;i<n;++i){
        for(int j=i+1;j<=n;j+=2){
            stack<char> S;
            int flag=0;
            for(int k=0;k<26;++k){
                if((sum[k][j]-sum[k][i-1])!=0&&(sum[k][j]-sum[k][i-1])%2==1){
                    flag=1;
                    break;
                }
            }
            if(flag) continue;
            for(int k=i;k<=j;++k){
                char top='A';
                if(!S.empty()) top=S.top();
                if(top!=s[k]) S.push(s[k]);
                else S.pop();
            }
            if(S.empty()) ans++;
        }
    }
    cout<<ans<<'\n';
}
int p=1000000007;

long long pw[2000005]={1},hsh[2000005],hsh1[2000005];
long long ghs1(int l,int r){
    return (((hsh[r]-hsh[l-1]+p)%p)*(q_pow(pw[l],p-2)))%p;
}
long long ghs2(int l,int r){
    return (((hsh1[l])%p-(hsh1[r+1])+p)%p*((q_pow(pw[n-r+1],p-2))))%p;
}
void solve(){
    vector<pair<int,int> > v;
    for(int i=0;i<n;++i){
        if(i!=0) pw[i]=(pw[i-1]*131)%p;
        else pw[i]=1;
        hsh[i]=(hsh[i-1]+(s[i]-'a'+1)*pw[i])%p;
    }
    for(int i=n-1;i>=0;--i){
        hsh1[i]=(hsh1[i+1]+(s[i]-'a'+1)*pw[n-i-1])%p;
    }
    for(int i=0;i<n-1;++i){
        if(s[i]==s[i+1]){
            int l=0,AAns=0,r=min(i,(n)-(i+1));
            while(l<=r){
                int mid=l+r>>1;
                if(ghs1(i-mid,i+1+mid)==ghs2(i-mid,i+1+mid)){
                    AAns=mid;
                    l=mid+1;
                }else r=mid-1;

            }
            v.push_back({i,AAns});
        }
    }
    int ans=0;
    for(int i=0;i<v.size()-1;++i){
        int l=v[i].first-v[i].second,r=v[i].first+1+v[i].second,
            l1=v[i+1].first-v[1+i].second,r1=v[1+i].first+1+v[i+1].second;
        ans+=v[i].second+1;
        if(r>=l1){
            ans+=(r-l1+1);
        }
    }
    ans+=v[n-1].second+1;
    cout<<ans<<'\n';
}
signed main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    cin>>n;
    cin>>s;
    if(n<=800){
        bf();
    }
    else
    solve();
    return 0;
}
/*
8
accabccb
*/
