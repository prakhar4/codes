public class primes
{

public static void main(String[] args)
{
	int i,j,k,  n=50;
	int[] a;
	a= new int[100];
	a[0]=2;
	a[1]=3;
	
	for(i=2;i<n;i++)
		{
			k=a[i-1];
			k+=2;
			j=0;
			ABC:
			
			/*k++;  THE LABEL SHOULD BE JUST ABOVE THE LOOP- NO OTHER STATEMENT IN BETWEEN.
			j=0;                       THESE STATEMENTS DONT ALLOW THE LABELLED  
			System.out.println("working");    CONTINUE TO WORK      */
			
			
			while(a[j]<=(Math.sqrt(k))  )   
			{if(k%a[j]==0)
				{
                    k+=2;
                    j=0;
                    continue ABC;
				}
			j++;
			
			}
			a[i]=k;
				
		
		}
		
    for(i=0;i<n;i++)
		System.out.println(" the prime no is "+a[i]);
	/*
	for(i=0; i<n; i++)		
		System.out.println(" the prime no is "+a[i]);*/
		
		
}
}
