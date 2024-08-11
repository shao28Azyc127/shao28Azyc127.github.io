#include <bits/stdc++.h>
using namespace std;
struct node{
	string name;
	long long start;
	long long end;
};
long long n,op,sum=0,k,maxlen=-1,cnt=0,addr;
string type,name,s;
node address[100010];
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
		cin>>op;
		if(op==1){
			//lol bu hui xie
		}else if(op==2){
			maxlen=-1;
			cin>>type>>name;
			if(type=="byte"){
				if(1>maxlen) maxlen=1;
			}else if(type=="short"){
				if(2>maxlen) maxlen=2;
			}else if(type=="int"){
				if(4>maxlen) maxlen=4;
			}else if(type=="long"){			
				if(8>maxlen) maxlen=8;
			}else{
				
			}
			address[cnt+1].name=name;
			address[cnt+1].start=sum;
			if(type=="byte") sum+=1;
			else if(type=="short") sum+=2;
			else if(type=="int") sum+=4;
			else sum+=8;
			address[cnt+1].end=sum-1;
			cnt++;
			if(sum%maxlen!=0){
				address[cnt+1].name="nothing";
				address[cnt+1].start=sum;
				sum=((sum/maxlen+1)*maxlen);
				address[cnt+1].end=sum-1;
				cnt++;
			}
		}else if(op==3){
			cin>>s;
			for(int i=1;i<=cnt;i++){
				if(address[i].name==s){
					cout<<address[i].start<<endl;
					break;
				}
			}
		}else{
			cin>>addr;
			for(int i=1;i<=cnt;i++){
				if(address[i].start<=addr && address[i].end>=addr){
					if(address[i].name!="nothing"){
						cout<<address[i].name<<endl;
					}else{
						cout<<"ERR"<<endl;
					}
					break;
				}
			}
		}
	}
	/*
	for(int i=1;i<=cnt;i++){
		cout<<"i:"<<i<<" name:"<<address[i].name<<" start:"<<address[i].start<<" end:"<<address[i].end<<endl;
	}
	*/
    return 0;
}
