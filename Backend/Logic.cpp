#include <iostream>
#include "json.hpp"
#include <fstream>
#include <string>
using json = nlohmann::json;



int main()
{
    //Specifys the length of the charList array
    std::string stringList {};
    std::ifstream myFile;
    myFile.open("test.txt");
    if (myFile.is_open())
    {
        std::cout << "File opened succesfully" << "\n";
    }
    /*std::cout << "Enter stuff please" << "\n";*/
    /*std::getline(std::cin >> std::ws, stringList);*/
    while (std::getline(myFile, stringList))
    {
        std::cout << stringList << "\n" << "\n";
    }
    myFile.close();
    std::cout << "Operation Complete Matthew's mom has been secured" << std::endl;
    return 0;
}
