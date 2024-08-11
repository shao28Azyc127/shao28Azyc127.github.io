#include<iostream>
#include<queue>
using namespace std;
queue<int> q;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);

    int n;
    cin>>n;
    int k=0;
    q.push(k);
    for(int i=1;i<=n;i++){
        q.push(i);
    }

    int cnt=0,cn=2,took;
    while(q.empty()==1){
        if(q.front()==0){
            cnt++;
            cn=2;
            q.push(q.front());
            q.pop();
        }

        else if(cn==2){
            cn=0;
            if(q.front()==n)took=cnt;
            q.pop();
        }else{
            q.push(q.front());
            q.pop();
            cn++;
        }
    }

    cout<<cnt<<" "<<took;
    fclose(stdin);
    fclose(stdout);
}