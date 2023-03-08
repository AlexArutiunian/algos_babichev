#include <iostream>
#include <fstream>
#include <string>
#include <sstream> 
#include <vector> 



int main(){

    
    
    std::vector<std::string> all;
    std::string line;
    while(std::getline(std::cin,line))
    {

        
        if (line.empty())
        break;
        line += '\n';
        all.push_back(line);
    }

    std::cout << all[0];
    std::cout << all[0];

   

    
    
    
    

    

}