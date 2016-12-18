#ifndef __PERMUTATION3_H_INCLUDED
#define __PERMUTATION3_H_INCLUDED

#include "Common.hpp"

class Permutation3 {

private:

	int **permutation; 
	int temp_permutation[2];
	int m;

public:

	Permutation3(int a[3]);
	int** get_permutation_tupple();
	void print_permutation_tupple();
	void generate_permutation(int *a, int l, int r);
	void swap(int *a, int *b);

};

#endif /* PERMUTATION3_H_INCLUDED */
