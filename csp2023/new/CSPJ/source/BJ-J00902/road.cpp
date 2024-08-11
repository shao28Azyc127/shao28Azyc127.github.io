#include <iostream>
#include <cmath>
using namespace std;
struct node{
    int v,a;
};
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d;
    int left=0;
    cin>>n>>d;
    int now=1,cheap=1,m=0;
    node road[100030];
    for(int i=1;i<n;i++)
        cin>>road[i].v;
    for(int i=1;i<n;i++)
        cin>>road[i].a;
    while(now<n){
        if(road[now].v<left){
            left-=road[now].v;
            now++;
            if(road[now].a<road[cheap].a)cheap=now;
        }else{
            m+=ceil(((road[now].v-left)/(float)d))*road[cheap].a;
            left=(road[now].v-left)%d;
            now++;
            if(road[now].a<road[cheap].a)cheap=now;
            // cout<<"now:"<<now<<" cheap:"<<cheap<<" left:"<<left<<" m:"<<m<<endl;
        }
    }
    cout<<m<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}