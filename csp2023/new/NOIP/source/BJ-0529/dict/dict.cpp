#include<bits/stdc++.h>
using namespace std;
const int MAXN=3005;
int n,m;

struct Node{
    int x,cnt;
};

Node dp[MAXN];
int cnt[MAXN][28];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);


    cin>>n>>m;//n个字符串长度为m

    if(n==1){
        cout<<1;
        return 0;
    }

    int k,q;
    string s;

    for(int i=1;i<=m;i++){
        dp[i].x=30;
        dp[i].cnt=0;
    }
    //cout<<dp[1].x<<' '<<dp[1].cnt<<endl;

    for(int j=1;j<=n;j++){
        cin>>s;
        //cout<<s<<endl;
        for(int i=0;i<m;i++){
            cnt[j][s[i]-'a'+1]++;
            //cout<<"cnt "<<j<<' '<<s[i]-'a'+1<<'='<<cnt[j][s[i]-'a'+1]<<endl;
        }
        k=1;q=0;
        for(int i=m;i>=1;i--){
            while(k<26&&cnt[j][k]<=q){
                k++;
                q=0;
            }
            q++;
            //cout<<"judge"<<k<<' ';
            if(k<dp[i].x){
                //cout<<'<'<<dp[i].x<<" dp[1].x= "<<k<<endl;
                dp[i].x=k;
                dp[i].cnt=0;
            }
            else if(k==dp[i].x){
                //cout<<'='<<dp[i].x<<" dp[1].cnt= "<<1<<endl;
                dp[i].cnt=1;
            }
        }
    }
    //cout<<dp[1].x<<' '<<dp[1].cnt<<endl;
    bool flag;
    for(int j=1;j<=n;j++){
        k=1;q=0;flag=0;
        for(int i=1;i<=m;i++){
            while(k<26&&cnt[j][k]<=q){
                k++;
                q=0;
            }
            q++;
            if(k<dp[i].x){
                flag=1;
                break;
            }
            if(k>dp[i].x){
                break;
            }
            if(k==dp[i].x&&dp[i].cnt==0){
                flag=1;
                break;
            }
        }

        if(flag){
            cout<<1;
        }
        else{
            cout<<0;
        }
    }
    return 0;
}
