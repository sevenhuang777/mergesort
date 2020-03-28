#include<stdio.h>

int input[100]={10,3,10,9,8,7,6,5,4,3,2,1};
int temp[100];

void printf_array(int input[], int length)
{
	int i = 0;
	for(i = 0; i < length; i++)
	{
		printf("%d ", input[i]);
	}
	printf("\n");
}

void merge(int array[], int left, int mid, int right)
{
	int l = left, p = left;
	int r = mid +1;
	int i = 0;
	while((l <= mid) && (r <= right))
	{
		if(array[l] > array[r])
		{
			temp[p] = array[r++];
		}
		else
		{
			temp[p] = array[l++];
		}
		p++;
	}
	if(l > mid)
	{
		for(;r <= right; r++ )
		{
			temp[p] = array[r];
			p++;
		}
	}
	if(r > right)
	{
		for(;l <= mid; l++ )
		{
			temp[p] = array[l];
			p++;
		}
	}
	
	for(i = left; i<=right; i++)
	{
		 array[i] = temp[i];
	}
}

void merge_sort(int array[], int left, int right)
{
	int mid = (left + right)/2;
	int p = 0;

	if(left>=right)
	{
		//printf("%d ", array[left]);
		return;
	}
	else
	{
		merge_sort(array, left, mid);
		merge_sort(array, mid+1, right);
		merge(array, left, mid, right);
	}
}

int main()
{
	//int test[6] = {3,9,68,1,6,100};
	//merge(test, 0, 0, 1);
	//printf_array(temp, 2);
	merge_sort(input, 0, 11);
	printf_array(input, 12);
	return 0;
}