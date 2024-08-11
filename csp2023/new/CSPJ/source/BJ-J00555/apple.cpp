#include<iostream>
#include<queue>
using namespace std;
queue<int> q;
int main() {
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) {
        q.push(i);
    }
    int ans=0,pickn;
    while(!q.empty()) {
        ans++;
        int len=q.size();
        for(int i=0;i<len;i++) {
            int temp=q.front();
            cout<<q.front()<<endl;
            q.pop();
            cout<<q.front()<<endl;
            if(i%3==0) {
                if(temp==n) pickn=ans;
            }
            else q.push(temp);
        }
    }
    cout<<ans<<" "<<pickn<<endl;
    return 0;
}
