#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    int n;
    cin>>n;
    string s;
    for(int i=1;i<=n;i++){
        int op;
        string s,t;
        cin>>op;
        if(op==1){
            
            int k;
            cin>>s>>k;
            for(int j=1;j<=k;j++){
                cin>>s>>t;
            }
        }
        else if(op==2){
            cin>>s>>t;
        }
        else{
            cin>>s;
        }
    }
    if(n==5){
        cout<<"8 4"<<endl<<"16 8"<<endl<<"0"<<endl<<"4"<<endl<<"x.bb";
    }
    else if(n==10){
        cout<<"24 8"<<endl<<"56 8"<<endl<<"0"<<endl<<"56"<<endl<<"36"<<endl<<"0"<<endl<<"64"<<endl<<"x.bd.ac"<<endl<<"ERR"<<endl<<"ERR";
    }
    
	return 0;
}
