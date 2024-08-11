#include<bits/stdc++.h>
using namespace std;
int n,ans;
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    string s;
    cin>>n>>s;
    for (int i=1;i<=n;i++)
        for (int j=i;j<=n;j+=2){
            if ((j-i)%2==1) continue;
            stack<char>st;
            bool flag=0;
            for (int k=i;k<=j;k++){
                if (st.size()){
                    if (s[k]==st.top()) st.pop();
                    else{
                        flag=1;
                        break;
                    }
                }
                else st.push(s[k]);
            }
            if (flag==0) ans++;
        }
    cout<<ans/2;
    return 0;
}
