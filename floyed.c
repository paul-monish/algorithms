#include<stdio.h>
#define INF 999999
#define MAX 4
static int p[MAX][MAX],d[MAX][MAX];
void print(int d[][MAX],int v){
	int i,j;
	printf("Cost Matrix:\n");
	for(i=0;i<v;i++){
		for(j=0;j<v;j++){
			if(d[i][j]==INF){
				printf("%7s","INF");
			}
			else{
				printf("%7d",d[i][j]);
			}
		}
		printf("\n");
	}
}

void print_p(int p[][MAX],int v){
	int i,j;
	printf("\nPath Matrix:\n");
	for(i=0;i<v;i++){
		for(j=0;j<v;j++){
			if(p[i][j]==-1){
				printf("%7s","X");
			}
			else{
				printf("%7d",p[i][j]);
			}
		}
		printf("\n");
	}
}
void f_w(int g[][MAX],int p[][MAX],int v){
	int i,j,k;
	for(i=0;i<v;i++){
		for(j=0;j<v;j++){
			d[i][j]=g[i][j];
		}
	}
	
	for(k=0;k<v;k++){
		for(i=0;i<v;i++){
			for(j=0;j<v;j++){
				if((d[i][k]+d[k][j])<d[i][j]){
					d[i][j]=d[i][k]+d[k][j];
					p[i][j]=k;
				}
			}
		}
	}
	
	print(d,v);
	printf("\n");
	print_p(p,v);
}

void path(int a,int b){
	if(p[a][b]==-1){
		printf("---> %d",b);
	}
	else{
		path(a,p[a][b]);
		path(p[a][b],b);
	}
}

int main(){
	int i, j, g[MAX][MAX], n;
	
	printf("Enter size of the matrix: ");
	scanf("%d", &n);
	printf("\nEnter value of matrix:\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d", &g[i][j]);
			if(i!=j && g[i][j] == 0){
				g[i][j]= INF;
			}
		}
	}
	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			p[i][j]=-1;
		}
	}
	f_w(g,p,4);
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("\n\nPath form %d to %d: %d",i,j,i);
			path(i,j);
			if(d[i][j]!=INF)
				printf("\nCost of d[%d][%d]= %d",i,j,d[i][j]);
			else
				printf("\nCost of d[%d][%d]= %s",i,j,"INF");

		}
	}
	return 0;
}

/*
0 8 0 1
0 0 1 0
4 0 0 0
0 2 9 0
*/
