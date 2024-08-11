#include<iostream>
using namespace std;
int n,d,money;
struct node{
    int num;
    int v;
    int a;
}t[100010];
bool cmp(node x,node y){
    return x.a<y.a;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<=n;i++) t[i].num=i;
    for(int i=1;i<n;i++) cin>>t[i].v;
    for(int i=1;i<=n;i++) cin>>t[i].a;
    for(int i=1;i<=n;i++){
        int p=t[i].v,q=0;
        while(t[i].a<t[i+1].a) p+=t[i+1].v;
        while(q<p){
            money+=t[i].a;
            q+=d;
        }
    }
    cout<<money;
    fclose(stdin);
    fclose(stdout);
    return 0;
}