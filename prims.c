#include<stdio.h>
#define MAX 50
#define INF 999999

int min_cost = 0, visited[MAX], min, g[MAX][MAX];
int prims(int n){
	int i,j,k,v1,v2;
	for(j=1;j<=n;j++){
		visited[j]=0;
	}
	visited[1]=1;
	for(k=1;k<n;k++){
		min=INF;
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				if(g[i][j]!=INF && visited[i]==1 && visited[j]==0)	{
					if(g[i][j]<min){
						min=g[i][j];
						v1=i;
						v2=j;
					}
				}
			}
		}
		
		printf("\nEdge[%d] = (%d ---> %d) (weight = %d)",k,v1,v2,min);
		visited[v1]=visited[v2]=1;
		min_cost+=min;
	}
	return min_cost;
}

int main(){
	int i, j, k, n;
	
	printf("Enter size of the matrix: ");
	scanf("%d", &n);
	printf("\nEnter value of matrix:\n");
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			scanf("%d", &g[i][j]);
			if(g[i][j] == 0){
				g[i][j]= INF;
			}
		}
	}	
	
	printf("\nAdjacency Matrix:\n");
	for(i = 1; i <= n; i++){
		for(j = 1; j <= n; j++){
			
			if(g[i][j]==INF){
				printf("%s\t","INF");
			}
			else{
				printf("%d\t", g[i][j]);
			}
		}
		printf("\n");
	}
	
	k = prims(n);
	printf("\n\nMinimum Cost = %d", k);
	
	return 0;
	
}
/*
0 6 0 8 2 0
6 0 4 7 3 3 
0 4 0 0 7 3
8 7 0 0 2 0 
2 3 7 2 0 6
0 3 3 0 6 0

0 7 2 6 0 0
7 0 6 0 4 0
2 6 0 6 7 5
6 0 6 0 0 3
0 4 7 0 0 7
0 0 5 3 7 0
*/
