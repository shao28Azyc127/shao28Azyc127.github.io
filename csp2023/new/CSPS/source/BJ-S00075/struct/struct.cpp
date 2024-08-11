#include<bits/stdc++.h>
using namespace std;
const int N=5e6;
int q;
int n,val[N],pos=0,cnt=0,vis=0;
string flag;
struct node{
	int n,maxx,place[N];
	string name[N];
	string vl[N];
}qwq;
struct plc{
	string vl,name;
	int place,start;
}mov[N];
int main(){
	freopen("struct.in","r",stdin);
	freopen("struct.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int opt;
		scanf("%d",&opt);
		if(opt==1){
			cin>>flag;
			scanf("%d",&qwq.n);
			for(int j=1;j<=qwq.n;j++) cin>>qwq.vl[j]>>qwq.name[j];
			int now=0;qwq.maxx=-1;
			for(int j=1;j<=qwq.n;j++){
				if(qwq.vl[j]=="byte") qwq.place[j]=1;
				if(qwq.vl[j]=="short") qwq.place[j]=2;
				if(qwq.vl[j]=="int") qwq.place[j]=4;
				if(qwq.vl[j]=="long") qwq.place[j]=8;
				qwq.maxx=max(qwq.maxx,qwq.place[j]);
				if(now%qwq.place[j]==0) now+=qwq.place[j];
				else{
					now=now+(qwq.place[j]-now%qwq.place[j])-1+qwq.place[j];
				} 
			}		
			printf("%d %d\n",now+1,qwq.maxx);
		}
		if(opt==2){
			cnt++;
			cin>>mov[cnt].vl>>mov[cnt].name;
			if(mov[cnt].vl=="byte") mov[cnt].place=1;
			if(mov[cnt].vl=="short") mov[cnt].place=2;
			if(mov[cnt].vl=="int") mov[cnt].place=4;
			if(mov[cnt].vl=="long") mov[cnt].place=8;
			if(pos%mov[cnt].place==0) pos+=mov[cnt].place;
			else{
				pos=pos+(mov[cnt].place-pos%mov[cnt].place)-1+mov[cnt].place;
			} 
			mov[cnt].start=pos-mov[cnt].place;
			printf("%d\n",mov[cnt].start);
		}
		if(opt==3){
			string temp;
			cin>>temp;
			for(int j=1;j<=cnt;j++){
				if(mov[j].name==temp) printf("%d\n",mov[j].start);
			}
		}
		if(opt==4){
			int awa,flg=0;
			scanf("%d",&awa);
			//cout<<awa<<endl;
			for(int j=1;j<=cnt;j++){
				if(awa<=mov[j].start+mov[j].place-1&&awa>=mov[j].start){
					cout<<mov[j].name<<"\n";
					flg=1;
					break;
				}
			}
			if(!flg) puts("ERR");
		}
		//puts("qwq");
	}
	return 0;
}
/*
4
1 a 2
short aa
int ab
2 long x
3 x
4 4

*/