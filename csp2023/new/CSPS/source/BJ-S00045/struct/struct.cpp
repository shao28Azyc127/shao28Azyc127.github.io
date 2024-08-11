#include<bits/stdc++.h>
using namespace std;
#define int long long
struct s2{
    string type,name;
    int len,addr;
};
struct s{
    string sname;
    s2 structi[101];
    int len,dui_qi;
}st[101];
signed main() {
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    int n,cnt=0;
    cin>>n;
    for(int i=1;i<=n;i++) {
        int op;
        cin>>op;
        if(op==1) {
            cnt++;
            int k,maxk=0,ans=0;
            cin>>st[cnt].sname>>k;
            for(int i=1;i<=n;i++) {
                string ti,ni;
                cin>>ti>>ni;
                st[cnt].structi[i].type=ti;
                st[cnt].structi[i].name=ni;
                if(ti=="byte") st[cnt].structi[i].len=1;
                if(ti=="short") st[cnt].structi[i].len=2;
                if(ti=="int") st[cnt].structi[i].len=4;
                if(ti=="long") st[cnt].structi[i].len=8;
                maxk=max(maxk,st[cnt].structi[i].len);
            }
            ans=maxk*k;
            st[cnt].len=ans;
            st[cnt].dui_qi=maxk;
            cout<<st[cnt].len<<" "<<st[cnt].dui_qi<<endl;
        }
        if(op==2) {
            cout<<"RP++"<<endl;
        }
        if(op==3) {
            cout<<"RP++"<<endl;
        }
        if(op==4) {
            cout<<"ERR"<<endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
