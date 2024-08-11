#include<iostream>
using namespace std;
string s;
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int n;
    cin>>n;
    cin>>s;
    int cnt = 0;
    int an = 0, bn = 0;
    bool flag = true;
    for(int i=0;i<n;i++){
        if(s[i] != 'a'&&s[i] !='b') flag = false;
        if(s[i]=='a') an++;
        if(s[i]=='b') bn++;
    }
    for(int i=0;i<n;i++){
        if(s[i]==s[i+1]){
            cnt++;
            if(s[i-1]==s[i+2]){
                cnt++;
            }
        }
    }
    cout<<cnt+1<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}