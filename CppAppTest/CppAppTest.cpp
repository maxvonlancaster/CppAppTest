// CppAppTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "OopPlayGround.h"
using namespace std;

void variables()
{
    //var i = 1; - undefined
    int i = 1;
    double d = 19.99;
    ++i; // increment
    char c = 'c';
    string s = "sss";
    bool b = true;
    cout << i;
    cout << c;
    cout << s;
}


void userInput() 
{
    int x;
    cout << "\nType a number: \n";
    cin >> x; // get input from keyboard
    cout << "Your number is " << x;
}


void conditionsLoops() 
{
    int x;
    cout << "\nType a number: \n";
    cin >> x; // get input from keyboard
    if (x < 10) 
    {
        cout << "\nLess then 10 \n";
    }
    else if (x == 10) 
    {
        cout << "\nIs equal to 10 \n";
    }
    else 
    {
        cout << "\nLarge then 10 \n";
    }

    switch (x) 
    {
        case 1:
            cout << "Is One";
            break;
        case 2:
            cout << "Is Two";
            break;
        default:
            cout << "\nIs not One or Two \n";
    }

    int i = 1;
    while (i < 10) 
    {
        ++i;
    }

    do 
    {
        cout << i;
        --i;
    } while (i > 5);

    for (int i = 0; i <= 20; i = i + 2) 
    {
        if (i == 4)
        {
            continue;
        }
        cout << i << "\n";
        if (i == 18) 
        {
            break;
        }
    }
}


void arrays() 
{
    string colors[3] = {"red", "blue", "green"};
    colors[2] = "yellow";

    // foreach loop:
    for (string s : colors) 
    {
        cout << s << "\n";
    }
    cout << sizeof(colors);
    int matrix[2][2] = { {0, 1}, {2, 2} }; // multidimensional
}


void structures() 
{
    struct
    {
        int myInt;
        string name;
    } myStruct = {1, "a"};

    myStruct.myInt = 1;
    myStruct.name = "Name";
}


void references() 
{
    // A reference variable is a "reference" to an existing variable, and it is created with the 
    // & operator:
    string food = "Pizza";
    string &meal = food;

    cout << food << "\n";  // Outputs Pizza
    cout << meal << "\n";  // Outputs Pizza

    //  But it can also be used to get the memory address of a variable; which is the location 
    // of where the variable is stored on the computer.
    cout << &food; // Outputs 0x6dfed4
}


void pointers() 
{
    // A pointer is a variable that stores the memory address as its value.
    string food = "Pizza";  // A food variable of type string
    string* ptr = &food;    // A pointer variable, with the name ptr, that stores the address of food

    // Output the value of food (Pizza)
    cout << food << "\n";

    // Output the memory address of food (0x6dfed4)
    cout << &food << "\n";

    // Output the memory address of food with the pointer (0x6dfed4)
    cout << ptr << "\n";

    // Dereference: Output the value of food with the pointer (Pizza)
    cout << *ptr << "\n";

    // You can also change the pointer's value. But note that this will also change the value of the 
    // original variable:
    *ptr = "Hamburger";
    cout << *ptr << "\n"; // Output the new value of the pointer (Hamburger)
    cout << food << "\n"; // Output the new value of the food variable (Hamburger)
}


int main()
{
    std::cout << "Hello World!\n";
    //variables();
    //userInput();
    //conditionsLoops();
    //structures();
    //references();
    //pointers();
    classUsage();
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add 
//      existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
