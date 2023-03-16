#include "OopPlayGround.h"
#include <iostream>
#include <SDL2/SDL.h>
using namespace std;

void classUsage() 
{
	MyClass myObj;

	myObj.id = 1;
	cout << myObj.id << "\n";
}