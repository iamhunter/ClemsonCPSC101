int inner_product(int a[], int b[], int count){

	int sum = 0;
	int x;
	
	for (x=0; x<count; x++){
		sum = sum + a[x]*b[x];
	}
	return(sum);
}

void reverse(int a[], int count)
{
	int x;
	int end = count-1;
	
	for(x = 0; x<count/2; x++){
		int temp = a[x];
		a[x] = a[end];
		a[end] = a[temp];
		end--;
	}
}
