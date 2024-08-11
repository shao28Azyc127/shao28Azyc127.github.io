#include<bits/stdc++.h>
using namespace std;
int main(){
        int c,t,m,n,num=0,origin[1145],exec[1145],temp[1145],ix,jx;
        char v;
        freopen("tribool.in","r",stdin);
        freopen("tribool.out","w",stdout);
        cin>>c>>t;
while(t--){
        num = 0;
        cin>>n>>m;
        for(int i=1;i<=m;i++){
                cin>>v;
                if (v == 'U'){cin>>ix;num++;}
                else if (v == 'T' || v == 'F'){cin>>ix;}
                else if (v == '+' || v == '-'){cin>>ix>>jx;}
        }
        cout<<num<<endl;




}
return 0;}



// Nov.18, 2023 NOIP
//By Tim Kevin
//Beijing, P.R.China
