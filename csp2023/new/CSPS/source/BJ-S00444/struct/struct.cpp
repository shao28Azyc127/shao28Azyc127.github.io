#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
const int N=8e3+5;
int n,op,cnt=0,k;
string str,name;
map<string,int> M;
map<int,string> m;
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    scanf("%d",&n);
    while(n--){
        scanf("%d",&op);
        if(op==2){
            cin>>str;
            printf("%d\n",cnt);
            cin>>name;
            M[name]=cnt;
            m[cnt]=name;
            if(str=="byte")
                cnt++;
            else if(str=="short")
                cnt+=2;
            else if(str=="int")
                cnt+=4;
            else    cnt+=8;
        }else if(op==3){
            cin>>name;
            printf("%d",M[name]);
        }else{
            cin>>k;
            cout<<m[k];
        }
    }
    return 0;
}
//aaaabbbb
//a 0
//aa 1
//aaa 2
//aaaa 4
//aaaab 4
//aaaabb
