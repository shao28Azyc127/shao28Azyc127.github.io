#include<bits/stdc++.h>
using namespace std;

int n;
queue <int> q;
int ansn=-1;
int d=0;
int m;

int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);

    cin>>n;
    for(int i=1;i<=n;i++){
        //a[i]=i;
        q.push(i);
    }                   //ok!

        int flag=0;
        int n1=n-flag;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n1;j++){
            if(q.front()==n1)    ansn=d+1;
            if(j%3==1){
                //q.pop();
                //if(q.front()==n1)    ansn=d+1;
               // cout<<i<<" "<<q.front()<<"* "<<n1;
                flag++;

            }
            q.pop();
        }
        d++;
        n1-=flag;
        if(n1==0)   break;
     //   cout<<i<<"/"<<n1<<endl;
        for(int j=1;j<=n1;j++){
            q.push(j);
        }
        flag=0;
    }
    if(n%3==1)  ansn=1;
    cout<<d<<" "<<ansn;
    return 0;
}
