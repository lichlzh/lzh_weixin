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
	int x,y,v;
}e[maxm];
bool Bellman_ford(){
	N=read(),M=read();
	for(int i=1;i<=M;i++)
		e[i].x=read(),e[i].y=read(),e[i].v=read();
	static int dis[maxn];
	memset(dis,10,sizeof(dis));
	dis[1]=0;
	int tim1=clock(),tim2;
	bool rel;
	for(int i=1;i<=N;i++){
		rel=0;
		for(int j=1;j<=M;j++){
			if(dis[e[j].y]>dis[e[j].x]+e[j].v) {
				dis[e[j].y]=dis[e[j].x]+e[j].v;
				rel=1;
			}
		}
		if(!rel)
			break;
	}
	tim2=clock();
	printf("%d\n",tim2-tim1);
	return rel;
}

int main(){
	freopen("in","r",stdin);
	Bellman_ford();
	return 0;
}

