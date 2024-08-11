#include <string>
#include <iostream>
#include <vector>
#include <map>
using namespace std;
#include <cstdio>
struct STRU{
    string name;
    int sz;
    int al;
    int le;//ele leng
    vector<string> eles;//type
    vector<string> ename;//name
};
map<string,STRU> stru;
int sl=0;
int main()
{
    int n,op;
    register int i;
    string a,b;
    cin.sync_with_stdio();
    scanf("%d",&n);
    stru["byte"]={"byte",1,1,0};
    stru["short"]={"short",2,2,0};
    stru["int"]={"int",4,4,0};
    stru["long long"]={"long long",8,8,0};
    while(n!=0)
    {
        scanf("%d",&op);
        switch(op)
        {
        case 1:
            cin >> a;
            STRU &e=stru[a];
            e.name=a;
            e.sz=0;
            e.al=0;
            scanf("%d",&e.le);
            for(i=0;i<e.le;i++)
            {
                cin >> a >> b;
                e.ename.push_back(b);
                e.eles.push_back(a);
                e.al=max(e.al,stru[a].al);
            }
            for(i=0;i<e.le;i++)
            {
                e.sz+=(stru[e.eles[i]]+(e.al-1))/e.al;
            }
            printf("%d %d\n",e.sz,e.al);
            break;
        }
        case 2:

        n--;
    }
    return 0;
}
