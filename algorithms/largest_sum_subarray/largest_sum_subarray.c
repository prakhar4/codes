#include<stdio.h>

void mid_max(int a[], int result[], int st, int en, int mid)
{
	//int result[3];
	int l_max=-9999, r_max=-9999, sum, i, j, l_pos, r_pos, maxx;
	
	for(i=mid, sum=0; i>=st; i--)
	{
		sum+=a[i];
		if(sum>=l_max)
		{
			l_max=sum;
			l_pos=i;					//try comibing both of these loops into the same for loop by having i++ j++ for left n right
		}
	}
	
	
	for(i=mid+1,sum=0; i<=en; i++)
	{
		sum+=a[i];
		if(sum>=r_max)
		{
			r_max=sum;
			r_pos=i;
		}
	}
	
	maxx=l_max + r_max;
	
	result[0]=maxx;
	result[1]=l_pos;
	result[2]=r_pos;
	
	//return (result);
}


void find_max(int a[], int tem[], int low, int high)				//a[0] is max_sum   a[1] is l_pos
{
	int  mid,  temp[3]; 
	
	//int tem[3];
	int mid_ret[3], ret[3][3];  	//ret is to return values
	
	if(low==high)
	{
		tem[0]=a[low];
		tem[1]=low;
		tem[2]=high;
		//return (tem);
	}
	else
	{
		mid=(low+high)/2;
				
		find_max(a,ret[0],low, mid);		
		find_max(a,ret[1],mid+1,high);
		mid_max(a,ret[2],low,high,mid);
		
		if( (ret[0][0]>= ret[1][0]) && (ret[0][0]>= ret[2][0]) )
		{
			tem[0]=(ret[0][0]);
			tem[1]=(ret[0][1]);
			tem[2]=(ret[0][2]);
			//return (tem);
		}
		else if( (ret[2][0]>= ret[1][0]) && (ret[2][0]>= ret[0][0]) )
		{
			tem[0]=(ret[2][0]);
			tem[1]=(ret[2][1]);
			tem[2]=(ret[2][2]);
			//return (tem);
		}
		else 
		{
			tem[0]=(ret[1][0]);
			tem[1]=(ret[1][1]);
			tem[2]=(ret[1][2]);
			//return (tem);
		}
	}
}

int main()
{
	int i,j, n,arr[100], res[3];
	
	printf("\nEnter the no of elements  ");
	scanf("%d",&n);
	
	printf("\nEnter the values  ");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
		
	find_max(arr,res,0,n-1);
	
	printf("\n\nLargest sum %d  and start point is %d   end point is %d  \n",res[0],res[1]+1,res[2]+1);    ///as index is plus one that of returned value
	
	return (0);
}
