//to make it start from 1....n not from 0
//input is 0....n-1 and shift it by one

#define MAXS 100

void shiftMatrix(int mat[][MAXS], int n)
{
	int i,j;
	for(i=n;i>0;i--)
		for(j=n;j>0;j--)
			mat[i][j]=mat[i-1][j-1];
	return;
}
