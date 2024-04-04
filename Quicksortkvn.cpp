 #include <iostream>
 using namespace std;
 void quick(int a[], int lw, int up);
 int party(int arr[], int lw, int up);
 int main ()
 {
 int arr[] = {12, 85, 69, 74, 25, 65, 71, 692};
 int n = 8, i;
 cout << "The unsorted array is : ";
 for(i=0; i<n; i++)
 {
 cout << arr[i] << " ";
 }
 quick(arr, 0, n-1);
 cout << "The sorted array is : ";
 for(i=0; i<n; i++)
 {
 cout << arr[i] << " ";
 }
 cout << endl;
 }
 void quick(int arr[], int lw, int up)
 {
 int pvtloc;
 if(lw >= up)
 return;
 pvtloc = party(arr, lw, up);
 quick(arr, lw, pvtloc-1);
 quick(arr, pvtloc+1, up);
 }
 int party(int arr[], int lw, int up)
 {
 int temp, i, j, pivot;
 i = lw+1; j = up;
 pivot = arr[lw];
 while(i<=j)
 {
 while((arr[i] < pivot) && (i < up))
 {
}
 i++;
 while(arr[j] > pivot)
 {
 j--;
 }
 if(i<j)
 {
 }
 else
 {
 }
 temp = arr[i];
 arr[i] = arr[j];
 arr[j] = temp;
 i++;
 j--;
 i++;
 arr[lw] = arr[j];
 arr[j] = pivot;
 return j;
 }
 }