#include<stdio.h>

void merge(int a[],int lo,int mid,int hi){
	int b[5];
	int i,j,h,k;
	i=lo;
	h=lo;
	j=mid+1;
	while(h<=mid && j<=hi){
		if(a[h]<a[j]){
			b[i]=a[h];
			h++;
			i++;
		}
		else{
			b[i]=a[j];
			j++;
			i++;
		}
	}
	while(h<=mid)
		b[i++]=a[h++];
	while(j<=hi)
		b[i++]=a[j++];
	
	for(k=lo;k<=hi;k++)
		a[k]=b[k];
		
	
}
void mergeSort(int a[],int lo,int hi){
	int mid;
	if(lo<hi){
		mid=(lo+hi)/2;
		mergeSort(a,lo,mid);
		mergeSort(a,mid+1,hi);
		merge(a,lo,mid,hi);
		
	}
	
}
int main(){
	int k;
	int a[]={2,1,9,7,-6};
	mergeSort(a,0,4);
	for(k=0;k<5;k++)
		printf("%d ",a[k]);
	return 0;
}
