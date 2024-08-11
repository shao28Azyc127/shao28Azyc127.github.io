#include<iostream>
#include<cstring>
#include<string>

using namespace std;
char s[2000010];
string temp,temp1;
int n,cnt;
bool empty(string s){
    for(int i=0;i<s.length();i++){
        if(s[i]!='N') return 0;
    }
    return 1;
}
string Over(string s){
    int len=s.length();
    for(int i=1;i<len;i++){
        if(s[i]==s[i-1]&&s[i]!='N'){
            s[i]='N';
            s[i-1]='N';
        }
        if(s[i-1]=='N'){
            s[i-1]=s[i];
            s[i]='N';
        }
    }
    return s;
}
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n>>s;
    for(int i=0;i<n;i++){
        for(int j=2;j<n;j+=2){
            int tot=j;
            for(int k=0;k<tot;k++){
                temp[k]=s[i];
                string s1=s,s2=Over(s1);
                while(!empty(s1)&&s1!=s2){
                    s1=s2;
                    s2=Over(s1);
                }
                if(empty(s1)&&empty(s2)) cnt++;
            }
        }
    }
    cnt/=3;
    int cnt1=0;
    while(cnt%2==0){
        cnt/=2;
        cnt1++;
    }
    cout<<cnt1;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
