#include<bits/stdc++.h>
using namespace std;
long long a,cont=0,c=0,d=0,e=0;
long long b[1000010];
void find(int x){
	for(int i=1;i<=a;i++){
		b[i]=i;
	}
	while(d==0){
		e++;
		for(int i=1;i<=a;i++){
			if(b[i]==a&&c==0){
				cout<<e;
				d=1;
			}
			else if(b[i]!=0&&c==0){
				b[i]=0;
				c=1;
			}else if(b[i]==a&&c==3){
				cout<<e;
				d=1;
			}else if(b[i]!=0&&c!=3){
				c++;
			}else if(b[i]!=0&&c==3){
				c=1;
				b[i]=0;
			}else if(b[i]==0){
				continue;
			}
		}
		c=0;
	}
	
}
void clean(int x){
	int c=x;
	if(c%3!=0){
		x=c-c/3-1;
	}else{
		x=c-c/3;
	}
	cont++;
	if(x<=0){
		cout<<cont<<" ";
	}else{
		clean(x);
	}
}
int main(){
	freopen("apple.in","r","stdin");
	freopen("apple.out","w","stdout");
	cin>>a;
	clean(a);
	find(a);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
