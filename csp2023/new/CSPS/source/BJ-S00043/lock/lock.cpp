#include<bits/stdc++.h>
using namespace std;
const int N=8,DIGIT=10;
bool num[6][DIGIT];
struct Lock{
    int a,b,c,d,e;
}lock[N];
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<=DIGIT;i++){
        num[1][i]=num[2][i]=num[3][i]=num[4][i]=num[5][i]=true;
    }
    for(int i=0;i<n;i++){
        int a,b,c,d,e;
        cin>>a>>b>>c>>d>>e;
        if(n==1){
            int cnt1=0,cnt2=0;
            cnt1=9+9+9+9+9;
            cnt2=9+9+9+9;
            int cnt=cnt1+cnt2;
            cout<<cnt;
        }else{

        }
    }
    return 0;
}
