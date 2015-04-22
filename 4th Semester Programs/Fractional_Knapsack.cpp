
// Fractional Knapsack using geedy technique.

#include<iostream>
#include<algorithm>
#include<conio.h>
#define MAX 100

using namespace std;

struct item{
	int p, w;
	float ratio;
};

bool compare(item lhs, item rhs){
	return lhs.ratio > rhs.ratio;
}

float Knapsack(item a[MAX], int m,int n){

	float profit = 0;

	sort(a, a + n, compare);
	for (int i = 0; m; i++){
		if (a[i].w >= m){
			m -= a[i].w;
			profit += a[i].p;
		}
		else{
			profit = a[i].p * ((float)m/a[i].w);
			m = 0;
		}
	}
	return profit;
}

int main(){

	item a[MAX];
	int n, m, i;

	cout << "Enter no. of items : ";
	cin >> n;

	cout << "Enter profit of each item";
	for (i = 0; i < n; i++)
		cin >> a[i].p;

	cout << "Enter weight of each item";
	for (i = 0; i < n; i++)
		cin >> a[i].w;

	cout << "Enter total capacity : ";
	cin >> m;

	cout << "The maximum profit is : " << Knapsack(a, m, n) << endl;

	_getch();
	return 0;
}