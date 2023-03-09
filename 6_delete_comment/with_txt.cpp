#include <iostream>
#include <fstream>

// Problem can be solve by state machine (конечный автомат)

int main(){
    std::ifstream in("in.txt");
    std::ofstream out("out.txt");
     
    // this data structure for storage 
    // current condition our state machine

    enum{
        program_text,
        manystring_comment,
        solostring_comment,
        /*
        Строковый литерал — это 
        последовательность символов 
        из исходной кодировки, 
        заключенной в двойные кавычки (" ")
        */
        string_literal,
        char_literal


    } condition = program_text;

    char c = ' ';
    char prev_c = ' ';
    while(std::cin.get(c)){
        switch(condition){

        // starting always from original_text    

        case program_text:

            if(c == '/'){
                prev_c = c;
                c = std::cin.get();
                // next if - for manystring comment
                if(c == '*'){
                    condition = manystring_comment;
                    prev_c = ' ';
                    
                }
                // next if - for solostring comment
                else if(c == '/'){
                    condition = solostring_comment;

                }
                // here - for no comment
                else{
                    out.put(prev_c);
                    out.put(c);
                    std::cout << prev_c << c;
                }
            } else if(c == '"'){
                condition = string_literal;
                out.put(c);
                std::cout << c;

            } else if(c == '\''){
                condition = char_literal;
                out.put(c);
                std::cout << c;
            } else{
                out.put(c);
                std::cout << c;
            }

            break;

        case manystring_comment:
            if(prev_c == '*' && c == '/') {
                condition = program_text;
                std::cout << ' ';
                out.put(' ');
            }    
            else prev_c = c;
            break;   

        case solostring_comment:
            if(c == '\n'){
                condition = program_text;
                out.put(c);
                std::cout << c;
            }

            break; 


        case string_literal:
            // ????check for c equal backslash????
            if(c == '"'){
                condition = program_text;
            }
            out.put(c);
            std::cout << c;
            break;    

        case char_literal:
            // check for c equal apostrophe
            if(c == '\''){
                condition = program_text;
            }
            out.put(c);
            std::cout << c;
            break;       
        }
                
    }
}