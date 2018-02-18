#include<stdio.h>
int majority(int a[],int low,int high);
int majority_util(int a[],int low,int high);
int isMajority(int a[],int low,int high,int maj);
int main()
{
	int a[]={3,3,4,2,4,4,2,4};
	int n=sizeof(a)/sizeof(a[0]);
	int majority_ele=majority(a,0,n-1);
	if(majority_ele==-1)
		printf("no majority element");
	else
		printf("the majority element is: %d",majority_ele);
	
}
int majority(int a[],int low,int high)
{
	int mid,left_majority=-1,right_majority=-1,comb_majority=-1,flag;
	if(low<high)
	{
		mid=(low+high)/2; 
		left_majority=majority(a,low,mid);
		right_majority=majority(a,mid+1,high);
		comb_majority=majority_util(a,low,high);
	}
	else 
		return a[low];
	if(left_majority==-1 && right_majority==-1){
		return -1;}
	else if(left_majority==-1){
		flag=isMajority(a,low,high,right_majority);
		if(flag==1)
			return right_majority;
		 return -1;}
	else if(right_majority==-1){
		flag=isMajority(a,low,high,left_majority);
		if(flag==1)
			return left_majority;
		return -1;}
	else
	{
		if(comb_majority!=left_majority && comb_majority!=right_majority)
			return -1;
		if(comb_majority==left_majority){
		flag=isMajority(a,low,high,left_majority);
		if(flag==1)
			return left_majority;
		return -1;
		}
		if(comb_majority==right_majority){
		flag=isMajority(a,low,high,right_majority);
		if(flag==1)
			return right_majority;
		return -1;
		}
		return -1;
	}

}
int majority_util(int a[],int low,int high)
{
	int maj_index=low,count=1;
	int i;
	for(i=low+1;i<=high;i++)
	{
		if(a[maj_index]==a[i])
			count++;
		else
			count--;
		if(count==0)
		{
			maj_index=i;
			count=1;
		}
	}
	return a[maj_index];
}
int isMajority(int a[],int low,int high,int maj)
{
	int i,count=0;
	for(i=low;i<=high;i++)
	{
		if(maj==a[i])
			count++;
	}
	int n=(high-low+1);
	if(count>n/2)
		return 1;
	return 0;
}