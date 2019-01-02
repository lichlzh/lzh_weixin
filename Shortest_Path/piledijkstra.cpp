#include<iostream>
#include<cstdio>
#include<cstring>
#include<ctime>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<string>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<utility>
#include<iomanip>
using namespace std;
int read(){
    int xx=0,ff=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')ff=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){xx=xx*10+ch-'0';ch=getchar();}
    return xx*ff;
}
long long READ(){
    long long xx=0,ff=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')ff=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){xx=xx*10+ch-'0';ch=getchar();}
    return xx*ff;
}
char one(){
	char ch=getchar();
	while(ch==' '||ch=='\n')
		ch=getchar();
	return ch;
}
const int maxn=5010,maxm=10000010;
int N,M;
int lin[maxn],len;
struct edge{
	int y,next,v;
}e[maxm];
inline void insert(int xx,int yy,int vv){
	e[++len].next=lin[xx];
	lin[xx]=len;
	e[len].y=yy;
	e[len].v=vv;
}
struct node{
	int id,val;
	bool operator<(const node&A)const{
		return val>A.val;
	}
}temp;
priority_queue<node>q;
void dijkstra(){
	static int dis[maxn];
	static bool vis[maxn];
	N=read(),M=read();
	for(int i=1;i<=M;i++){
		int t1=read(),t2=read(),t=read();
		insert(t1,t2,t);
	}
    memset(dis,10,sizeof(dis));
    memset(vis,0,sizeof(vis));
    while(!q.empty())
        q.pop();
	int tim1=clock(),tim2;
    dis[1]=0;
    temp.id=1,temp.val=0;
    q.push(temp);
    for(int i=1;i<N;i++){
        while(!q.empty()){
            temp=q.top();
            q.pop();
            if(!vis[temp.id])
                break;
        }
        int x=temp.id;
        vis[x]=1;
        for(int i=lin[x];i;i=e[i].next)
            if(dis[e[i].y]>dis[x]+e[i].v){
                dis[e[i].y]=dis[x]+e[i].v;
                temp.id=e[i].y,temp.val=dis[e[i].y];
                q.push(temp);
            }
    }
	tim2=clock();
	printf("%d\n",tim2-tim1);
}
int main(){
	freopen("in","r",stdin);
	dijkstra();
	return 0;
}

