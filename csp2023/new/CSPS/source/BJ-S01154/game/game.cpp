#include<bits/stdc++.h>
using namespace std;
long long n=0,ls=0,m,ans=0;
string s,ss;
int ck(){

    long long l=ss.length(),nx=0;
    bool mv=0;
    for(int i=0;i<l;i++){
            if(i>=1&&mv==0){
                break;
            }else{
                mv=0;
            }
        for(int j=0;j<l-1;j++){
            if(ss.length()<=2){
                if(ss[0]==ss[1]){
                    ss.clear();
                    break;
                }
            }
            if(ss[j]==ss[j+1]){
                //cerr<<j<<"and"<<j+1<<"was del"<<"\n";
                //cerr<<ss[j]<<" "<<ss[j+1]<<"\n";
                ss.erase(j,1);
                //cerr<<ss[j]<<"\n";
                ss.erase(j,1);
                mv=1;
                break;
            }
        }
    }
    for(int oio=0;oio<=ss.length();oio++){
        if(ss[oio]==' '){
            ss.erase(oio,1);
        }
    }
    if(ss.length()>=1){
        //cerr<<"N"<<"\n";
        return 114;
    }else{
        //cerr<<"Y"<<"\n";
        return 514;
    }
    return 0;
}
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;
    cin>>s;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            ss.clear();

            ss=s.substr(i,j+1);
            //cerr<<"sub:"<<ss<<"\n";
            int qwq=ck();
            if(qwq==514){

                ans++;
            }
        }


    }
    cout<<ans<<"\n";
    return 0;
}
