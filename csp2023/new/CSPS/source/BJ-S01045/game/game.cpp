#include<bits/stdc++.h>
using namespace std;
int n;
int cnt;
string s;
queue<int>q;
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n>>s;
    for(int i=2;i<=n;i++){
        /*
        */
        if(s[i]==s[i-1]){
            //q.();
            s[i-1]=s[i+1];
            s[i]=s[i+2];
            cnt++;
        }
        /*if(q.empty()){
            cout<<cnt<<endl;
            return 0;
        }*/
    }
    cout<<cnt<<endl;
    return 0;
}
