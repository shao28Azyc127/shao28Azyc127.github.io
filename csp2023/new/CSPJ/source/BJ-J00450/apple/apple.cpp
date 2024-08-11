#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    queue<int>q;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        q.push(i);
    }
    int b=0,ans=0,f=q.front()+1,ad;
    while(!q.empty()){
        if(q.front()<f||q.size()==1){
            ans++;
            b=0;
        }
        f=q.front();
        if(b==0){
            if(q.front()==n){
                ad=ans;
            }
           // cout<<q.front()<<" "<<ans<<endl;
            q.pop();
        }
        else{
            q.push(q.front());
            q.pop();
        }
        b=(b+1)%3;
    }
    cout<<ans<<" "<<ad;
    return 0;
}
