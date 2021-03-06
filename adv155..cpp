/*In computer science, a heap is a specialized tree-based data structure that satisfies the heap property: if P is a parent node of C, then the key (the value) of P is either greater than or equal to (in a max heap) or less than or equal to (in a min heap) the key of C. A common implementation of a heap is the binary heap, in which the tree is a complete binary tree. (Quoted from Wikipedia at https://en.wikipedia.org/wiki/Heap_(data_structure))

One thing for sure is that all the keys along any path from the root to a leaf in a max/min heap must be in non-increasing/non-decreasing order.

Your job is to check every path in a given complete binary tree, in order to tell if it is a heap or not.
Input Specification:

Each input file contains one test case. For each case, the first line gives a positive integer N (1<N≤1,000), the number of keys in the tree. Then the next line contains N distinct integer keys (all in the range of int), which gives the level order traversal sequence of a complete binary tree.
Output Specification:

For each given tree, first print all the paths from the root to the leaves. Each path occupies a line, with all the numbers separated by a space, and no extra space at the beginning or the end of the line. The paths must be printed in the following order: for each node in the tree, all the paths in its right subtree must be printed before those in its left subtree.

Finally print in a line Max Heap if it is a max heap, or Min Heap for a min heap, or Not Heap if it is not a heap at all.
Sample Input 1:

8
98 72 86 60 65 12 23 50

Sample Output 1:

98 86 23
98 86 12
98 72 65
98 72 60 50
Max Heap

Sample Input 2:

8
8 38 25 58 52 82 70 60

Sample Output 2:

8 25 70
8 25 82
8 38 52
8 38 58 60
Min Heap

Sample Input 3:

8
10 28 15 12 34 9 8 56

Sample Output 3:

10 15 8
10 15 9
10 28 34
10 28 12 56
Not Heap

*/

#include <iostream>
#include <vector>


using namespace std;

vector<int> v;
vector<int> path;
int n;

void dfs(int i);
void printpath();
bool ismaxheap,isminheap;


int main()
{
	
	//int n;

	
	cin >> n;
	v.resize(n);
	ismaxheap=isminheap=true;
	
	for(int i=0; i<n; i++){
		cin >> v[i];
	}
	
	path.push_back(v[0]);
	dfs(0);
	
	if(ismaxheap){
		cout <<"Max Heap";
		system("pause");
		return 0;
	}
	
	if(isminheap){
		cout <<"Min Heap";
		system("pause");
		return 0;
	}
	
	cout <<"Not Heap";
	
	system("pause");
	return 0;
 } 
 
 void dfs(int i){
 	
	 
	 if(2*i+1>n-1){
 		printpath();
 		return;
	 }
 	
 	if(2*i+2<n){
 		path.push_back(v[2*i+2]);
 		dfs(2*i+2);
 		path.pop_back();
	 }
 	
 	
 	path.push_back(v[2*i+1]);
 	dfs(2*i+1);
 	path.pop_back();
 	
 }
 
 void printpath(){
 	cout << path[0];
 	
 	for(int i=1; i<path.size(); i++){
 		cout<<" "<<path[i];
 		if(path[i]>path[i-1]){
 			ismaxheap=false;
		 }
		 if(path[i]<path[i-1]){
		 	isminheap=false;
		 }
	 }
	 cout << endl;
	 return;
 }