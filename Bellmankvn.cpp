 #include <iostream>
 using namespace std;
 #define MAX 100
 #define infty 9999
 #define NIL -1
 #define TRUE 1
 #define FALSE 0
 int n, front, rear;
 int adj[MAX][MAX];
 int prede[MAX];
 int pl[MAX];
 int ispqueue[MAX], queue[MAX], dltqueue(), emptqueue(); 
void intlqueue();
 void insrtqueue(int u);
 void cretgraph();
 void fndpath(int s, int v);
 int bellman(int s);
 int main()
 {
 int flag, s, v;
 cretgraph();
 cout << "Enter source vertex : ";
 cin >> s;
 flag = bellman(s);
 if(flag == -1)
 {
 cout << "Error : Negative cycle in graph" << endl;
 exit(1);
 }
 while(1)
 {
 cout << "Enter destination vertex : ";
 cin >> v;
 if(v == -1)
 break;
 if(v<0 || v>=n)
 cout << "This vertex doesn't exists" << endl;
 else if(v==s)
 cout << "Source and destination vertex same" << endl;
 else if(pl[v] == infty)
 cout << "There is no path from source to destination" << endl;
 else
 }
 }
 fndpath(s, v);
 void fndpath(int s, int v)
{
 int i, u, path[MAX], shortdist = 0, count = 0;
 while(v != s)
 {
 count++;
 path[count]++;
 u = prede[v];
 shortdist += adj[u][v];
 v = u;
 }
 count++;
 path[count] = s;
 cout << "Shortest path is : ";
 for(i = count; i>=1; i--)
 cout << path[i] << endl;
 cout << "Shortest dist. is : " << shortdist;
 }
 int bellman(int s)
 {
 int k=0, i, current;
 for(i=0; i<n; i++)
 {
 prede[i] = NIL;
 pl[i] = infty;
 ispqueue[i] = FALSE;
 }
 intlqueue();
 pl[s]= 0; 
insrtqueue(s);
 ispqueue[s] = TRUE;
 while(!emptqueue()) 
{
 current = dltqueue();
 ispqueue[current] = FALSE;
 if(s==current)
 k++;
 if(k>n)
 return -1; 
for(i=0; i<n; i++)
 {
 if(adj[current][i] != 0)
 if (pl[i] > pl[current] + adj[current][i])
 {
 pl[i] = pl[current] + adj[current][i];
 prede[i] = current;
 if(!ispqueue[i])
{
 insrtqueue(i);
 ispqueue[i]=TRUE;
 }
 }
 }
 }
 return 1;
 }
 void intlqueue()
 {
 for(int i=0; i<MAX; i++)
 queue[i] = 0;
 rear = -1; front = -1;
 }
 int emptqueue()
 {
 if(front==-1 || front>rear)
 return 1;
 else
 return 0;
 }
 void insrtqueue(int added_item)
 {
 if (rear==MAX-1)
 {
 printf("Queue Overflow\n"); 
exit(1);
 }
 else
 {
 }
 }
 int dltqueue()
 {
 int d;
 if (front==-1) 
front = 0; 
rear = rear+1; 
queue [rear] = added_item;
 if(front==-1 || front>rear)
 {
 printf("Queue Underflow\n"); 
exit(1);
 }
 else
 {
 d = queue [front]; 
front = front+1;
 }
 return d; 
}
 void cretgraph()
 {
 cout<<"enter the number of vertice:";
 cin>>n;
   
    cout<<"enter the adjacency matrix:\n";
    for(int i = 0;i<n;i++)
    {
    for (int j = 0; j<n;j++)
    {
    cin >>adj[i][j];
    }
   }
 }