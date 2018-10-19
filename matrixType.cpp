#include <iostream>	
#include <vector>	
using namespace std;

typedef std::vector<std::vector<int>> Matrix;

void printVector( Matrix m ){
	std::vector<std::vector<int>>::iterator i;
	std::vector<int>::iterator j;
	for ( i = m.begin() ; i < m.end() ; i++ ){
		for ( j = (*i).begin() ; j < (*i).end() ; j++ ){
			cout << " " << *j;
		}
		cout << std::endl;
	}
}

int main(){
//	Matrix m = {{ 1.0, 0.0, 0.3 }, 
//		{ 0.2, 0.1, 1.0 },
//		{ 0.0, 1.0, 0.7 }};
	Matrix m = {{ 1, 0, 3 },
		{ 2, 1, 1 },
		{ 0, 1, 7 }};


	printVector(m);
	return 0;
}
