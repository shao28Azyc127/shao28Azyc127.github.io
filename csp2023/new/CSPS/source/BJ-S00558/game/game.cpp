#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int n,ans=0;
string s;
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    scanf("%d",&n);
    cin>>s;
    for(int i=0;i<=25;i++){
        string s1="\0";
        s1+=(char)'a'+i;
        s1+=s1;
        if(s.find(s1)>=0&&s.find(s1)<n)ans++;
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
