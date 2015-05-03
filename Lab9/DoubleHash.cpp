/*
 * Hash.cpp
 *
 *  Created on: May 1, 2015
 *      Author: Christina
 */


#include "DoubleHash.hpp"
#include<iostream>
using namespace std;


DoubleHash::DoubleHash(){
	size = 29;
	m = 7;
	collisions = 0;
}//DoubleHash

void DoubleHash::findIndex(int *a, int *hash){
	int key;
	for(int i = 0; i < 14; i++){
		if(i == 0){
			key = a[i] % size;
			hash[key] = a[i];
		}//if
		else{
			key = a[i] % size;
			if(hash[key] == -1 && key < 30){
				hash[key] = a[i];
			}//if
			else{
				collisions++;
				key = doubleHash(a, hash, i, key);

				if(key < 30){
					hash[key] = a[i];
				}//if
			}//else
		}//else
	}//for
}//findIndex

int DoubleHash::doubleHash(int *a, int *hash, int index, int key){
		key = key + (1 + a[index] % m);
		for(int i = 2; i < 10; i++){
			if(hash[key] != -1 && key < 30){
				collisions++;
				key = key + i * (1 + a[index] % m);

				if(key > size){
					collisions++;
					key = key - size;
				}//if
			}//if

		else if(hash[key] == -1 && key < 30){
			return key;
		}//else if

		else if(key > size){
			key = key - size;
			return key;
		}//else if
	}//for
}//doubleHash(int size)

void DoubleHash::printHash(int *a, int *hash){
	cout << "After double hashing:" << endl;
	cout << "Key" << "    " << "Number" << endl;
	for(int i = 0; i < 29; i ++){
		cout << i << "      " << hash[i] << endl;
	}//for
	cout << "The total number of collisions is: " << collisions << endl;
}//printHash
