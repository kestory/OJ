Arrays
The output was "xx xx xx xx"//notice the space
So I need do this after for loop:
	for (int arr_i = n - 1; arr_i > 0; arr_i--)
			printf("%d ", arr[arr_i]);
	printf("%d", arr[0]);
-------------------------------------------------
2D Array
Just 16 hourglass sum, calculate each of them and put them in the "vector<int> v(16, 0);" and then:
int max = *max_element(v.begin(), v.end());
done.
