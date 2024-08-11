#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;
#define int long long
struct element
{
	string name;
	int type;
	int start,end;
};
struct typetype
{
	string name;
	int sz,tab;
	vector<element> elements;
};
vector<typetype> types;
map<string,int> rtypes;
typetype global;
element gg;
signed main()
{
	freopen("struct.in","r",stdin);
	freopen("struct.out","w",stdout);
	global.name="global";
	int n;
	cin>>n;
	rtypes["byte"]=0;
	rtypes["short"]=1;
	rtypes["int"]=2;
	rtypes["long"]=3;
	typetype tmppmt;
	tmppmt.name="byte";
	tmppmt.sz=tmppmt.tab=1;
	types.push_back(tmppmt);
	tmppmt.name="short";
	tmppmt.sz=tmppmt.tab=2;
	types.push_back(tmppmt);
	tmppmt.name="int";
	tmppmt.sz=tmppmt.tab=4;
	types.push_back(tmppmt);
	tmppmt.name="long";
	tmppmt.sz=tmppmt.tab=8;
	types.push_back(tmppmt);
	while(n--)
	{
		int op,k,id;
		cin>>op;
		string str,x;
		element tmp;
		typetype* tp=&global;
		element* ele;
		switch(op)
		{
			case 1:
				cin>>str>>k;
				id=types.size();
				rtypes[str]=id;
				types.emplace_back();
				types[id].name=str;
				types[id].sz=types[id].tab=0;
				for(int i=1;i<=k;i++)
				{
					string tp,nm;
					cin>>tp>>nm;
					tmp.name=nm;
					tmp.type=rtypes[tp];
					types[id].tab=max(types[id].tab,types[tmp.type].tab);
					tmp.start=(types[id].sz+types[tmp.type].tab-1)/types[tmp.type].tab*types[tmp.type].tab;
					tmp.end=tmp.start+types[tmp.type].sz-1;
					types[id].sz=tmp.end+1;
					types[id].elements.push_back(tmp);
//					cout<<"#"<<tmp.type<<"="<<types[tmp.type].name<<" "<<tmp.name<<":"<<tmp.start<<"~"<<tmp.end<<endl;
				}
				types[id].sz=(types[id].sz+types[id].tab-1)/types[id].tab*types[id].tab;
				cout<<types[id].sz<<" "<<types[id].tab<<endl;
				break;
			case 2:
				cin>>str>>x;
				id=rtypes[str];
				tmp.name=x;
				tmp.type=id;
				tmp.start=(global.sz+types[id].tab-1)/types[id].tab*types[id].tab;
				tmp.end=(tmp.start+types[id].sz-1);
				global.sz=tmp.end+1;
				global.elements.push_back(tmp);
				cout<<tmp.start<<endl;
				break;
			case 3:
				id=0;
				cin>>str;
				str+='.';
				x="";
				for(char ch:str)
					if(ch=='.')
					{
						for(const element& e:tp->elements)
							if(e.name==x)
							{
								tp=&types[e.type];
								id+=e.start;
//								cout<<tp->name<<" "<<x<<" "<<e.type<<" "<<e.start<<" "<<e.end<<endl;
								break;
							}
						x="";
					}
					else x+=ch;
				cout<<id<<endl;
				break;
			case 4:
				cin>>id;
				tp=&global;
				x="";
				while(true)
				{
					bool ok=0;
					for(element& e:tp->elements)
						if(e.end>=id)
						{
							id-=e.start;
//							cout<<types[e.type].name<<" "<<e.name<<" select\n";
							ele=&e;
							tp=&types[ele->type];
							ok=1;
							break;
						}
//						else cout<<types[e.type].name<<" "<<e.name<<" "<<id<<"/"<<e.end<<endl;
					if(!ok)
					{
//						cout<<ele->name<<" "<<tp->name<<endl;
						x=".ERR";
						break;
					}
					x+=".";
					x+=ele->name;
					if(ele->type<4)
						break;
				}
				cout<<x.substr(1)<<endl;
		}
//		cout<<"Globals:sz="<<global.sz<<"\n";
//		for(element i:global.elements)
//			cout<<"#"<<i.type<<"="<<types[i.type].name<<" "<<i.name<<":"<<i.start<<"~"<<i.end<<endl;
	}
	return 0;
}
/*
import requests
import json
import time
headers={}
headers["Cookie"]=r"JSE=**********; JSESSIONID=********************************; lang=zh"
while True:
	req=requests.get('http://172.17.20.11/user.CheckStarted.dt',headers=headers)
	j=json.loads(req.text)
	remain=int(j['timeleft'])
	if remain<1:
		break
	second=remain%60
	remain=remain//60
	minute=remain%60
	hour=remain//60
	if second<1:
		second='00'
	elif second<10:
		second='0'+str(second)
	else:
		second=str(second)
	if minute<1:
		minute='00'
	elif minute<10:
		minute='0'+str(minute)
	else:
		minute=str(minute)
	print("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	print('        ',end='')
	if hour:
		print(hour,minute,second,sep=':',end='')
	else:
		print(minute,second,sep=':',end='')
	print(' to the end of the world!')
	time.sleep(0.25)
while True:
	print("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	print('            The world has ended!')
	time.sleep(0.25)
*/