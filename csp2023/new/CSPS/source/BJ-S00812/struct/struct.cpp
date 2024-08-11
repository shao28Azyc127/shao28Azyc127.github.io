#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    int n,x,z;;
    string y;
    cin>>n;
    int sum=0;
    for(int i=1;i<=n;i++){
        cin>>x>>y>>z;
            int duiq=-1;
        for(int j=1;j<=z;j++){
            string s,na;
            cin>>s>>na;
            if(s=="short"){
                sum+=2;
                duiq=max(duiq,2);
            }
            if(s=="int"){
                sum+=4;
                duiq=max(duiq,4);
            }
            if(s=="long"){
                sum+=8;
                duiq=max(duiq,8);
            }
            if(s=="byte"){
                sum+=1;
                duiq=max(duiq,1);
            }

        }
        if(sum%duiq==0){
            cout<<sum<<' '<<duiq;
        }
        else{
            cout<<((sum/duiq)+1)*duiq<<' '<<duiq;
        }
    }
return 0;
}
