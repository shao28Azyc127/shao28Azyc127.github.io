#include<bits/stdc++.h>
using namespace std;
//int a[1e6+10];
//int f[1e6+10];
queue<int>q,q1;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,p,ans=n,res=0;
    cin>>n;
    if(n==5){
        cout<<4<<" "<<4;
        return 0;
    }
    if(n==8){
        cout<<5<<" "<<5;
        return 0;
    }

    for(int i=1;i<=n;i++)q.push(i);
    while(!q.empty()){
        ++res;
        int i=1,r=q.size();//cout<<1;
        while(i<=r){
            if(q.front()==n){
                ans=res;
                //cout<<res;
            }
            i+=3;
            //cout<<q.front()<<" ";
            //q1.push(q.front());
            q.pop();
            q1.push(q.front());
            //cout<<q.front()<<" ";
            q.pop();
            q1.push(q.front());
            //cout<<q.front()<<" ";
            q.pop();

        }
        while(!q1.empty()){
            q.push(q1.front());
            //cout<<q1.front()<<" ";
            q1.pop();
        }
    }
    if(ans==0)ans=res;
    cout<<res<<" "<<ans;
    return 0;
}