#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    int n;
    cin>>n;
    int type;
    string s1,s2;
    int take[105];
    int takemax=0;
    int p;
    int num;
    for(int i=1;i<=n;i++){
        cin>>type;
        if(type==2){
            cin>>s1>>s2;
            if(s1=="int"){take[++p]=4;takemax=max(takemax,take[p]);}
            if(s1=="byte"){take[++p]=1;takemax=max(takemax,take[p]);}
            if(s1=="long"){take[++p]=8;takemax=max(takemax,take[p]);}
        }
        else if(type==3){
            cin>>num;
            cout<<num*takemax-1<<endl;
            }
        else if(type==4){
            cin>>num;
            int near1=(num-1)/takemax;
            int near2=(num-1)%takemax;
            if(take[near1]>=near2){
                cout<<num*takemax-1<<endl;
            }
            else{
                cout<<"ERR"<<endl;
            }
        }
    }
    return 0;
}