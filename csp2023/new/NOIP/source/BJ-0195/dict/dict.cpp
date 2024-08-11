#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;

string c[3005];
string mn[3005];
bool cmp(char l1,char l2){
    return int(l1)>int(l2);
}
int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    int n,m;
    cin>>n>>m;
    if(n==1){
        cout<<"1";
        return 0;
    }
    string mn1,mn2;
    int id1=0,id2=0;
    for(int i=1;i<=n;++i){
        cin>>c[i];
        sort(c[i].begin(),c[i].end(),cmp);
        if(id1==0)mn1=c[i],id1=i;
        else if(c[i]<mn1)mn1=c[i],id1=i;
        else if(id2==0||c[i]<mn2)mn2=c[i],id2=i;
        for(int j=m-1;j>=0;j--)mn[i]+=c[i][j];
        //cout<<mn[i]<<" "<<s<<endl;
    }
    //cout<<mn1<<" "<<mn2<<"\n";
    for(int i=1;i<=n;i++){
        if(i==id1){
            if(mn[i]<mn2)cout<<"1";
            else cout<<"0";
        }
        else{
            if(mn[i]<mn1)cout<<"1";
            else cout<<"0";
        }
    }
    return 0;
}
