#include<bits/stdc++.h>
using namespace std;
long long ans,cnt;
int f[2000005],vis[2000005];
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int n;
    cin>>n;
    string s;
    cin>>s;
    for(int i=1;i<n;i++){
        if(s[i-1]==s[i]){
            ++cnt;
            f[i-1]=cnt;
            f[i]=cnt;
        }
    }
    for(int len=4;len<=n;len+=2){
        for(int l=0;l+len-1<n;l++){
            int r=l+len-1;
            if(f[l+1]==f[r-1]&&f[l+1]>0&&s[l]==s[r]){
                ++cnt;
                f[l]=cnt;
                f[r]=cnt;
            }
            if(f[l]!=f[r]&&f[l]&&f[r]){
                int flag=1;
                for(int i=l;i<=r;i++){
                    if(f[i]==0){
                        flag=0;
                        break;
                    }
                    vis[f[i]]++;
                }
            for(int i=1;i<=cnt;i++){
                if(vis[i]%2==1){
                    flag=0;
                    break;
                }
            }
            if(flag==1)cnt++;
            }
        }
    }
    int flag=1;
                for(int i=0;i<n;i++){
                    if(f[i]==0){
                        flag=0;
                        break;
                    }
                    vis[f[i]]++;
                }
            if(flag==1)cnt++;
    cout<<cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}