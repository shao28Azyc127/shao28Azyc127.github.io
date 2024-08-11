#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,d,s,o,tp;
queue<ll> a;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>n;
    for(ll i=1;i<=n;i++){
        a.push(i);
    }while(!a.empty()){
        s++;
        o=3;
        tp=a.size();
        while(tp--){
            if(o==3){
                if(a.front()==n) d=s;
                a.pop();
                o=0;
            }else{
                a.push(a.front());
                a.pop();
            }o++;
        }
    }
    cout<<s<<" "<<d;
    return 0;
}
