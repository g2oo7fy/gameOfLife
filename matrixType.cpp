#include <iostream>	
#include <vector>
#include <random>
#include <stdlib.h>
#include <functional>

using namespace std;

typedef vector<vector<int>> Matrix;

int coin(){
	random_device r;
	mt19937 engine{ r()};
//	bernoulli_distribution coin_distribution{0.5};
	uniform_int_distribution<int> d(0, 1);
	auto generator = bind( d, engine );

//	return coin_distribution(random_engine);
	return generator();
}


void printVector( Matrix m ){
	vector<vector<int>>::iterator i;
	vector<int>::iterator j;
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
	vector<vector<int>> m(n);
	for ( int i = 0 ; i < n ; i++ ){
		for ( int j = 0 ; j < n ; j++ ){
			int b = coin();
			m[i].push_back(b);
		}
	}
		
	return m;
}

int matrixSum( Matrix m ){
	vector<vector<int>>::iterator i;
	vector<int>::iterator j;
	int sum = 0;
	for ( i = m.begin() ; i < m.end() ; i++ ){
		for ( j = (*i).begin() ; j < (*i).end() ; j++ ){
			sum += *j;
		}
	}
	return sum;
}


int main(){
	Matrix m;
	m = randomMatrix( 3 );
	printVector( m );
	cout << matrixSum( m ) << endl;
	return 0;
}
