#pragma once
#include<iostream>
#include<assert.h>
using namespace std;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//use as vector 
template <class T>
class SmarterArray
{
private:
	T *A;
	int size;

public:
	//Constructors
	SmarterArray(); //Implemented for you
	SmarterArray(const SmarterArray<T>& obj){
		this->A = obj;
	} //Copy constructor: Deep copy of the argument

	//Assignment operator
	SmarterArray<T>& operator = (const SmarterArray<T>& obj){
		delete[] A;
		size = obj.size;
		A = new T[size];
		for (int i = 0; i < size; i++){
			A[i] = obj.A[i];
		}
		return *this;
	} //Assignment operator. Memory clean up and deep copy of the argument

	//Destructor
	~SmarterArray()
	{
		delete[] A;
	} //Destructor. Memory clean up

	//Getters, Setters, operators and other functions
	int getSize() const{
		return size;
	} //Return the size of the calling object
	T& operator[](const int& index) const{
		assert(index < size && index >= 0);
		return A[index];
	} //Assert index is valid and then return the element at the given index
	int find(const T& item) const{
		for (int i = 0; i < size; i++){
			if (item == A[i]){
				return i;
			}
		}
		return -1;
	} //Return the index of the element that is == to the argument. Return -1 if not found.
	void append(const T& item){
		SmarterArray<T> temp;
		temp.size = size + 1;
		temp.A = new T[temp.size];
		for (int i = 0; i < size; i++){
			temp.A[i] = this->A[i];
		}
		temp.A[size] = item;
		*this = temp;
 	} //Append the argument to the calling object.

	bool remove(const int& index){
		if (index < 0 || index >= size){
			return 0;
		}
		SmarterArray<T> temp;
		temp.size = size - 1;
		temp.A = new T[size - 1];
		for (int i = 0; i < index; i++){
			temp.A[i] = A[i];
		}
		for (int i = index + 1; i < size; i++){
			temp.A[i - 1] = A[i];	
		}
		*this = temp;

		return 1;
	} //If the index argument is a valid index, then remove the element at the index argument
	//from the calling object and return true. Otherwise return false. 
	//You don't need to assert the index argument.

	bool operator == (const SmarterArray<T>& obj) const{
		if (obj.size != size) return 0;
		for (int i = 0; i < size; i++){
			if (obj.A[i] != A[i]){
				return 0;
			}
		}
		return 1;
	} //return true if sizes are equal and elements at same indexes are ==
	
	template <class TF>
	friend ostream& operator << (ostream&, const SmarterArray<TF>&); //Implemented for you
};
template <class T>
SmarterArray<T>::SmarterArray()
{
	this->A = nullptr;
	this->size = 0;
}

template <class TF>
ostream& operator << (ostream& out, const SmarterArray<TF>& L)
{
	if (L.getSize() == 0)
		out << "[Empty List]";
	else
	{
		for (int i = 0; i < L.getSize()-1; i++)
			out << L[i] << endl;
		out << L[L.getSize()-1] << endl;
	}
	return out;
}
