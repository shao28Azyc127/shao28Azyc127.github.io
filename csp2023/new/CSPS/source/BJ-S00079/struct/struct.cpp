#include <iostream>
#include <cstring>
using namespace std;
int n;
string defined_struct[100][101];
int struct_size[100][100];
int size_tot[100];
string elements[100][2];
long long elements_memory[100][2];
long long memory=0;
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    int cnt=0,cnt2=0;
    cin>>n;
    for(int i=0;i<n;i++){
        int op;
        cin.get();
        op=getchar()-'0';
        if(op==1){
            string s;
            int k;
            cin>>s>>k;
            defined_struct[cnt][0]=s;
            for(int i=0;i<k;i++){
                string temp_t,temp_n;
                cin>>temp_t>>temp_n;
                defined_struct[cnt][k+1]=temp_n;
                if(temp_t=="byte") struct_size[cnt][i]=1;
                if(temp_t=="short") struct_size[cnt][i]=2;
                if(temp_t=="int") struct_size[cnt][i]=4;
                if(temp_t=="long") struct_size[cnt][i]=8;
                for(int j=0;j<100;j++){
                    if(temp_t==defined_struct[j][0]) struct_size[cnt][i]=size_tot[j];
                }
            }
            int tot=0,maxn=0;
            for(int i=0;i<k;i++){
                tot+=struct_size[cnt][i];
                maxn=max(maxn,struct_size[cnt][i]);
            }
            int i=0;
            do{
                i++;
            }while(maxn*i<tot);
            cout<<maxn*i<<" "<<maxn<<endl;
            size_tot[cnt]=maxn*i;
            cnt++;
        }
        if(op==2){
            string temp_t,temp_n;
            cin>>temp_t,temp_n;
            elements[cnt2][0]=temp_t;
            elements[cnt2][1]=temp_n;
            int p=0;
            for(int i=0;i<cnt;i++){
                if(temp_t==defined_struct[i][0]) p=i;
            }
            cout<<memory;
            elements_memory[cnt2][0]=memory;
            memory+=size_tot[p];
            elements_memory[cnt2][1]=memory;
        }
        if(op==3){
            string s;
            cin>>s;
        }
        if(op==4){
            int addr;
            cin>>addr;
        }
    }
    return 0;
}
