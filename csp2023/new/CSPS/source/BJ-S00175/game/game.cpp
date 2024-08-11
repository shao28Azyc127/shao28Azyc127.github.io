#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>PII;
long long n;
string a;
PII part[100001];
int add(int t){
    return t*(t+1)/2;
}
map<PII,bool>mp;
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n>>a;
    int len=0;
    int ans=0;
    for(int i=0;i<n-1;i++){
        if(a[i]==a[i+1]){
            int l=i,r=i+1;
            while(a[l]==a[r]&&l>=0&&r<n){
                part[len++]=PII(l,r);
                mp[part[len-1]]=1;
                ans++;
                l--;
                r++;
            }
        }
    }
    for(int i=0;i<len;i++){
        for(int j=0;j<len;j++){
            if(part[i].second==part[j].first-1){
                if(mp[PII(part[i].first,part[j].second)]==0){
                    mp[PII(part[i].first,part[j].second)]=1;
                    ans++;
                    part[len++]=PII(part[i].first,part[j].second);
                }
            }
            if(part[j].second==part[i].first-1){
                if(mp[PII(part[j].first,part[i].second)]==0){
                    mp[PII(part[j].first,part[i].second)]=1;
                    ans++;
                    part[len++]=PII(part[j].first,part[i].second);
                }
            }
        }
    }
    cout<<ans<<endl;
}
