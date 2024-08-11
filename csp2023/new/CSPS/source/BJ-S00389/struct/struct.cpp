#include<iostream>
#include<string>
using namespace std;
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    int n;
    cin>>n;
    int ad = 0;
    for(int i=1;i<=n;i++){
        int op;
        cin>>op;
        if(op == 1){
            string s;
            cin>>s;
            int k;
            cin>>k;
            int siz = 0, ru  = 0;
            for(int i=1;i<=k+1;i++){
                char t;
                cin>>t;
                if(t == 'b') ru = max(ru,1);
                if(t == 's') ru = max(ru,2);
                if(t == 'i') ru = max(ru,4);
                if(t == 'l') ru = max(ru,8);
                string n;
                cin>>n;
            }cout<<ru*k<<" "<<ru<<endl;
        }
        if(op == 2){
            char t;
            int ru = 0;
            string  n;
            cin>>t>>n;
            cout<<ad<<endl;
            if(t == 'l') ad+=8;
        }
        if(op == 3){
            cout<<0;
        }
        if(op == 4){
            cout<<"ERR"<<endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}