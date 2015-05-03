/*
 * Hash.hpp
 *
 *  Created on: May 1, 2015
 *      Author: Christina
 */

#ifndef DOUBLEHASH_HPP_
#define DOUBLEHASH_HPP_


class DoubleHash{
	int size;
	int m;
	int collisions;

public:
	DoubleHash();
	void findIndex(int *a, int *hash);
	int doubleHash(int *a, int *hash, int index, int key);
	void printHash(int *a, int *hash);
};


#endif /* DOUBLEHASH_HPP_ */
