#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("uqe.in","r",stdin);
freopen("uqe.out","w",stdout);
int t,m;
int a,b,c;
cin>>t>>m;
while(t!=0){
cin>>a>>b>>c;
int d;
d=(b*b) - (4*a*c);
if(d<0){
cout<<"NO";
}else if(d=0){
cout<<-b/2*a;
}else{
    cout<<max((-b+sqrt(d))/(2*a),(-b-sqrt(d))/(2*a))<<endl;


}
t--;
}
fclose(stdin);
fclose(stdout);
return 0;
}

