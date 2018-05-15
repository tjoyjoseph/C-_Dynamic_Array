#include <stdio.h>
#include <string>
#include <iostream>
#include <sstream>

#include <string>

using namespace std;

//class ComponentType; //forward declaration –
//probably replaced a typedef
template <typename Type>
class DynArray //Level 1 version (Professional)
{
private:
	//your choice (data & helper functions)
	const int InitialArraySize = 5;
	int _bufferCapacity;
	Type *_buffer;
	int LastIndex;

	void ExpandBuffer();
	void reset(int ArraySize);
	void copy(const DynArray & tbc);

public:
	DynArray();
	DynArray(DynArray & tbc);
	//DynArray(int);
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
	void Remove(/*Type rmvItem*/ int rmvIndex);
	void Insert(Type newItem, int index);
	DynArray operator=( const DynArray& tbc);
	bool operator==(const DynArray& compArray);
	void Shrink();
	
	/////////////////////////////////////////////////////////////////
	//////////////////[ULTIMATE FUNCTIONALITIES]/////////////////////
	/////////////////////////////////////////////////////////////////
	Type &operator[](int Index);
	DynArray  operator+=(const DynArray& newArray);
	void InsertFront(Type newItem);
	void RemoveFront();
	void ShowAll();
};


template <class Type>
DynArray<Type>::DynArray(){
	reset(InitialArraySize);
}

template <class Type>
DynArray<Type>::DynArray(DynArray & tbc){
	copy(tbc);
}

template <class Type>
DynArray<Type>::~DynArray(){
	delete[] _buffer;
}

template <class Type>
void DynArray<Type>::reset(int ArraySize){
	_bufferCapacity = ArraySize;
	_buffer = new Type[ArraySize];
	LastIndex = -1;
}

template <class Type>
void DynArray<Type>::ExpandBuffer(){
	if (LastIndex == _bufferCapacity){
		Type * Tempbuffer = new Type[_bufferCapacity + InitialArraySize];
		for (int i = 0; i <= _bufferCapacity; i++){
			Tempbuffer[i] = _buffer[i];
		}
		_bufferCapacity += InitialArraySize;
		_buffer = new Type[_bufferCapacity];
		//_buffer = Tempbuffer;
		for (int i = 0; i <=LastIndex; i++){
			_buffer[i] = Tempbuffer[i];
		}

		delete[] Tempbuffer;
	}
}

template <class Type>
void DynArray<Type>::copy(const DynArray & tbc){
	reset(tbc._bufferCapacity);
	_bufferCapacity = tbc._bufferCapacity;
	LastIndex = tbc.LastIndex;
	//_buffer = tbc._buffer;
	for (int i = 0; i <= LastIndex; ++i){
		_buffer[i] = tbc._buffer[i];
	}
}

///////////////////////////////////////////////////////////////////////
////////////////////////[PRO FUNCTIONALITIES]//////////////////////////
///////////////////////////////////////////////////////////////////////
template <class Type>
int DynArray<Type>::capacity() const{
	return _bufferCapacity;
}

template <class Type>
int DynArray<Type>::size() const{
	return LastIndex+1;
}

template <class Type>
bool DynArray<Type>::empty(){
	if (LastIndex == -1){
		return true;
	}
	return false;
}

template <class Type>
void DynArray<Type>::push_back(Type Item){
	LastIndex += 1;
	_buffer[LastIndex] = Item;
	ExpandBuffer();
}

template <class Type>
void DynArray<Type>::pop_back(){
	LastIndex -= 1;
}

template <class Type>
Type DynArray<Type>::back(){
	return _buffer[LastIndex];
}

template <class Type>
Type DynArray<Type>::front(){
	return _buffer[0];
}

template <class Type>
Type DynArray<Type>::get(int index){

	if (index > _bufferCapacity){

		throw out_of_range("Heyyyyy you are crazy");
	}
	return _buffer[index];
}

template <class Type>
void DynArray<Type>::set(Type newItem, int index){
	_buffer[index] = newItem;
}

template <class Type>
void DynArray<Type>::zap(){
	reset(InitialArraySize);
}


///////////////////////////////////////////////////////////////////////////////
//////////////////////////[PRIMIUM FUNCTIONALITIES]////////////////////////////
///////////////////////////////////////////////////////////////////////////////
template <class Type>
void DynArray<Type>::Remove(/*Type rmvItem*/ int rmvIndex){
	/*bool found = false;
	int i = 0;
	while (found = false||i = LastIndex){
	if (_buffer[i] == rmvItem){
	found = true;
	}
	i++;
	}
	if (found == false){
	cout << "Item not found" << endl;
	}*/
	if ((rmvIndex < 0) || (rmvIndex > LastIndex))
	{
		cout << ("The Index doesn't exist") << endl;
	}
	else
	{
		int m;
		for (m = rmvIndex; m < LastIndex + 1; ++m)
		{
			_buffer[m] = _buffer[m + 1];
		}
		//	_buffer[m] = _buffer[m + 1];
		LastIndex = m - 2;
	}

}

template <class Type>
void DynArray<Type>::Insert(Type newItem, int index){
	ExpandBuffer();
	Type temp;
	int i;
	for (i = index; i < LastIndex + 1; ++i)
	{
		temp = _buffer[i];
		_buffer[i] = newItem;
		newItem = temp;
	}
	_buffer[i] = newItem;
	LastIndex += 1;
	ExpandBuffer();
};

template <class Type>
DynArray<Type> DynArray<Type>::operator=(const DynArray& tbc){
	copy(tbc);
	return *this;
};

template <class Type>
bool DynArray<Type>::operator==(const DynArray& compArray){
	bool comparison = false;
	if (LastIndex == compArray.LastIndex){
		for (int i = 0; i < LastIndex; ++i)
		{
			//	cout << this->_buffer[i] << "   -    " << compArray._buffer[i] << endl;
			if (_buffer[i] == compArray._buffer[i]){
				comparison = true;
			}
		}
	}
	return comparison;
}

template <class Type>
void DynArray<Type>::Shrink(){
	Type * Tempbuffer = new Type[LastIndex + 1];
	for (int i = 0; i <= LastIndex; i++){
		Tempbuffer[i] = _buffer[i];
	}
	_bufferCapacity += LastIndex;
	_buffer = new Type[_bufferCapacity + 1];
	//_buffer = Tempbuffer;
	for (int i = 0; i <= _bufferCapacity; i++){
		_buffer[i] = Tempbuffer[i];
	}

	delete[] Tempbuffer;
}
///////////////////////////////////////////////////////////////////////////////////
////////////////////////////[PRIMIUM FUNCTIONALITIES]//////////////////////////////
///////////////////////////////////////////////////////////////////////////////////
template <class Type>
Type &DynArray<Type>::operator[](int Index){
	if ((Index < LastIndex) && (Index >= 0)){
		return _buffer[Index-1];
	}
};

template <class Type>
DynArray<Type>  DynArray<Type>::operator+=(const DynArray& newArray){
	//	DynArray <Type> Array;
	for (int i = 0; i < newArray.LastIndex; ++i)
	{
		this->push_back(newArray._buffer[i]);
	}
	return *this;
};

template <class Type>
void DynArray<Type>::InsertFront(Type newItem){
	_buffer[0] = newItem;
};

template <class Type>
void DynArray<Type>::RemoveFront(){
	Remove(0);
};

template <class Type>
void DynArray<Type>::ShowAll(){
	for (int i = 0; i <= LastIndex; ++i){
		cout << _buffer[i] << "  ";
	}
};