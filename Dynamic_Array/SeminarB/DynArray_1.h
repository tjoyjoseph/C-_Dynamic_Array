#include <stdio.h>
#include <string>
#include <iostream>
#include <sstream>
#include <typeinfo>


using namespace std;

const int InitialArray = 5;



//class ComponentType; //forward declaration –
//probably replaced a typedef
template <typename Type>
class DynArray //Level 1 version (Professional)
{
private:
	//your choice (data & helper functions)
	int ArraySize;
	int LastIndex;
	Type * _buffer;
	Type null;

	void reset(){
		int n;
		ArraySize = InitialArray;
		_buffer = new Type[ArraySize];
		LastIndex = 0;
	};

	void nullcheck(){
		if (typeid(Type) == (typeid(int)) || (typeid(Type) == typeid(double)) || (typeid(Type) == typeid(float))){
			for (int i = 0; i < ArraySize; i++){
				_buffer[i] = 0;
			}
		}
		else if (typeid(Type) == typeid(string)){
			for (int i = 0; i < ArraySize; i++){
				_buffer[i] = "Null";
			}
		}
		else if (typeid(Type) == typeid(char)){
			for (int i = 0; i < ArraySize; i++){
				_buffer[i] = 'N';
			}
		}
	}

public:
	DynArray(){
		reset();
		nullcheck();
	};
	/*DynArray(DynArray);
	DynArray(int);*/
	~DynArray(){
		delete[] _buffer;
	};

	////[PRO FUNCTIONALITY]
	int capacity() const{
		return ArraySize;
	};
	int size() const{
		return LastIndex;
	};
	bool empty(){
		if (LastIndex == 0){
			return true;
		}
		return false;
	};
	void push_back(Type Item){
		if (LastIndex == ArraySize){
			Type * _Tbuffer = new Type[ArraySize + InitialArray];
			for (int i = 0; i < ArraySize; i++){
				_Tbuffer[i] = _buffer[i];
			}
			ArraySize += InitialArray;
			_buffer = new Type[ArraySize];
			nullcheck();
			for (int i = 0; i <LastIndex; i++){
				_buffer[i] = _Tbuffer[i];
			}
			delete[] _Tbuffer;
		}
		_buffer[LastIndex] = Item;
		LastIndex += 1;
	};
	void pop_back(){
		LastIndex -= 1;
	};
	Type back(){
		if (LastIndex == 0){
			return _buffer[LastIndex];
		}
		return _buffer[LastIndex - 1];
	};
	Type front(){
		return _buffer[0];
	};
	Type get(int index){
		return _buffer[index - 1];
	}
	void set(Type newItem, int index){
		_buffer[index - 1] = newItem;

	};
	void zap(){
		reset();
		nullcheck();
	};

	////[PREMIUM FUNCTIONALITY]
	void Constructor();
	void Remove();
	void Insert();
	void Asignment();
	bool Equality();
	void Shrink();
};