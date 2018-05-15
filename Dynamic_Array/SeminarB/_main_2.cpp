#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>

#include <string>

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
	Type * Array;

	void reset(){
		int n;
		ArraySize = InitialArray;
		Array = new Type[ArraySize];
		/*for (n = 0; n < ArraySize; n++){
			Array[n] = "";
		}*/
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
	void push_back(Type Item/*ComponentType*/){
		if (LastIndex == ArraySize){
			Type * buffer = new Type[ArraySize + InitialArray];
			for (int i = 0; i < ArraySize; i++){
				buffer[i] = Array[i];
			}
			ArraySize += InitialArray;
			Array = new Type[ArraySize];
			/*for (int i = 0; i <ArraySize; i++){
				Array[i] = "";
			}*/
			for (int i = 0; i <LastIndex; i++){
				Array[i] = buffer[i];
			}
			delete[] buffer;
		}
		Array[LastIndex] = Item;
		LastIndex += 1;

		//for (int i = 0; i <ArraySize; i++){  ///Testing Purposes
		//cout << Array[i] << "  ";
		//}

	};
	void pop_back(){
		//Array[LastIndex-1] = "";
		//delete[LastIndex] Array;
		LastIndex -= 1;
	};
	Type /*ComponentType*/ back(){
		if (LastIndex == 0){
			return Array[LastIndex];
		}
		return Array[LastIndex - 1];
	};
	Type /*ComponentType*/ front(){
		return Array[0];
	};
	Type /*ComponentType*/ get(int index){
		return Array[index - 1];
	}
	void set(/*ComponentType*/Type newItem, int index){
		Array[index - 1] = newItem;

	};
	void zap(){
		reset();
	};
	/*DynArray(DynArray);
	DynArray(int);*/

	~DynArray(){
		int x = 4;
	};
};




int main(int argc, char* argv[])
{
	DynArray<int> Put;

	for (int i = 0; i < 15; i++){ 
		Put.push_back(3); 
		cout << Put.back()<<"  "<<endl; ///Testing Purposes 
	}

	cout << " \nback = " << Put.back() << endl;
	cout << " front = " << Put.front() << endl;

	cout << " \nCapatcity = " << Put.capacity() << endl;
	cout << " Size = " << Put.size() << endl;

	cout << " \nPop Back" << endl;
	Put.pop_back();
	cout << " \nCapatcity = " << Put.capacity() << endl;
	cout << " Size = " << Put.size() << endl;

	cout << " \nback =  " << Put.back() << endl;
	cout << " front =  " << Put.front() << endl;

	cout << " Get Item 2  " << Put.get(2) << endl;
//	Put.set('p', 2);
//	cout << " \nSet Item 2 to 9  - " << Put.get(2) << endl;
//	cout << " Get Item 2  - " << Put.get(2) << endl;

	cout << " \nZap" << endl;
	Put.zap();
	
	if (Put.empty() == true)
	{
		cout << " \nEmpty =  True" << endl;
	}
	else{
		cout << " \nEmpty =  False" << endl;
	}


	cout << " \nCapatcity =  " << Put.capacity() << endl;
	cout << " Size =  " << Put.size() << endl;

	cout << " \nback =  " << Put.back() << endl;
	cout << " \nfront =  " << Put.front() << endl;

}