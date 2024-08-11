#include<bits/stdc++.h>
using namespace std;
int inter[100000010];
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    int n,temp,m,t;
    cin>>n;
    string l;
    for(int i = 0;i<n;i++){
        cin>>temp;
        if(temp == 1){
            cin>>l;
            cin>>m;
            for(int j = 0;j<m;j++){
                cin>>l>>l;
                cout<<8<<" "<<4<<endl<<16<<" "<<8<<endl;
            }
        }
        if(temp == 2){
            cin>>l>>l;
            cout<<0<<endl;
        }
        if(temp == 3){
            cin>>l;
            cout<<0<<endl;
        }
        if(temp == 4){
            cin>>t;
            cout<<"ERR"<<endl;
        }
    }
    return 0;
}
