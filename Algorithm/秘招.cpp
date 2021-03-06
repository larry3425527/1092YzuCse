#include <iostream>
using namespace std;
int main()
{
	int a[2][2][3] = {{{4,3,2},{1,3,2}},
						{{3,1,2} , {2,1,3}}};
	int b[2][2][3] = {{{1,2,3},{3,2,1}},
						{{3,4,2},{2,1,3}}};
	for(int i = 0 ; i<5; i++)
	{
		for(int j = 4 ; j >= 0 ; j--)
			cout << a[i%2][j%2][i%3] + b[j%2][i%2][j%3];
		cout << endl;
	}
	return 0;
						
} 
