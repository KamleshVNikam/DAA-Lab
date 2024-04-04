 #include<iostream>
 using namespace std;
 void knapsack(int n, float wt[], float pft[], float capy)
 {
 float x[20], tp = 0;
 int i, j, u;
 u = capy;
 for (i = 0; i < n; i++)
 {
 x[i] = 0.0;
 }
 for (i = 0; i < n; i++)
 {
 if(wt[i] > u)
 break;
 else
 {
 x[i] = 1.0;
 tp = tp + pft[i];
 u = u - wt[i];
 }
 }
 if (i < n)
 x[i] = u / wt[i];
 tp = tp + (x[i] * pft[i]);
 cout << "The result vector is: " << endl;
 for(i = 0; i < n; i++)
 cout << x[i];
 cout << "Maximum profit is: " << tp << endl;
 }
 int main()
 {
 float wt[20], pft[20], capy;
 int num, i, j;
 float ratio[20], temp;
 cout << "Enter the no. of objects: ";
 cin >> num;
 cout << "Enter the wts and profits of each object: " << endl; 
for (i = 0; i < num; i++)
 {
 cin >> wt[i] >> pft[i];
 }
cout << "Enter the capacity of knapsack: ";
 cin >> capy;
 cout << endl;
 for(i = 0; i < num; i++)
 {
 ratio[i] = pft[i] / wt[i];
 }
 for (i = 0; i < num; i++)
 {
 for (j = i + 1; j < num; j++)
 {
 if (ratio[i] < ratio[j])
 {
 temp = ratio[j];
 ratio[j] = ratio[i];
 ratio[i] = temp;
 
temp = wt[j];
 wt[j] = wt[i];
 wt[i] = temp;
 temp = pft[j];
 pft[j] = pft[i];
 pft[i] = temp;
 }
 }
 }
 knapsack(num, wt, pft, capy);
 return(0);
 }