#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=3010;
ll n,m,cnt_1,cnt,cnti,cnta;
bool flag_1;
string s[N],si[N],sa[N],smi_1;
int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>s[i];
        si[i]=s[i];
        sa[i]=s[i];
        flag_1=1;
        if(m==1){
            if(i==1){
                smi_1=s[i];
                continue;
            }
            if(smi_1==s[i]){
                flag_1=0;
            }
            if(smi_1>s[i]){
                smi_1=s[i];
                flag_1=1;
            }
            continue;
        }
        cnt=0;
        while(s[i][cnt]==s[i][cnt+1])cnt++;
        //cout<<cnt<<endl;
        cnti=m-1;
        cnta=cnt+1;
        if(cnt+1==s[i].length())continue;
        for(int j=cnt+1;j<m;j++){
            if(s[i][cnta]<s[i][j])cnta=j;
        }
        for(int j=m-1;j>=cnt+1;j--){
            if(s[i][cnti]>s[i][j])cnti=j;
        }
        if(s[i][0]<s[i][cnta]){
            swap(sa[i][0],sa[i][cnta]);
        }else{
            swap(sa[i][cnt+1],sa[i][cnta]);
        }
        if(s[i][0]>s[i][cnti]){
            swap(si[i][0],si[i][cnti]);
        }else{
            swap(si[i][cnt+1],si[i][cnti]);
        }
    }
    if(n==1){
        cout<<1<<endl;
        return 0;
    }
    if(m==1){
        if(!flag_1){
            for(int i=1;i<=n;i++)cout<<0;
        }else{
            for(int i=1;i<=n;i++){
                if(s[i]==smi_1){
                    cout<<1;
                }else cout<<0;
            }
        }
        cout<<endl;
        return 0;
    }
    for(int i=1;i<=n;i++){
        bool flag=0;
        for(int j=1;j<=n;j++){
            if(i==j)continue;
            if(si[i]>=sa[j]){
                flag=1;
                break;
            }
        }
        cout<<!flag;
    }
    cout<<endl;
    return 0;
}
