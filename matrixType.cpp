#include <iostream>	
#include <vector>
#include <random>
#include <stdlib.h>

using namespace std;

typedef vector<vector<bool>> Matrix;

bool coin(){
	random_device r;
	mt19937 random_engine{ r()};
	bernoulli_distribution coin_distribution{0.5};

	return coin_distribution(random_engine);
}


void printVector( Matrix m ){
	vector<vector<bool>>::iterator i;
	vector<bool>::iterator j;
	for ( i = m.begin() ; i < m.end() ; i++ ){
		for ( j = (*i).begin() ; j < (*i).end() ; j++ ){
			char c;
			if ( *j == true ){
				c = '*';
			} else {
				c = ' ';
			}
			cout << " " << c;
		}
		cout << endl;
	}
}

Matrix randomMatrix( int n ){
	vector<vector<bool>> m(n);
	for ( int i = 0 ; i < n ; i++ ){
		for ( int j = 0 ; j < n ; j++ ){
			//bool b = rand() % 2;
			bool b = coin();
			m[i].push_back(b);
		}
	}
		

	//Matrix m = {{ true }, {false}};
	return m;
}

int main(){
//	Matrix m = {{ 1, 0, 3 },
//		{ 2, 1, 1 },
//		{ 0, 1, 7 }};

	printVector( randomMatrix( 3 ));
	return 0;
}
