#include<bits/stdc++.h>
using namespace std;
const int N=15;
int n;
struct node{
    int a[5];
    bool operator<(const node& y)const{
        for(int i=0;i<5;++i){
            if(a[i]!=y.a[i])return a[i]<y.a[i];
        }
        return 0;
    }
}ls,to;
map<node,int> ma;
vector<node> z;
set<node> s;
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;++i){
        for(int j=0;j<5;++j){
            cin>>ls.a[j];
        }
        ma[ls]--;
        for(int j=0;j<5;++j){
            for(int k=1;k<10;++k){
                to=ls;
                to.a[j]=(to.a[j]+k)%10;
                ma[to]++;
                z.push_back(to);
            }
        }
        for(int j=0;j<4;++j){
            for(int k=1;k<10;++k){
                to=ls;
                to.a[j]=(to.a[j]+k)%10;
                to.a[j+1]=(to.a[j+1]+k)%10;
                ma[to]++;
                z.push_back(to);
            }
        }
    }
    for(node no:z){
        if(ma[no]==n)s.insert(no);
    }
    cout<<s.size();
    return 0;
}
