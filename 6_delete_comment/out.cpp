

#include <iostream>
#include <fstream>
#include <string>
#include <vector> 


void deal(std::vector<char> x){
    enum{
        program_text,
        manystring_comment,
        solostring_comment,
         
        string_literal,
        char_literal


    } condition = program_text;

    
    int count = 0;
    auto c = x.begin();
    char prev_c = ' ';
    for(auto c = x.begin(); c != x.end(); ++c){
        switch(condition){

        // starting always from original_text    

        case program_text:

            if(*c == '/'){
                prev_c = *c;
                c = std::next(c);
                // next if - for manystring comment
                if(*c == '*'){
                    condition = manystring_comment;
                    prev_c = ' ';
                    
                }
                // next if - for solostring comment
                else if(*c == '/'){
                    condition = solostring_comment;

                }
                // here - for no comment
                else{
                  
                    std::cout << prev_c << *c;
                }
            } else if(*c == '"'){
                condition = string_literal;
               
                std::cout << *c;

            } else if(*c == '\''){
                condition = char_literal;
            
                std::cout << *c;
            } else{
             
                std::cout << *c;
            }

            break;

        case manystring_comment:
            if(prev_c == '*' && *c == '/') {
                condition = program_text;
                std::cout << ' ';
                
            }    
            else prev_c = *c;
            break;   

        case solostring_comment:
            if(*c == '\n'){
                condition = program_text;
                
                std::cout << *c;
            }

            break; 


        case string_literal:
            // ????check for c equal backslash????
            if(*c == '"'){
                condition = program_text;
            }
          
            std::cout << *c;
            break;    

        case char_literal:
            // check for c equal apostrophe
            if(*c == '\''){
                condition = program_text;
            }
           
            std::cout << *c;
            break;       
        }
                
    }
}


int main(){
 
    std::vector<char> all;
    std::string line;
    while(std::getline(std::cin,line))
    {
        
        if (line.empty())
        break;
        for(auto x : line){
            all.push_back(x);
        }
        all.push_back('\n');
        
    }

    
         
    deal(all);


    

    
    
}