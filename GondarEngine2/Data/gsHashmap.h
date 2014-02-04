#ifndef __GS_HASHMAP_H__
#define __GS_HASHMAP_H__

#include "gsArrayList.h"
#include "gsMacros.h"

#define GENERICS template <class K, class V>
#define TABLE_SIZE 256

GENERICS
struct gsKeyValuePair {
	K key;
	V value;

	gsKeyValuePair();
	gsKeyValuePair(K k, V v) { key = k; value = v; }
};

GENERICS
class gsHashMap {
private:
	gsArrayList<gsKeyValuePair<K, V>>* data;
	int size;

public:
	gsHashMap<K, V>(void);
	gsHashMap<K, V>(int size);
	~gsHashMap<K, V>(void);

	V get(K key);

	int hashFunction(K key);

	void add(K key, V value);
	void remove(K key);
	bool contains(K key);
	void clear(void);
};

GENERICS
gsHashMap<K, V>::gsHashMap(void) {
	data = new gsArrayList<gsKeyValue<K, V>>[TABLE_SIZE];
	this->size = TABLE_SIZE;
}

GENERICS
gsHashMap<K, V>::gsHashMap(int size) {
	data = new gsArrayList<gsKeyValue<K, V>>[size];
	this->size = size;
}

GENERICS
gsHashMap<K, V>::~gsHashMap(void) {
	delete[] data;
}

GENERICS
V gsHashMap<K, V>::get(K key) {
	int position = hashFunction(key);
	gsArrayList<gsKeyValue<K, V>>* list = &data[position];
	
	for (int i = 0; i < list->getSize(); i++)
	{
		if (list->get(i).key == key)
		{
			return list->get(i).value;
		}
	}
	gsAssert(0); // Element not found Exception
	return V();
}

GENERICS
int gsHashMap<K, V>::hashFunction(K value)
{
	return (*(int*)value) % size;
}

GENERICS
void gsHashMap<K, V>::add(K key, V value)
{
	int position = hashFunction(key);
	gsArrayList<gsKeyValue<K, V>>* list = &data[position];

	list->add(gsKeyValue<K, V>(key, value));
}

GENERICS
void gsHashMap<K, V>::remove(K key)
{
	int position = hashFunction(key);
	gsArrayList<gsKeyValue<K, V>>* list = &data[position];
	
	for (int i = 0; i < list->getSize(); i++)
	{
		if (list->get(i).key == key)
		{
			list->remove(i);
			return;
		}
	}
	gsAssert(0); // Element not found Exception
}

GENERICS
bool gsHashMap<K, V>::contains(K key)
{
	int position = hashFunction(key);
	gsArrayList<gsKeyValue<K, V>>* list = &data[position];
	
	for (int i = 0; i < list->getSize(); i++)
	{
		if (list->get(i).key == key)
		{
			return true;
		}
	}
	return false;
}

GENERICS
void gsHashMap<K, V>::clear(void)
{
	gsArrayList<gsKeyValue<K, V>>* list;
	for (int i = 0; i < size; i++)
	{
		list = &data[i];
		list->clear();
	}
}

#undef GENERICS
#undef TABLE_SIZE
#endif