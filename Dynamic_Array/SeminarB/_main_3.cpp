#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

const int InitialArray = 5;

class ComponentType; //forward declaration –
//probably replaced a typedef
class DynArray //Level 1 version (Professional)
{
private:
	//your choice (data & helper functions)
	
	int ArraySize;
	int LastIndex;
	int * Array;

	void reset(){
		int n;
		ArraySize = InitialArray;
		Array = new int[ArraySize];
		for (n = 0; n < ArraySize; n++){
			Array[n] = NULL;
		}
		LastIndex = 0;
	};

public:
	DynArray(){
		reset();
	};
	
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
	void push_back(int Item/*ComponentType*/){
		if (LastIndex == ArraySize){
			ArraySize += InitialArray;
			int * buffer = new int[ArraySize];
			for (int i = 0; i < ArraySize; i++){
				buffer[i] = Array[i];
			}
			Array = new int[ArraySize];
			for (int i = 0; i <ArraySize; i++){
				Array[i] = NULL;
			}
			for (int i = 0; i <LastIndex; i++){
				Array[i] = buffer[i];
			}
			delete[] buffer;
		}
		Array[LastIndex] = Item;
		LastIndex += 1;

		//for (int i = 0; i <ArraySize; i++){
			//cout << Array[i] << "  ";
		//}

	};
	void pop_back(){
		Array[LastIndex] = NULL;
		//delete[LastIndex] Array;
		LastIndex -= 1;
	};
	int /*ComponentType*/ back(){
		//////for (int i = 0; i < 5; i++){ cout << Array[i] << " "; }
		if (Array[0] == NULL){
			return Array[LastIndex];
		}
 		return Array[LastIndex-1];
	};
	int /*ComponentType*/ front(){
		//////for (int i = 0; i < 5; i++){ cout << Array[i] << " "; }
		return Array[0];
	};
	int /*ComponentType*/ get(int index){
		return Array[index-1];
	}
	void set(/*ComponentType*/int newItem, int index){
		Array[index-1] = newItem;

	};
	void zap(){
		reset();
	};
	/*DynArray(DynArray);
	DynArray(int);*/

	//~DynArray();
};




int main(int argc, char* argv[])
{
	DynArray Put;

	for (int i = 0; i < 7; i++){ Put.push_back(i+10); }

	cout << " \nback = " << Put.back() << endl;
	cout << " front = " << Put.front() << endl;

	cout << " \nCapatcity = "<<Put.capacity() << endl;
	cout << " Size = " << Put.size() << endl;

	cout << " \nPop Back" << endl;
	Put.pop_back();
	cout << " \nCapatcity = " << Put.capacity() << endl;
	cout << " Size = " << Put.size() << endl;

	cout << " \nback =  " << Put.back() << endl;
	cout << " front =  " << Put.front() << endl;

	cout << " Get Item 2  " << Put.get(2) << endl;
	Put.set(9, 2);
	cout << " \nSet Item 2 to 9  - " << Put.get(2) << endl;
	cout << " Get Item 2  - " << Put.get(2) << endl;

	cout << " \nZap" << endl;
	Put.zap();
//	cout << " \nEmpty =  " << Put.empty() << endl;

	cout << " \nCapatcity =  " << Put.capacity() << endl;
	cout << " Size =  " << Put.size() << endl;

	cout << " \nback =  " << Put.back() << endl;
	cout << " \nfront =  " << Put.front() << endl;

}