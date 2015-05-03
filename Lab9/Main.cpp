/*
 * Main.cpp
 *
 *  Created on: May 1, 2015
 *      Author: Christina
 */
#include "DoubleHash.hpp"
#include<iostream>
using namespace std;

int main(){
	DoubleHash *dh = new DoubleHash();
	int a[14] = {560, 671, 353, 502, 490, 757, 38, 410, 904, 93, 818, 577, 3, 671};

	int *hash = NULL;
	hash = new int[29];
	for(int i = 0; i < 29; i++){
		hash[i] = -1;
	}//for

	dh->findIndex(a, hash);
	dh->printHash(a, hash);
	return 0;
}//main()




