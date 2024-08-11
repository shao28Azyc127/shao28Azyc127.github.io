#include <iostream>
#include <map>
#include <unordered_map>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int n,cnt;
unordered_map <string,unsigned long long>s11,s2;//s1:type->duiqi s2:type->space_length
struct node{
    int k;
    unsigned long long s,a;
    int s1[105],a1[105],o[105];
}st[105];
void init(string s,int k){
    cnt++;
    st[cnt].k=k;
    string ty,name;
    for(int i=1;i<=k;i++){
        cin>>ty>>name;
        st[cnt].s1[i]=s2[ty];
        st[cnt].a1[i]=s11[ty];
        st[cnt].a=max(st[cnt].a,1ull*st[cnt].a1[i]);
    }
    for(int i=2;i<=k;i++){
        if((st[cnt].o[i-1]+st[cnt].s1[i-1])%st[cnt].a1[i]==0){
            st[cnt].o[i]=st[cnt].o[i-1]+st[cnt].s1[i-1];
        }else{
            st[cnt].o[i]=((st[cnt].o[i-1]+st[cnt].s1[i-1])/st[cnt].a1[i]+1)*st[cnt].a1[i];
        }
    }
    if((st[cnt].o[k]+st[cnt].s1[k])%st[cnt].a!=0){
        st[cnt].s=((st[cnt].o[k]+st[cnt].s1[k])/st[cnt].a+1)*st[cnt].a;
    }else{
        st[cnt].s=st[cnt].o[k]+st[cnt].s1[k];
    }
    s11[s]=st[cnt].a;
    s2[s]=st[cnt].s;
    cout<<st[cnt].s<<' '<<st[cnt].a<<endl;
    return;
}
int main(){
    s11["byte"]=1;
    s11["short"]=2;
    s11["int"]=4;
    s11["long"]=8;
    s2["byte"]=1;
    s2["short"]=2;
    s2["int"]=4;
    s2["long"]=8;
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    cin>>n;
    while(n--){
        int op;
        cin>>op;
        if(op==1){
            string s;
            int k;
            cin>>s>>k;
            init(s,k);
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
