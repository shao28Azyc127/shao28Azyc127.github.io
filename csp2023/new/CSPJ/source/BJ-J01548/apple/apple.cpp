#include<bits/stdc++.h>
using namespace std;
long long num;
queue<long long> q,q2;
int main(){
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    cin>>num;
    int index1=3;
    long long n=num;
    for(int i=1;i<=num;i++){
        if(i%3!=1){
            q.push(i);
        }
        else{
            n--;
        }
    }

    int day=1;
    int res=1;

    int flag=1;
    while(n){
        day++;
        index1=3;
        if(flag==1){
            flag=0;
            while(!q.empty()){
                if(index1%3==0){
                    index1=1;
                    if(q.front()==num){
                        res=day;
                    }
                    // cout<<q.front()<<" ";
                    n--;
                    q.pop();
                }
                else{
                    index1++;
                    q2.push(q.front());
                    q.pop();
                }
            }
        }
        else{
            flag=1;
            while(!q2.empty()){
                if(index1%3==0){
                    index1=1;
                    if(q2.front()==num){
                        res=day;
                    }
                    q2.pop();
                    n--;
                }
                else{
                    index1++;
                    // cout<<q2.front()<<" ";
                    q.push(q2.front());
                    q2.pop();
                }
            }
        }

    }
cout<<day<<" "<<res;
    return 0;
}
