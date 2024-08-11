//Help me,miss Chtholly.Let's congratulate this program.
#include<cstdio>
#include<string>
#include<iostream>
using namespace std;
class Chtholly{
    public:
        string name,inname[102];
        long long base,sum,k,type[102],inzz[102];
        long long find(string a){
            for(int i=1;i<=k;i++)if(inname[i]==a)return inzz[i];
            //printf("Nopht ");
            cout<<a<<"\n";
        }
        string find(long long a){
            for(int i=k;i>0;i--){
                if(inzz[i]>a)continue;
                if(a>inzz[i]+type[i]-1)return "ERR";\
                return inname[i];
            }
        }
};
Chtholly st[102];
long long x,tot,tot_s,op,n,k,type[102],type3[102],dz[102];
string str,named[102];
long long find(string name){
    for(int i=1;i<=tot;i++)if(named[i]==name)return i;
}
int findst(string cat){
    for(int i=1;i<=tot_s;i++)if(cat==st[i].name)return i;
}
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    cin>>n;
    dz[0]=0;
    while(n--){
        cin>>op;
        //printf("Chtholly %d %d\n",n,op);
        if(op==1){
            cin>>st[++tot_s].name>>st[tot_s].k;
            st[tot_s].inzz[0]=st[tot_s].base=0;
            //printf("Nephren %d %d\n",tot_s,st[tot_s].k);
            for(int i=1;i<=st[tot_s].k;i++){
                cin>>str>>st[tot_s].inname[i];
                if(str=="long")st[tot_s].type[i]=8;
                else if(str=="short")st[tot_s].type[i]=2;
                else if(str=="int")st[tot_s].type[i]=4;
                else if(str=="byte")st[tot_s].type[i]=1;
                st[tot_s].inzz[i]=(st[tot_s].inzz[i-1]+st[tot_s].type[i-1]+st[tot_s].type[i]-1)/st[tot_s].type[i]*st[tot_s].type[i];
                st[tot_s].base=max(st[tot_s].base,st[tot_s].type[i]);
                //printf("Nephren %d %d %d\n",st[tot_s].type[i],st[tot_s].inzz[i],st[tot_s].base);
            }
            st[tot_s].sum=(st[tot_s].inzz[st[tot_s].k]+st[tot_s].base)/st[tot_s].base*st[tot_s].base;
            printf("%lld %lld\n",st[tot_s].sum,st[tot_s].base);
        }
        if(op==2){
            cin>>str>>named[++tot];
            if(str=="long")type[tot]=8;
            else if(str=="short")type[tot]=2;
            else if(str=="int")type[tot]=4;
            else if(str=="byte")type[tot]=1;
            else{
                int f=findst(str);
                type[tot]=st[f].sum;
                type3[tot]=f;
            }
            dz[tot]=(dz[tot-1]+type[tot-1]+(!type3[tot]?type[tot]:st[type3[tot]].base)-1)/(!type3[tot]?type[tot]:st[type3[tot]].base)*(!type3[tot]?type[tot]:st[type3[tot]].base);
            printf("%lld\n",dz[tot]);
        }
        if(op==3){
            cin>>str;
            long long dota=str.find('.');
            if(dota==-1)printf("%lld\n",dz[find(str)]);
            else{
                string dotl,dotr;
                //for(int i=0;i<dota;i++)dotl[i]=str[i];
                dotl=str.substr(0,dota);
                //dotl[dota]=0;
                int len=str.length();
                //for(int i=dota+1;i<len;i++)dotr[i-dota-1]=str[i];
                //dotr[len-dota-1]=0;
                dotr=str.substr(dota+1,len);
                //printf("Rhantolk %d ",dota);
                //cout<<dotl<<" "<<dotr<<"\n";
                int fl=find(dotl);
                //printf("Ithea %d %d\n",dz[fl],st[type3[fl]].find(dotr));
                printf("%lld\n",dz[fl]+st[type3[fl]].find(dotr));
            }
        }
        if(op==4){
            cin>>x;
            for(int i=tot;i>0;i--){
                if(dz[i]>x)continue;
                if(!type3[i]){
                    if(x>dz[i]+type[i]-1){
                        cout<<"ERR\n";
                        break;
                    }
                    else cout<<named[i]<<"\n";
                }
                else{
                    string ans=st[type3[i]].find(x-dz[i]);
                    if(ans=="ERR")cout<<ans<<"\n";
                    else cout<<named[i]<<"."<<st[type3[i]].find(x-dz[i])<<"\n";
                    break;
                }
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
