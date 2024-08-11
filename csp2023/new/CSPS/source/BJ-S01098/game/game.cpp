#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;
int len;
string s;
long long ans=0;
int sum[30][2000010];
bool check(string str){
    while(str!=""){
        bool flag=false;
        for(int i=0;i<str.length();i++){
            if(str[i]==str[i+1]){
                str.replace(i,2,"");
                flag=true;
                break;
            }
        }
        if(flag==false){
            return false;
        }
    }
    return true;
}
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>len;
    cin>>s;
    sum[s[0]-'a'+1][0]=1;
    for(int i=1;i<len;i++){
        for(int j=1;j<=26;j++){
            sum[j][i]=sum[j][i-1];
        }
        sum[s[i]-'a'+1][i]=sum[s[i]-'a'+1][i-1]+1;
    }
    for(int i=0;i<len;i++){
        for(int j=i+1;j<len;j+=2){
            int tmp=0;
            if(j-i+1>=10){
                for(int k=1;k<=26;k++){
                    if((sum[k][j]-sum[k][i-1])%2!=0){
                        tmp++;
                    }
                }
                if(tmp%2==1){
                    tmp-=1;
                }
                j+=tmp;
                if(j>=len){
                    break;
                }
            }
            string str=s.substr(i,j-i+1);
            if(check(str)==true){
                ans++;
            }
        }

    }
    cout<<ans;
    return 0;
}
