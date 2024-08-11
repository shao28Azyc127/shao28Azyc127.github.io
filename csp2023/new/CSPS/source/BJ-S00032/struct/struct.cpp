#include <bits/stdc++.h>
using namespace std;
int a[400],i,j=1,b[101],s,z,n,s1;
string y;
char name[101][101];
int main(){
	freopen("struct.in","r",stdin);
	freopen("struct.out","w",stdout);
	scanf("%d",&n);
	for(int t=0,x;i<n;t++){
		scanf("%d",&x);
		if(x==2){
			cin>>y;
			while(1==1){
				s=0;
				scanf("%c",&name[j][s++]);
				if(getchar()=='\n'){
					break;
				}
			}
			if(y=="byte"){
				b[j]=i;
				a[i++]=j;
			}
			else if(y=="short"){
				if(i%2!=0){
					i++;
				}
				b[j]=i;
				a[i++]=j;
				a[i++]=j;
			}
			else if(y=="int"){
				while(i%4!=0){
					i++;
				}
				b[j]=i;
				for(s=0;s<4;s++){
					a[i++]=j;
				}
			}
			else{
				while(i%8!=0){
					i++;
				}
				b[j]=i;
				for(s=0;s<8;s++){
					a[i++]=j;
				}
			}
			j++;
		}
		else if(x==3){
			cin>>y;
			for(s=0;s<j;s++){
				for(s1=0;name[s][s1]!='\n'&&y[s1]!='\n'&&name[s][s1]==y[s1];s1++){}
				if(name[s][s1]=='\n'||y[s1]=='\n'){
					break;
				}
			}
			printf("%d\n",b[s]);
		}
		else if(x==4){
			scanf("%d",&z);
			if(a[z]==0)
				printf("ERR\n");
			else
				cout<<name[a[z]]<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}