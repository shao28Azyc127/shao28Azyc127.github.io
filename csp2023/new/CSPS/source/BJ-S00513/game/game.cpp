#include<bits/stdc++.h>
using namespace std;
string n;
int ans;
bool same(int a,int b,string c){
    for(int i=1;i<=c.length();i++){
        if(c[a+i]==c[b-1]){
            return false;
        }
    }

    return true;
}
int game(int p,string q){
    for(int i=1;i<=p;i++){
        if(q[i]==q[i+1]){
            ans++;
            continue;
        }
        /*for(int j=2;j<=p;j++){
            if(same(i,i+j,q)||same(i+1,j-1,q)){
                ans++;
            }
        }*/
    }
    return ans;
}

int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;
    string cop=n;
    int len=n.length();
    cout<<game(len,n);
    return 0;
}