#include<bits/stdc++.h>
using namespace std;
int game(string s){
    int l=s.length();
    for(int j=1;j<=s.length();j++){
        int flag=0;
        for(int i=0;i<l-1;i++){
            if(s[i]==s[i+1]){
                for(int k=i+2;k<l;k++){
                    s[k-2]=s[k];
                }
                l-=2;
                flag=1;
            }
        }
        if(flag==0){
            break;
        }
    }
    if(l==0){
        return 1;
    }
    return 0;
}
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int len,ans=0;
    cin>>len;
    string str;
    cin>>str;
    for(int i=0;i<len-1;i++){
        for(int j=i+1;j<=len-1;j++){
            string temp;
            for(int k=i;k<=j;k++){
                temp+=str[k];
            }
            ans+=game(temp);
        }
    }
    cout<<ans;
    return 0;
}
