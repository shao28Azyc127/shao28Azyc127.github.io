#include<bits/stdc++.h>

using namespace std;
long long N;
const unsigned long long Maxn=1e8;
bool ram[Maxn]={};
struct things{
    int type;//1-byte 2-short 3-int 4-long 5-struct
    string Name;
    int li,ri;
}thing[100010];
long long idx=0;

void Fill(long long l,long long r){
    for(long long i=l;i<=r;i++){
        ram[i]=0;
        //cout<<i;
    }
}

int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    memset(ram,1,Maxn);
    scanf("%lld",&N);
    while(N--){
        int op;
        scanf("%d",&op);
        if(op==1){

        }else if(op==2){
            string Type,Name;
            cin>>Type>>Name;
            if(Type=="byte"){
                for(long long i=0;i<=Maxn;i++){
                    if(ram[i]){
                        Fill(i,i);
                        thing[idx].type=1;
                        thing[idx].li=i;
                        thing[idx].ri=i;
                        thing[idx].Name=Name;
                        idx++;
                        break;
                    }
                }
            }else if(Type=="short"){
                for(long long i=0;i<=Maxn;i+=2){
                    if(ram[i]){
                        Fill(i,i+1);
                        thing[idx].type=2;
                        thing[idx].li=i;
                        thing[idx].ri=i+1;
                        thing[idx].Name=Name;
                        idx++;
                        break;
                    }
                }
            }else if(Type=="int"){
                for(long long i=0;i<=Maxn;i+=4){
                    if(ram[i]){
                        Fill(i,i+3);
                        thing[idx].type=3;
                        thing[idx].li=i;
                        thing[idx].ri=i+3;
                        thing[idx].Name=Name;
                        idx++;
                        break;
                    }
                }
            }else{
                for(long long i=0;i<=Maxn;i+=8){
                    if(ram[i]){
                        Fill(i,i+7);
                        thing[idx].type=8;
                        thing[idx].li=i;
                        thing[idx].ri=i+7;
                        thing[idx].Name=Name;
                        idx++;
                        break;
                    }
                }
            }
        }else if(op==3){
            string Name;
            cin>>Name;
            for(long long i=0;i<idx;i++){
                if(thing[i].Name==Name){
                    cout<<thing[i].li<<endl;
                }
            }
        }else{
            long long Addr;
            cin>>Addr;
            bool flg=0;
            for(long long i=0;i<idx;i++){
                if(thing[i].li<=Addr&&thing[i].ri>=Addr&&thing[i].type!=5){
                    cout<<thing[i].Name<<endl;
                    flg=1;
                    break;
                }
            }
            if(!flg){
                cout<<-1;
            }
        }
    }


    fclose(stdin);
    fclose(stdout);
    return 0;
}

