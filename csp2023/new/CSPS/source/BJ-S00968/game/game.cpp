#include <bits/stdc++.h>
using namespace std;
int n,ans=0;
string s;
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin >>n>>s;
    string str,tmp;
    int len;
    int l,r;
    bool flag;
    for(register int len=2;len<=n;len+=2){
        for(register int i=0;i+len-1<n;++i){
            l=i,r=i+len-1;
            str="";
            for(register int i=l;i<=r;++i) str+=s[i];
            len=str.size();
            while(str.size()){
                flag=false;
                for(register int i=0;i<len-1;++i){
                    if(str[i]==str[i+1]){
                        tmp="";
                        for(register int j=0;j<i;++j){
                            tmp+=str[j];
                        }
                        for(register int j=i+2;j<len;++j){
                            tmp+=str[j];
                        }
                        str=tmp;
                        flag=true;
                        len-=2;
                    }
                }
                if(!flag) return false;
            }
            ++ans;
        }
    }
    cout <<ans;
    return 0;
}
