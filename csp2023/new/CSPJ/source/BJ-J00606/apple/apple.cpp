#include<bits/stdc++.h>
using namespace std;
int a;
stack<int> n,m;
int t,t1,t2,t3;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    scanf("%d",&a);
    for(int i=1;i<=a;i++){
        if(i%3==1&&i==a){
            t=1;
            continue;
        }
        else if(i%3==1) continue;
        n.push(i);
    }
    while(n.size()>0){
        t3=n.top();n.pop();
        m.push(t3);
    }
    int j=2;
    while(m.size()>0){
        while(m.size()>0){
            if(m.top()==a)t=j;
            m.pop();if(m.size()==0)break;
            t1=m.top();m.pop();n.push(t1);if(m.size()==0)break;
            t2=m.top();m.pop();n.push(t2);if(m.size()==0)break;
        }
        while(n.size()>0){
            t3=n.top();n.pop();
            m.push(t3);
        }
        j++;
    }
    printf("%d %d",j-1,t);
    return 0;
}
