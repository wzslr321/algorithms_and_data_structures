#include <algorithm> // std::sort
#include <iostream>
#include <limits> // std::numeric_limits
#include <string>

int getNameCount()
{
    std::cout << "How many names would you like to enter? ";
    int length{};
    std::cin >> length;

    return length;
}

// Asks user to enter all the names
void getNames(std::string* names, int length)
{
    // Ignore the line feed that was left by std::cin.
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    for (int i{ 0 }; i < length; ++i)
    {
        std::cout << "Enter name #" << i + 1 << ": ";
        std::getline(std::cin >> std::ws, names[i]);
    }
}

// Prints the sorted names
void printNames(std::string* names, int length)
{
    std::cout << "\nHere is your sorted list:\n";

   for (int i{ 0 }; i < length; ++i)
        std::cout << "Name #" << i + 1 << ": " << names[i] << '\n';
}

int main()
{
    int length{ getNameCount() };

    // Allocate an array to hold the names
    auto* names{ new std::string[length]{} };

    getNames(names, length);

    // Sort the array
    std::sort(names, names + length);

    printNames(names, length);

    // don't forget to use array delete
    delete[] names;
    // we don't need to set names to nullptr/0 here because it's going to go out
    // of scope immediately after this anyway.

    return 0;
} 
