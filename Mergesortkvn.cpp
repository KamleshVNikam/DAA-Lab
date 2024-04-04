 #include<iostream>
 using namespace std;
 void merges(int a[], int l, int up);
 void merge(int arr[], int temp[], int l1, int up1, int l2, int up2);
 void copy(int arr[], int temp[],int low, int up);
 int main()
 {
 }
 int a[7]={2,33,54,6,87,11,12},i;
 int n=7;
 merges(a,0,n-1);
 cout << "The unsorted array is : ";
 for(i=0; i<n; i++)
 {
 cout << a[i] << " ";
 }
 cout << "\nThe sorted array is : ";
 for(i=0; i<n; i++)
 {
 cout<<a[i];
 }
 return 0;
 void merges(int a[], int l, int up)
 {
 int mid;
 int temp[10];
 if(l<up)
 {
 mid=(l+up)/2;
 merges(a,l,mid);
 merges(a,mid+1,up);
 merge(a,temp,l,mid,mid+1,up);
 copy(a,temp,l,up);
 }
 }
 void merge(int arr[],int temp[], int l1, int up1, int l2, int up2)
 {
 int i=l1;
 int j=l2;
 int k=l1;
 while((i<=up1)&&(j<=up2))
 {
 if(arr[i]<arr[j])
 temp[k++]=arr[i++];
else
 temp[k++]=arr[j++];
 }
 while(i<=up1)
 temp[k++]=arr[i++];
 while(j<=up2)
 temp[k++]=arr[j++];
 }
 void copy(int arr[], int temp[], int low, int up)
 {
 int i;
 for(i=low; i<=up; i++)
 {
 arr[i]=temp[i];
 }
 }