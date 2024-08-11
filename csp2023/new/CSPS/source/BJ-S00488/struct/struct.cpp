#include <bits/stdc++.h>

using namespace std;
map <string,int>m,mm;
map<int,string> addre;string aa="long",bb="int",cc="short",dd="byte";
int main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    int opt,x;
    string type,name;
    m[aa]=8,m[bb]=4,m[cc]=2,m[dd]=1;
    int n,f=0;
    cin>>n;
    int cnt=0;
    for(int i=1;i<=n;i++){
        cin>>opt;
        if(opt==1){
            f=1;
            string s;
            cin>>s>>x;
            int ma=0;
            for(int j=1;j<=x;j++){
                cin>>type>>name;
                int t=m[type];
                ma=max(ma,t);
            }
            cout<<ma*x<<' '<<ma<<'\n';
            m[s]=ma;
        }

            if(opt==2){
                cin>>type>>name;
                mm[name]=cnt;
                for(int i=cnt;i<cnt+m[type];i++) addre[i]=name;
                cout<<cnt<<'\n';
                cnt+=m[type];
            }
            if(opt==3){
                cin>>name;
                cout<<mm[name]<<'\n';
            }
            if(opt==4){
                int k;
                cin>>k;
                if(addre[k]!="") cout<<"ERR"<<'\n';
                else cout<<addre[k]<<'\n';
            }
    }
    return 0;
}
