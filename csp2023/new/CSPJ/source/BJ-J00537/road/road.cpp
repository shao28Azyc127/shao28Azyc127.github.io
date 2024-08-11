#include<bits/stdc++.h>
using namespace std;
void al(int x,int n,int all_dis,int gas_have,int have_dis,int d,int pri[],int dis[],int pay){
    if (x<=n-1){
    for(int i=0;all_dis>=(i+gas_have)*d;i++){
        if((i+gas_have)*d>=dis[x+1]+have_dis){
        gas_have+=i;
        have_dis+=dis[x+1];
        pay+=pri[x]*i;
        al(x+1,n,all_dis,gas_have,have_dis,d,pri,dis,pay);
        cout<<pay<<endl;
        }
    }}
}
//int min_p(int pay,int countls){

//}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d;
    cin>>n>>d;
    int dis[n]={},pri[n]={},s_dis=0;
    for(int i=1;i<=n-1;i++){
        cin>>dis[i];
        s_dis+=dis[i];
    }
    for(int i=0;i<=n-1;i++){
        cin>>pri[i];
    }
    int pay=0;
    al(0,n,s_dis,0,0,d,pri,dis,pay);
    return 0;
}
