#include <bits/stdc++.h>
using namespace std;
int n,ans;
string str;
char a[2000001];
bool is_hui(string s){
    bool flag=true;
    int r=s.length(),l=0;
    while(l<=r){
        if(s[l]!=s[r]){
            flag=false;
            break;
        }
        l++;
        r--;
    }
    return flag;
}
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;
    cin>>str;
    for(int i=0;i<n;i++){
        a[i]=str[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<(n-i);j++){
            bool flag[2000001];
            memset(flag,true,sizeof(flag));
            if(i==2){
                if(a[j]==a[j+1]){
                    ans++;
                }
                break;
            }
            if(i%2==1){
                break;
            }
            for(int k=j;k<(j+i-1);k++){
                if(a[k]==a[k+1]){
                    flag[k]=false;
                    flag[k+1]=false;
                    k++;
                }
            }
            string sss;
            for(int k=j,x=0;k<(j+i);k++){
                if(flag[k]==true){
                    sss[x]=a[k];
                    x++;
                }
            }
            if(is_hui(sss)==true){
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}