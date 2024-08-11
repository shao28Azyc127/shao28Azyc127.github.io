#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
using namespace std;

int n;
string str;
int ans=0;

int findnext(int rp,string s)
{
    rp++;
    while(s[rp]=='0') rp++;
    return rp;
}

void xc(int pos1,int pos2)
{
    string s;
    for(int i=pos1;i<=pos2;i++){
        s+=str[i];
    }
    if(s.length()==2 && s[0]==s[1]){
        ans++;
        return;
    }

    bool flag=true;
    while(flag){
        flag=false;

        for(int i=0;i<s.length();i++){
            if(s[i]=='0') continue;
            int nexti=findnext(i,s);
            if(s[i]==s[nexti]){
                flag=true;
                s[i]='0';
                s[nexti]='0';
            }
        }
    }
    for(int i=0;i<s.length();i++){
        if(s[i]!='0'){
            return;
        }
    }
    ans++;

//    cout<<s<<endl;
}

int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;
    cin>>str;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            xc(i,j);
        }
    }
    cout<<ans<<endl;

    return 0;
}
