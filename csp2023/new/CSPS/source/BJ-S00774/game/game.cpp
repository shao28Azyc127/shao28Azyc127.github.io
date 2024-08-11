#include<iostream>
#include<map>
using namespace std;
map<string,bool> m;
bool pd(string str){
    if(m.count(str)){
        return m[str];
    }
    int len=str.size();
    if(len%2==1){
        return m[str]=0;
    }
    if(len==2){
        return m[str]=(str[0]==str[1]);
    }
    if(pd(str.substr(1,len-2))&&str[0]==str[len-1]){
        return m[str]=1;
    }
    for(int i=1;i<len;i++){
        if(pd(str.substr(0,i))&&pd(str.substr(i,len-i))){
            return m[str]=1;
        }
    }
    return m[str]=0;
}
int main(){
    ios::sync_with_stdio(0);
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int len;
    cin>>len;
    string a;
    cin>>a;
    long long ans=0;
    for(int i=0;i<len;i++){
        for(int j=i+1;j<len;j++){
                int dd=pd(a.substr(i,j-i+1));
            ans+=dd;
        }
    }
    cout<<ans;
    return 0;
}
/*rp+=inf*/
