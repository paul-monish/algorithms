#include<stdio.h>
typedef struct pair{
	int max;
	int min;
}pair;
pair maxMin(int a[],int lo,int hi){
	int mid;
	pair maxmin,mml,mmr;
	if(lo==hi){
		maxmin.max=a[lo];
		maxmin.min=a[lo];
		return maxmin;
	}
	if(lo+1==hi){
		if(a[lo]<a[hi]){
			maxmin.max=a[hi];
			maxmin.min=a[lo];
		}
		else{
			maxmin.max=a[lo];
			maxmin.min=a[hi];
		}
		
		return maxmin;	
	}
	mid=(lo+hi)/2;
	mml=maxMin(a,lo,mid);
	mmr=maxMin(a,mid+1,hi);
	if(mml.max<mmr.max)
		maxmin.max=mmr.max;
	else
		maxmin.max=mml.max;
	if(mml.min>mmr.min)
		maxmin.min=mmr.min;
	else
		maxmin.min=mml.min;
	return maxmin;
	
}
int main(){
	int a[]={2,3,4,5,6};
	pair maxmin=maxMin(a,0,4);
	printf("Max=%d Min=%d",maxmin.max,maxmin.min);
	return 0;
}
