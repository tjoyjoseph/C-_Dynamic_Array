#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

#ifndef DYNARRAY_H
#define DYNARRAY_H

template <typename Type>
class DynArray
{
private:
	const int INITIAL_ARRAY_SIZE = 5;
	int _bufferCapacity;
	Type *_buffer;
	int lastIndex;

	void expandBuffer();
	void reset(int ArraySize);
	void copy(const DynArray & tbc);
public:
	DynArray();
	DynArray(DynArray & tbc);
	~DynArray();

	////////////////////////////////////
	////////[PRO FUNCTIONALITY]/////////
	////////////////////////////////////
	int capacity() const;
	int size() const;
	bool empty();
	void push_back(Type Item);
	void pop_back();
	Type back();
	Type front();
	Type get(int index);
	void set(Type newItem, int index);
	void zap();

	/////////////////////////////////////////////////////////////////
	///////////////////[PREMIUM FUNCTIONALITY]///////////////////////
	/////////////////////////////////////////////////////////////////
	void remove(int rmvIndex);
	void insert(Type newItem, int index);
	DynArray operator=(const DynArray& tbc);
	bool operator==(const DynArray& compArray);
	void shrink();

	/////////////////////////////////////////////////////////////////
	//////////////////[ULTIMATE FUNCTIONALITIES]/////////////////////
	/////////////////////////////////////////////////////////////////
	Type &operator[](int Index);
	DynArray  operator+=(const DynArray& newArray);
	void insertFront(Type newItem);
	void removeFront();
	void showAll();
};
#endif // !DYNARRAY_H

///Constructor
template <class Type>
DynArray<Type>::DynArray()
{
	reset(INITIAL_ARRAY_SIZE);	
}

///Copy Constructor
template <class Type>
DynArray<Type>::DynArray(DynArray & tbc)
{
	copy(tbc);
}

///Destructor
template <class Type>
DynArray<Type>::~DynArray()
{
	delete[] _buffer;
}

///Rests array back to its initial state
template <class Type>
void DynArray<Type>::reset(int ArraySize)
{
	_bufferCapacity = ArraySize;
	_buffer = new Type[ArraySize];
	lastIndex = -1;
}

///when the array is full, expands the capacity by the initial array size
template <class Type>
void DynArray<Type>::expandBuffer()
{
	///checks if array is full
	if (lastIndex == _bufferCapacity)
	{
		///creates a temporary buffer bigger than the current buffer
		///copies all files from cuurent cuffer to temporary buffer
		Type * Tempbuffer = new Type[_bufferCapacity + INITIAL_ARRAY_SIZE];
		for (int i = 0; i <= _bufferCapacity; i++)
		{
			Tempbuffer[i] = _buffer[i];
		}
		///ammends current buffer properties and resets current buffer with expanded size to match temp buffer
		///copies files from temp buffer to the resetted bufffer  then deletes temp buffer
		_bufferCapacity += INITIAL_ARRAY_SIZE;
		_buffer = new Type[_bufferCapacity];
		for (int i = 0; i <= lastIndex; i++)
		{
			_buffer[i] = Tempbuffer[i];
		}
		delete[] Tempbuffer;
	}
}

///used to copy friles from an external dynamic array to the current one
///done by resetting the array, matching the properties and then copying the items
template <class Type>
void DynArray<Type>::copy(const DynArray & tbc)
{
	reset(tbc._bufferCapacity);
	_bufferCapacity = tbc._bufferCapacity;
	lastIndex = tbc.lastIndex;
	for (int i = 0; i <= lastIndex; ++i)
	{
		_buffer[i] = tbc._buffer[i];
	}
}

///////////////////////////////////////////////////////////////////////
////////////////////////[PRO FUNCTIONALITIES]//////////////////////////
///////////////////////////////////////////////////////////////////////

///returns buffer capacity
template <class Type>
int DynArray<Type>::capacity() const
{
	return _bufferCapacity;
}

///returns buffer size
template <class Type>
int DynArray<Type>::size() const
{
	return lastIndex + 1;
}

///returns true if buffer is empty, else false
template <class Type>
bool DynArray<Type>::empty()
{
	if (lastIndex == -1)
	{
		return true;
	}
	return false;
}

///adds one element to the buffer, expands buffer if need be
template <class Type>
void DynArray<Type>::push_back(Type Item)
{
	lastIndex += 1;
	_buffer[lastIndex] = Item;
	expandBuffer();
}

///deletes the last element from the buffer
template <class Type>
void DynArray<Type>::pop_back()
{
	lastIndex -= 1;
}

///returns the last element of the buffer
template <class Type>
Type DynArray<Type>::back()
{
	return _buffer[lastIndex];
}

///returns the first element of the buffer
template <class Type>
Type DynArray<Type>::front()
{
	return _buffer[0];
}

///returns the element in the index defined by the parameters
template <class Type>
Type DynArray<Type>::get(int index)
{
	if (index > lastIndex)
	{
		//throw out_of_range("The Index is out of range");
	}
	return _buffer[index];
}

///replaces index element defined by the parameters with element defined by the parameters.
///Produces error if out of range
template <class Type>
void DynArray<Type>::set(Type newItem, int index)
{
	if ((index > lastIndex) || (index < 1))
	{
		//throw out_of_range("The Index is out of range");
	}
	else
	{
		_buffer[index] = newItem;
	}
}

///resets buffer to its original state
template <class Type>
void DynArray<Type>::zap()
{
	reset(INITIAL_ARRAY_SIZE);
}


///////////////////////////////////////////////////////////////////////////////
//////////////////////////[PRIMIUM FUNCTIONALITIES]////////////////////////////
///////////////////////////////////////////////////////////////////////////////

///removes index element if it exists, else produces an error
template <class Type>
void DynArray<Type>::remove(int rmvIndex)
{
	if ((rmvIndex < 0) || (rmvIndex > lastIndex))
	{
		//throw out_of_range("The Index is out of range");
	}
	else
	{
		///sets all elements after the proposed elements need removing, back by one
		int m;
		for (m = rmvIndex; m < lastIndex + 1; ++m)
		{
			_buffer[m] = _buffer[m + 1];
		}
		lastIndex = m - 2;
	}
}

///inserts element into th proposed index
///done by inserting element and then moving all other elements down by one
template <class Type>
void DynArray<Type>::insert(Type newItem, int index)
{
	expandBuffer();
	Type temp;
	int i;
	for (i = index; i < lastIndex + 1; ++i)
	{
		temp = _buffer[i];
		_buffer[i] = newItem;
		newItem = temp;
	}
	_buffer[i] = newItem;
	lastIndex += 1;
	expandBuffer();
}

///copies everything from external array into this array
template <class Type>
DynArray<Type> DynArray<Type>::operator=(const DynArray& tbc)
{
	copy(tbc);
	return *this;
}

///compare external array with this array based on its elements and its properties. 
///All have to match for it to be true
template <class Type>
bool DynArray<Type>::operator==(const DynArray& compArray)
{
	bool comparison = false;
	if (lastIndex == compArray.lastIndex)
	{
		for (int i = 0; i < lastIndex; ++i)
		{
			if (_buffer[i] == compArray._buffer[i])
			{
				comparison = true;
			}
		}
	}
	return comparison;
}

///shrinks array size to its last element
template <class Type>
void DynArray<Type>::shrink()
{
	///creates a temporary smaller buffer, and copies everything from current buffer to this buffer
	Type * Tempbuffer = new Type[lastIndex + 1];
	for (int i = 0; i <= lastIndex; i++)
	{
		Tempbuffer[i] = _buffer[i];
	}
	///creates new buffer based on temporary buffer's size 
	///copies everything from temp buffer to current buffer
	_bufferCapacity += lastIndex;
	_buffer = new Type[_bufferCapacity + 1];
	for (int i = 0; i <= _bufferCapacity; i++)
	{
		_buffer[i] = Tempbuffer[i];
	}
	delete[] Tempbuffer;
}
///////////////////////////////////////////////////////////////////////////////////
////////////////////////////[PRIMIUM FUNCTIONALITIES]//////////////////////////////
///////////////////////////////////////////////////////////////////////////////////

///can be used to return index element requested, or even change the index element requested
template <class Type>
Type &DynArray<Type>::operator[](int Index)
{
	if ((Index < lastIndex) && (Index >= 0))
	{
		return _buffer[Index - 1];
	}
}

//adds on additional elements from the external array into this array
template <class Type>
DynArray<Type>  DynArray<Type>::operator+=(const DynArray& newArray)
{
	for (int i = 0; i < newArray.lastIndex; ++i)
	{
		this->push_back(newArray._buffer[i]);
	}
	return *this;
}

///replaces an element in the front
template <class Type>
void DynArray<Type>::insertFront(Type newItem)
{
	_buffer[0] = newItem;
}

///removes the element in the front
template <class Type>
void DynArray<Type>::removeFront()
{
	remove(0);
}

//Displays all element of the array
template <class Type>
void DynArray<Type>::showAll()
{
	for (int i = 0; i <= lastIndex; ++i)
	{
		cout << _buffer[i] << "  ";
	}
}