#include<bits/stdc++.h>
using namespace std;
int n;
int ind;
string vis[105];
vector<int> node[50000];
int book[50000];
void O(int op,int par)
{
	if(op==1)
		{
			
			string name;
			int num;
			cin>>name>>num;
			int nind=int(name[0])*2+int(name[1])*3+int(name[2])*5+int(name[3])*7+int(name[4])*11+int(name[5])*13+int(name[6])*17+int(name[7]*19+int(name[8])*23+int(name[9])*27);
			for(int i=1;i<=num;i++)
				{
					O(2,nind);
				}
			
		}
		if(op==2)
		{
			
			string type;
			string name;
			cin>>type>>name;
			int f=int(name[0])*2+int(name[1])*3+int(name[2])*5+int(name[3])*7+int(name[4])*11+int(name[5])*13+int(name[6])*17+int(name[7]*19+int(name[8])*23+int(name[9])*27);
			if(type=="short")
			{
				if(ind%2!=0) ind+=2-ind%2;
				vis[ind]=name;
				book[f]=ind;
				if(par!=-1) node[par].push_back(ind);
				printf("%d\n",ind);
				ind+=2;
				
			}
			if(type=="byte")
			{
				vis[ind]=name;
				book[f]=ind;
				if(par!=-1) node[par].push_back(ind);
				printf("%d\n",ind);
				ind++;
			}
			if(type=="int")
			{
				if(ind%4!=0) ind+=4-ind%4;
				vis[ind]=name;
				book[f]=ind;
				if(par!=-1) node[par].push_back(ind);
				printf("%d\n",ind);
				ind+=4;
			}
			if(type=="long")
			{
				if(ind%8!=0) ind+=8-ind%8;
				vis[ind]=name;
				book[f]=ind;
				if(par!=-1) node[par].push_back(ind);
				printf("%d\n",ind);
				ind+=8;
			}
			
		}
		if(op==3)
		{
			string name;
			cin>>name;
			int f=int(name[0])*2+int(name[1])*3+int(name[2])*5+int(name[3])*7+int(name[4])*11+int(name[5])*13+int(name[6])*17+int(name[7]*19+int(name[8])*23+int(name[9])*27);
			printf("%d\n",book[f]);
		}
		if(op==4)
		{
			int addr;
			cin>>addr; 
			cout<<vis[addr]<<endl;
		}
}
int main()
{
	
	freopen("struct.in","r",stdin);
	freopen("struct.out","w",stdout);
	for(int i=1;i<=105;i++) vis[i]="ERR";
	cin>>n;
	for(int q=1;q<=n;q++)
	{
		int op;
		cin>>op;
		O(op,-1);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}