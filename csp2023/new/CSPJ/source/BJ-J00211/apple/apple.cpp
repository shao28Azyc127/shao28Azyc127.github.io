#include<bits/stdc++.h>
using namespace std;
queue<int>q;
queue<int>q1;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,m=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        q.push(i);
    }
    while(1){
        q.pop();
        if(q.empty()==true){
            m++;
            break;
        }
        for(int i=1;i<=2;i++){
            if(q.empty()==true){
                m++;
                break;
            }
            q1.push(q.front());
            q.pop();
        }
        q1.pop();
        if(q1.empty()==true){
            m++;
            break;
        }
        for(int i=1;i<=2;i++){
            if(q1.empty()==true){
                m++;
                break;
            }
            q.push(q1.front());
            q1.pop();
        }
    }
    cout<<m<<" "<<m;
    return 0;
}