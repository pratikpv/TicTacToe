using namespace std;

#include <iostream>
#include "Permutation3.hpp"
#include "Board.hpp"
#include "Player.hpp"

Permutation3::Permutation3(int arr[3]){

	permutation = new int*[6];
	for(int i = 0; i < 6; ++i)
	    permutation[i] = new int[3];
	m = 0;
	generate_permutation(arr, 0, 2);

}

/*Permutation3:: ~Permutation3(){

	delete []permutation ;

}*/

int**  Permutation3::get_permutation_tupple(){
	
	return permutation;

}

void Permutation3::print_permutation_tupple(){

	cout << "\n" ;
	for (int index=0; index < 6  ; index++) {
		cout << "\n " << index << " : ";
		for( int i =0; i< 3 ;i++)
			cout  << permutation[index][i] << " "  ;
	    }
	cout << "\n";
	
}

void Permutation3::generate_permutation(int *a, int l, int r)
{
	   int i;
	   if ( l == r ) {
		   for (int i = 0 ; i<=2 ;i++) {
			permutation[m][i] = a[i];
		   }
		   m++;
	   }
	   else
	   {
	       for (i = l; i <= r; i++)
	       {

	          swap(&a[l], &a[i]);
	          generate_permutation(a, l+1, r);
	          swap(&a[l], &a[i]); /* backtrack */

	       }
	   }
}

void Permutation3::swap(int *a, int *b)
{

    int temp;
    temp = *a;
    *a = *b;
    *b = temp;

}
