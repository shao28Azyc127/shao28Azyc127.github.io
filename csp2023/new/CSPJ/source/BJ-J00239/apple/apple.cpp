#include<bits/stdc++.h>
using namespace std;
queue<long long>a;
long long n,ans1=0,ans2,q=0;
int y=1;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        a.push(i);

    }
    while(!a.empty()){
        y++;q++;


        if(y==2){
            y=0;//cout<<q<<endl;
            long long t=a.front();//cout<<t<<endl;
            if(t==n)ans2=ans1+1;
            a.pop();
        }
        if(q>=a.size()){
                //cout<<endl;
            q=0;y=1;
            ans1++;
        }
        long long t1=a.front();
        a.pop();
        a.push(t1);
    }
    cout<<ans1<<" "<<ans2;
    return 0;



}