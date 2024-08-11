#include <iostream>
#include <algorithm>
using namespace std;
int space[100005],cur=0;
string dic[1005];
void fillin(int l,int c){
    for (int i=cur;i<=cur+l-1;i++) space[i]=c;
    cur+=l;
    return;
}
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    int q;
    cin>>q;
    int dic_cur=0;
    while (q--){
        int op;
        cin>>op;
        if (op==2){
            string t,n;
            cin>>t>>n;
            dic[++dic_cur]=n;
            cout<<cur<<endl;
            if (t=="byte") fillin(1,dic_cur);
            if (t=="short") fillin(2,dic_cur);
            if (t=="int") fillin(4,dic_cur);
            if (t=="long") fillin(8,dic_cur);
        }
        if (op==3){
            string s;
            int findc;
            cin>>s;
            for (int i=1;i<=dic_cur;i++){
                if (dic[i]==s){
                    findc=i;
                    break;
                }
            }
            for (int i=1;i<=cur;i++){
                if (space[i]==findc){
                    cout<<i<<endl;
                    break;
                }
            }
        }
        if (op==4){
            int n;
            cin>>n;
            cout<<dic[space[n]]<<endl;
        }
    }
    return 0;
}
