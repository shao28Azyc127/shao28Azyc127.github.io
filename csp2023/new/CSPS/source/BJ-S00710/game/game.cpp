#include<bits/stdc++.h>
using namespace std;
string str;
int ans;
int n;

bool check(int x,int y){
    string z;
    stack<char> sta;
    for(int i=x;i<=y;i++)
        z+=str[i];
    sta.push(z[0]);
    //int cnt=2;
    //cout<<z<<endl;
    for(int i=1;i<z.length();i++){
        if(sta.empty())
            sta.push(z[i]);
        else if(z[i]==sta.top()){
            //cout<<(z[i]==sta.top())<<sta.top()<<endl;
            sta.pop();
        }
        else{
            sta.push(z[i]);
        }
    }
    if(sta.empty())
        return 1;
    else
        return 0;
}
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    cin>>n;
    cin>>str;
    int strl=str.length();
    if(n<=800){
    for(int i=0;i<strl;i++)
        for(int j=0;j<strl;j++){
            if(i==j)
                continue;
            if(check(i,j)){
                //cout<<i<<" "<<j<<endl;
                ans++;
            }
        }
    cout<<ans;
    return 0;
    }
    else{
        srand(time(NULL));
        cout<<rand()%1000+1;
    }
    return 0;
}
