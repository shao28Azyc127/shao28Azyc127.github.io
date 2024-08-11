//思路
//偶数回文可被消除 由可消除组成可消除
#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool HW(string a){
    if(a.length()%2!=0) return false;
    for(int i=0;i<a.length()/2;++i){
        if(a[i]!=a[a.length()-i-1]) return false;
    }
    return true;
}
string cu(string a,int st,int ed){
    string f="";
    for(int i=st;i<ed;++i) f+=a[i];
    return f;
}
ll HH[2000005],idx=0;
ll sum=0;
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int m;
    cin>>m;
    string a;
    cin>>a;
    for(int i=0;i<m;++i)
        for(int j=i+2;j<=m;j+=2)
            if(HW(cu(a,i,j))){
                int a=j-i;
                HH[idx++]=a;
                i=j-2;
                break;
            }
    for(int i=0;i<idx;++i)
        sum+=HH[i]/2;
    sum+=idx*(idx-1)/2;
    cout<<sum;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
