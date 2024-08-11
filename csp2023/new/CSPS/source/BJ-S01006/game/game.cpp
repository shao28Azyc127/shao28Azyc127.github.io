#include<iostream>
#include<cstdio>
#include<stack>
using namespace std;
int n;
long long ans;
string str;
stack<char> s;
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);

    scanf("%d",&n);
    cin >> str;
    for(int i=0;i<str.size();i++){
        for(int j=1;j<str.size()-i;j+=2){
            if(j==1 && str[i]!=str[i+1]) continue;
            if(j==1){
                ans++;
                continue;
            }
            for(int k=i;k<=i+j;k++){
                if(!s.empty()){
                    if(s.top()!=str[k]) s.push(str[k]);
                    else s.pop();
                }else s.push(str[k]);
            }
            if(s.empty()) ans++;
            else while(!s.empty()) s.pop();
        }
    }
    printf("%lld",ans);

    fclose(stdin);
    fclose(stdout);
    return 0;
}
