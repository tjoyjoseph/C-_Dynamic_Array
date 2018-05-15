//#include <stdio.h>
//#include <string>
//#include <iostream>

#include "DynArray.h"

using namespace std;


int main(int argc, char* argv[])
{
	char choice;
	cout << "Would you like to see an example of the PRO FUNCTIONALITY? -";
	cin >> choice;
	if (choice = 'y'){
		///////////////////////////////////////////////////
		////////////[PRO FUNCTIONALITY]////////////////////
		///////////////////////////////////////////////////

		cout << "\n//////////CREATE ARRAY PUT////////" << endl;
		DynArray<int>Put;
		cout << "Capacity - " << Put.capacity();
		cout << "\nSize - " << Put.size();

		cout << "\n\n//////////PUSH BACK 10////////" << endl;
		for (int i = 0; i <= 10; i++){
			Put.push_back(i);
			cout << Put.back() << " ";
		}
		cout << "\n";
		Put.showAll();
		cout << "\nCapacity - " << Put.capacity();
		cout << "\nSize - " << Put.size();
		cout << "\nFront - " << Put.front();
		cout << "\nBack - " << Put.back();
		cout << "\nEmpty? " << (Put.empty() ? "Yes" : "No") << endl;

		cout << "\n\n//////////POP BACK ONE////////" << endl;
		Put.pop_back();
		Put.showAll();
		cout << "\nCapacity - " << Put.capacity();
		cout << "\nSize - " << Put.size();
		cout << "\nFront - " << Put.front();
		cout << "\nBack - " << Put.back();
		cout << "\nEmpty? " << (Put.empty() ? "Yes" : "No") << endl;

		cout << "\n\n//////////POP BACK ONE////////" << endl;
		Put.pop_back();
		Put.showAll();
		cout << "\nCapacity - " << Put.capacity();
		cout << "\nSize - " << Put.size();
		cout << "\nFront - " << Put.front();
		cout << "\nBack - " << Put.back();
		cout << "\nEmpty? " << (Put.empty() ? "Yes" : "No") << endl;

		cout << "\n\n//////////GET INDEX 5////////" << endl;
		cout << Put.get(5);

		cout << "\n\n//////////SET////////" << endl;
		cout << "Set Index 5 to 97" << endl;
		Put.set(97, 5);
		Put.showAll();

		cout << "\n\n//////////GET INDEX 5////////" << endl;
		
		cout << Put.get(5);
	
		cout << "\n\n//////////ZAP////////" << endl;
		Put.zap();
		Put.showAll();
		cout << "\nCapacity - " << Put.capacity();
		cout << "\nSize - " << Put.size();
		cout << "\nFront - " << Put.front();
		cout << "\nBack - " << Put.back();
		cout << "\nEmpty? " << (Put.empty() ? "Yes" : "No") << endl;



		cout << "Would you like to see an example of the PREMIUM FUNCTIONALITY? -";
		cin >> choice;
		if (choice = 'y'){
			///////////////////////////////////////////////////////
			//////////////[PREMIUM FUNCTIONALITY]//////////////////
			///////////////////////////////////////////////////////

			cout << "\n//////////CREATE ARRAY HOME////////" << endl;
			DynArray<int>home;
			cout << "\n\n//////////PUSH BACK 10////////" << endl;
			for (int i = 0; i <= 10; i++){
				home.push_back(i);
				cout << home.back() << " ";
			}
			cout << "\n";
			home.showAll();
			cout << "\nCapacity - " << home.capacity();
			cout << "\nSize - " << home.size();

			cout << "\n\n//////////remove ITEM NUMBER 7////////" << endl;
			home.remove(7);
			home.showAll();
			cout << "Capacity - " << home.capacity();
			cout << "\nSize - " << home.size();

			cout << "\n\n//////////insert ITEM 78 into index 3////////" << endl;
			home.insert(78, 3);
			home.showAll();
			cout << "Capacity - " << home.capacity();
			cout << "\nSize - " << home.size();


			cout << "\n//////////CREATE ARRAY HOPE(HOME)////////" << endl;
			DynArray<int>hope(home);
			cout << "\n";
			hope.showAll();
			cout << "\nCapacity - " << hope.capacity();
			cout << "\nSize - " << hope.size();

			cout << "\n//////////shrink////////" << endl;
			hope.pop_back();
			hope.pop_back();
			hope.shrink();
			hope.showAll();
			cout << "\nCapacity - " << hope.capacity();
			cout << "\nSize - " << hope.size();

			cout << "\n//////////CREATE ARRAY////////" << endl;
			DynArray<int>hope2;
			cout << "\n//////////OPERATOR = HOPE////////" << endl;
			hope2 = hope;
			cout << "\n";
			hope2.showAll();
			cout << "\nCapacity - " << hope2.capacity();
			cout << "\nSize - " << hope2.size();

			cout << "\n////////////////OPERATOR == HOPE/////////////////" << endl;
			cout << "/////No shrink////" << endl;
			cout << (hope2 == hope ? "Same" : "Different") << endl;
			hope2.push_back(5);
			cout << "/////With PUSH_BACK 5////" << endl;
			cout << (hope2 == hope ? "Same" : "Different") << endl;

			cout << "Would you like to see an example of the ULTIMATE FUNCTIONALITY? -";
			cin >> choice;
			if (choice = 'y'){
				/////////////////////////////////////////////////////////////////
				//////////////////[ULTIMATE FUNCTIONALITIES]/////////////////////
				/////////////////////////////////////////////////////////////////

				cout << "\n\n\n//////////CREATE ARRAY ULTIMATE////////" << endl;
				DynArray<int>ultimate;
				cout << "\n//////////PUSH BACK 10////////" << endl;
				for (int i = 0; i <= 10; i++){
					ultimate.push_back(i);
					cout << ultimate.back() << " ";
				}
				cout << "\n";
				ultimate.showAll();

				cout << "\n//////////insert FRONT 57////////" << endl;
				ultimate.insertFront(57);
				ultimate.showAll();

				cout << "\n//////////remove FRONT////////" << endl;
				ultimate.removeFront();
				ultimate.showAll();

				cout << "\n\n\n//////////CREATE ARRAY ULTIMATE2////////" << endl;
				DynArray<int>ultimate2;
				cout << "\n//////////PUSH BACK 3////////" << endl;
				for (int i = 0; i <= 3; i++){
					ultimate2.push_back(i + 10);
				}
				cout << "\n";
				ultimate2.showAll();
				cout << "\nCapacity - " << ultimate2.capacity();
				cout << "\nSize - " << ultimate2.size();

				cout << "\n//////////operator+= ULTIMATE////////" << endl;
				ultimate2 += ultimate;
				ultimate2.showAll();
				cout << "\nCapacity - " << ultimate2.capacity();
				cout << "\nSize - " << ultimate2.size();

				cout << "\n\n//////////operator[9]////////" << endl;
				cout << ultimate2[9] << endl;
				ultimate2.showAll();

				cout << "\n\n//////////operator[9] = 44////////" << endl;
				ultimate2[9] = 44;
				ultimate2.showAll();

				cout << "\n" << endl;
			}
		}
	}

}


