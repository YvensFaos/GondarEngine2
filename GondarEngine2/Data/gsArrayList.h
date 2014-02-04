#ifndef __GS_ARRAY_LIST_H__
#define __GS_ARRAY_LIST_H__


#define CHUNK_SIZE 16
#define GENERICS template <class T>

#include "System\Subsystems\gsLogger.h"
#include "gsMacros.h"

GENERICS
class gsArrayList {
private:
	T*  data;
	int capacity;
	int size;

public:
	gsArrayList<T>(void);
	gsArrayList<T>(int initialCapacity);
	~gsArrayList(void);

	T get(int i);
	T* getAddress(int i);

	void add(T value);
	void remove(int i);
	void remove(T value);
	bool contains(T value);
	int  indexOf(T value);
	void clear(void);

	int getSize(void) { return size; }
	int getCapacity(void) { return capacity; }
	void log(void);
};


GENERICS
gsArrayList<T>::gsArrayList() {
	capacity = 4;
	size = 0;
	data = new T[capacity];
}

GENERICS
gsArrayList<T>::gsArrayList(int initialCapacity) {
	capacity = initialCapacity;
	size = 0;
	data = new T[capacity];
}

GENERICS
gsArrayList<T>::~gsArrayList(void) {
	delete[] data;
}

GENERICS
T gsArrayList<T>::get(int i) {
	if (i < 0 || i >= size) {
		gsAssert(0); // Array out of bounds exception
	}
	return data[i];
}

GENERICS
	T* gsArrayList<T>::getAddress(int i) {
	if (i < 0 || i >= size) {
		gsAssert(0); // Array out of bounds exception
	}
	return &data[i];
}

GENERICS
void gsArrayList<T>::add(T value) {
	if (size == capacity) {
		capacity += chunkSize;
		T* newData = new T[capacity];
		for (int i = 0; i < size; i++)
		{
			newData[i] = data[i];
		}
		delete[] data;
		data = newData;
	}
	data[size] = value;
	size++;
}

GENERICS
void gsArrayList<T>::remove(int i) {
	if (i < 0 || i >= size) {
		gsAssert(0); // Array out of bounds exception
	}
	size--;
	for (; i < size; i++)
	{
		data[i] = data[i + 1];
	}
}

GENERICS
void gsArrayList<T>::remove(T value) {
	int index = indexOf(value);

	if (index == -1) {
		gsAssert(0); // Element not found exception
	}
	remove(index);
}

GENERICS
bool gsArrayList<T>::contains(T value) {
	return (indexOf(value) != -1);
}

GENERICS
int gsArrayList<T>::indexOf(T value) {
	for (int i = 0; i < size; i++)
	{
		if (data[i] == value) {
			return i;
		}
	}
	return -1;
}

GENERICS
void gsArrayList<T>::clear(void) {
	size = 0;
}

GENERICS
void gsArrayList<T>::log(void) { 
	if (size == 0) {
		GS_LOG("Lista vazia");
		return;
	}

	GS_LOG("Logging a lista inteira: ");
	for (int i = 0; i < size; i++)
	{
		GS_LOG(i << ": " << data[i]);
	}
}


#undef CHUNK_SIZE
#undef GENERICS
#endif