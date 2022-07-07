#include<stdio.h>
int binarySearch(int a[],int lo,int hi,int x){
	int mid;
	mid=(lo+hi)/2;
//	if(x==a[mid])
//		return mid;
//	else if(x<a[mid])
//		return	binarySearch(a,lo,mid-1,x);
//	else
//		return binarySearch(a,mid+1,hi,x);

	if(x==a[mid])
		return mid;
	else if(x<a[mid])
		hi=mid-1;
	else
		lo=mid+1;
	
}
int main(){
	int a[]={2,3,4,5,6},i;
	i=binarySearch(a,0,4,5);
	printf("%d",i);
	return 0;
}
