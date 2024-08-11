#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
#include<queue>
#include<cstdio>
using namespace std;
struct obj{
    string name,tp;
    int sz;
    int st;
}a[10005];
struct sct{
	string name;
	obj comp[105];
	int cps;
}s[105];
int res=0,rs=0,n,sn=0;
string ramm[100005];
int main(){
freopen("struct.in","r",stdin);
freopen("struct.out","w",stdout);
for(int i = 0;i<100005;i++){
    ramm[i]="ERR";
}
cin>>n;
int op,addr;
string chk,nam,yyy;
for(int i = 0;i<n;i++){
    cin>>op;
    if(op==1){
        cin>>nam;
        cin>>addr;
        for(int j = 0;j<addr;j++){
			cin>>chk>>yyy;
			s[sn].comp[j].name=yyy;
			if(chk=="byte"){
				s[sn].comp[j].sz=1;
			}
			if(chk=="short"){
				s[sn].comp[j].sz=2;
			}
			if(chk=="int"){
				s[sn].comp[j].sz=4;
			}
			if(chk=="long"){
				s[sn].comp[j].sz=8;
			}
		}
		s[sn].cps=addr;
		sn++;
    }else if(op==2){
        cin>>chk>>nam;
        if(chk=="byte"){
            a[res].name=nam;
            a[res].sz=1;
            a[res].st=rs;
            ramm[rs]=nam;
            rs+=1;
            res++;
            
        }else if(chk=="short"){
            a[res].name=nam;
            a[res].sz=2;
            a[res].st=rs-rs%2+2;
            if(rs%2==0){
				 a[res].st-=2;
			}
            ramm[a[res].st]=nam;
            ramm[a[res].st+1]=nam;
            rs=a[res].st+2;
            res++;
        }else if(chk=="int"){
            a[res].name=nam;
            a[res].sz=4;
            a[res].st=rs-rs%4+4;
            if(rs%4==0){
				 a[res].st-=4;
			}
            ramm[a[res].st]=nam;
            ramm[a[res].st+1]=nam;
            ramm[a[res].st+2]=nam;
            ramm[a[res].st+3]=nam;
            rs=a[res].st+4;
            res++;
        }else if(chk=="long"){
            a[res].name=nam;
            a[res].sz=8;
            a[res].st=rs-rs%8+8;
            if(rs%8==0){
				 a[res].st-=8;
			}
            ramm[a[res].st]=nam;
            ramm[a[res].st+1]=nam;
            ramm[a[res].st+2]=nam;
            ramm[a[res].st+3]=nam;
            ramm[a[res].st+4]=nam;
            ramm[a[res].st+5]=nam;
            ramm[a[res].st+6]=nam;
            ramm[a[res].st+7]=nam;
            rs=a[res].st+8;
            res++;
        }else{
            for(int j = 0;j<sn;j++){
				if(s[j].name==chk){
					for(int k = 0;k<s[j].cps;k++){
						if(s[j].comp[k].sz==1){
							a[res].name=s[j].name+'.'+s[j].comp[k].name;
							a[res].sz=1;
							a[res].st=rs;
							ramm[rs]=nam;
							rs+=1;
							res++;
							
						}else if(s[j].comp[k].sz==2){
							a[res].name=s[j].name+'.'+s[j].comp[k].name;
							a[res].sz=2;
							a[res].st=rs-rs%2+2;
							if(rs%2==0){
								 a[res].st-=2;
							}
							ramm[a[res].st]=nam;
							ramm[a[res].st+1]=nam;
							rs=a[res].st+2;
							res++;
						}else if(s[j].comp[k].sz==4){
							a[res].name=s[j].name+'.'+s[j].comp[k].name;
							a[res].sz=4;
							a[res].st=rs-rs%4+4;
							if(rs%4==0){
								 a[res].st-=4;
							}
							ramm[a[res].st]=nam;
							ramm[a[res].st+1]=nam;
							ramm[a[res].st+2]=nam;
							ramm[a[res].st+3]=nam;
							rs=a[res].st+4;
							res++;
						}else if(s[j].comp[k].sz==8){
							a[res].name=s[j].name+'.'+s[j].comp[k].name;
							a[res].sz=8;
							a[res].st=rs-rs%8+8;
							if(rs%8==0){
								 a[res].st-=8;
							}
							ramm[a[res].st]=nam;
							ramm[a[res].st+1]=nam;
							ramm[a[res].st+2]=nam;
							ramm[a[res].st+3]=nam;
							ramm[a[res].st+4]=nam;
							ramm[a[res].st+5]=nam;
							ramm[a[res].st+6]=nam;
							ramm[a[res].st+7]=nam;
							rs=a[res].st+8;
							res++;
						}
					}
				}
			}
        }
    }else if(op==3){
        cin>>chk;
        for(int i = 0;i<=rs;i++){
            if(ramm[i]==chk){
                cout<<i<<endl;
                break;
            }
        }
    }else{
        cin>>addr;
        cout<<ramm[addr]<<endl;
    }
}
return 0;
}

