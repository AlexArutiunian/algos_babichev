#include <iostream>
#include <fstream>
#include <string>
#include <vector> 



int main(){

    enum{
        program_text,
        manystring_comment,
        solostring_comment,
         
        string_literal,
        char_literal


    } condition = program_text;

    char c = ' ';
    char prev_c = ' ';

    std::vector<std::string> all;
    std::string line;
    while(std::getline(std::cin,line))
    {
        
        if (line.empty())
            break;
        line += '\n';
        all.push_back(line);
    }
  

    for(auto x : all){
        
        c = x[0];
        int count = 0;
        c = x[count];
        while(x[count] != '\n'){
        count += 1;
        switch(condition){

        case program_text:

            if(c == '/'){
                prev_c = c;
                
                c = x[count];
                

                
               
                
                if(c == '*'){
                    condition = manystring_comment;
                    prev_c = ' ';
                    
                }
                
                else if(c == '/'){
                    condition = solostring_comment;

                }
                
                else{
                     
                     
                    std::cout << prev_c << c;
                }
            } else if(c == '"'){
                condition = string_literal;
                 
                std::cout << c;

            } else if(c == '\''){
                condition = char_literal;
                 
                std::cout << c;
            } else{
                 
                std::cout << c;
            }

            break;

        case manystring_comment:
            if(prev_c == '*' && c == '/') {
                condition = program_text;
                std::cout << ' ';
                
            }    
            else prev_c = c;
            break;   

        case solostring_comment:
            if(c == '\n'){
                condition = program_text;
                 
                std::cout << c;
            }

            break; 


        case string_literal:
            
            if(c == '"'){
                condition = program_text;
            }
             
            std::cout << c;
            break;    

        case char_literal:
            
            if(c == '\''){
                condition = program_text;
            }
             
            std::cout << c;
            break;       
        }
                
    }

    }

    
    
}