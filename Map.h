#pragma once
#include<iostream>
#include<SmarterArray.h>
using namespace std;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class K, class V>
class Map
{
private:
	SmarterArray<K> A1;	//The keys of the map
	SmarterArray<V> A2;	//The values of the map

public:
	//Constructors
	Map(); //Implemented for you
	Map(const Map<K, V>& obj){
		*this = obj;
	} //Copy constructor. Deep copy.

	//Assignment operator
	Map<K, V>& operator = (const Map<K, V>& obj){
		A1 = obj.A1;
		A2 = obj.A2;

		return this;
	} //Assignment operator. Memory clean up and deep copy.

	//Destructor
	~Map(){
		~A1();
		~A2();
	} //Destructor.

	//Getters, Setters, operators and other functions
	int getSize() const{
		return A1.size();
	} //Return the common size of the map.
	int findKey(const K& k) const{
		for (int i = 0; i < A1.getSize(); i++){
			if(A1[i] == k){return i;}
		}
		return -1;
	} //Return the index of the first element of the Keys array == the argument. Return -1 if not found.
	int findValue(const V& val) const{
		for (int i = 0; i < A2.getSize(); i++){
			if(A2[i] == val){return i;}
		}
		return -1;
	} //Return the index of the first element of the Values array == the argument. Return -1 if not found.
	K getKey(const V& val) const{
		return A1[findValue(val)];
	} //Assert the argument is found in the Values array and then return the first key with the given value 
	V getValue(const K& k) const{
		return A2[findKey(k)];
	} //Assert the argument is found in the Keys array and then return the first value with the given key
	K getKeyAtIndex(const int& index) const{
		return A1[index];
	} //Assert the index argument and then return the key at the given index
	V getValueAtIndex(const int& index) const{
		return A2[index]
	} //Assert the index argument and then return the value at the given index
	void setKeyAtIndex(const int& index, const K& k){
		A1[index] = k;
	} //Assert the index argument and then set the key at the given index
	void setValueAtIndex(const int& index, const V& val){
		A2[index] = val;
	} //Assert the index argument and then set the value at the given index
	void append(const K& k, const V& val){
		A1.append(k);
		A2.append(val);
	} //Append the key-value pair to the calling object
	bool remove(const int& index){
		A1.remove(index);
		A2.remove(index);
	} //If the index argument is a valid index, then remove the key-value pair at the index argument
							//from the calling object and return true. Otherwise return false. 
							//You don't need to assert the index argument.

	template <class KF, class VF>
	friend ostream& operator << (ostream&, const Map<KF, VF>&); //Implemented for you
};
template <class K, class V>
Map<K, V>::Map()
{
	//No code is needed here.
	//The member variables will automatically be initialized as default objects
}


template <class KF, class VF>
ostream& operator << (ostream& out, const Map<KF, VF>& m)
{
	if (m.getSize() == 0)
		out << "[Empty Map]" << endl;
	else
	{
		for (int i = 0; i < m.getSize(); i++)
			out << m.A1[i] << ", " << m.A2[i] << endl;
	}
	return out;
}