#include<stdio.h>
void swap(int *x,int *y){
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;
}
void sort(int a[],int lo,int hi){
	int i,j;
	//printf("%d",lo);
	//printf("%d",hi);
	for(i=lo;i<hi-1;i++){
		for(j=lo;j<hi-i-1;j++){
			if(a[j]>a[j+1])
				swap(&a[j],&a[j+1]);
		}
	}
}
void disp(int a[],int n){
	int i;
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
}
int main(){
	int n=8,c=1;
	int lo,hi;
	int a[20]={3,2,12,9,13,5,6,17};
	lo=0;
	hi=n-1;
	sort(a,3,8);
	disp(a,n);
		while(lo<hi){
			if(a[lo]%2==0)
				lo++;
			else if(a[hi]%2!=0){
				hi--;
				//c++;
			}
				
			else
				swap(&a[lo],&a[hi]);
		}
	//sort(a,0,lo);
	//printf("%d",a[lo]);
	//disp(a,n);
	//sort(a,lo,n);
	printf("\n");
	//disp(a,n);
	//printf("\n%d%d",lo,c);
	return 0;
}
