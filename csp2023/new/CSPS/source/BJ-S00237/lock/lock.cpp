#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<set>
#include<algorithm>
#include<map>
#define MAXSTATUS 100000
using namespace std;
int n,a[5];
//int status[MAXSTATUS];
//vector<int> st[MAXSTATUS];
int st[MAXSTATUS][100];
int pt[MAXSTATUS];
//set<int> st[MAXSTATUS];
//multiset<int> ans;
map<int,int> ans;
const int qz[5]={10000,1000,100,10,1};
void init(){
    for(int i=0;i<MAXSTATUS;i++){
        for(int dig=0;dig<5;dig++){
            int preval=i/qz[dig]/10;
            int postval=i%qz[dig];

            for(int off=0;off<10;off++){
                int res=preval*qz[dig]*10+off*qz[dig]+postval;
                //if(find(st[i].begin(),st[i].end(),res)==st[i].end())
                if(res!=i)
                    st[i][pt[i]++]=res;
            }
        }
    }

    for(int i=0;i<MAXSTATUS;i++){
        for(int dig=0;dig<4;dig++){
            int preval=i/qz[dig]/10;
            int postval=i%(qz[dig+1]);
            int midval1=i/qz[dig]%10;
            int midval2=i/qz[dig+1]%10;
            for(int off=0;off<10;off++){
                midval1++;
                midval2++;
                midval1%=10;
                midval2%=10;
                int res=preval*qz[dig]*10+midval1*qz[dig]+midval2*qz[dig+1]+postval;
                //if(find(st[i].begin(),st[i].end(),res)==st[i].end())
                if(res!=i)
                    st[i][pt[i]++]=res;
            }
        }
    }
}
int vals[10];
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    init();
    //cout<<"OK";
    scanf("%d",&n);
    for(int j=0;j<n;j++){
        for(int i=0;i<5;i++)
            scanf("%d",&a[i]);
        vals[j]=a[0]*10000+a[1]*1000+a[2]*100+a[3]*10+a[4];
        /*for(int i=0;i<pt[vals[j]];i++){
            int numm=st[vals[j]][i];
            int u=numm/10000,v=numm/1000%10,w=numm/100%10,x=numm/10%10,y=numm%10;
            printf("%d %d %d %d %d\n",u,v,w,x,y);
        }*/
    }
    for(int i=0;i<n;i++){
        int len=pt[vals[i]];
        for(int j=0;j<len;j++)
            //ans.insert(st[vals[i]][j]);
            ans[st[vals[i]][j]]++;
    }
    int ans_sum=0;
    for(map<int,int>::iterator it=ans.begin();it!=ans.end();it++){
        //printf("%d:%d\n",it->first,it->second);
        if(it->second==n) ans_sum++;
    }
    printf("%d",ans_sum);
    //for(int i=0;i<st[val].size();i++) cout<<st[val][i]<<' ';
}
