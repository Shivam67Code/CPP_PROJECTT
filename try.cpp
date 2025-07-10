//ui is incomplete
#include "predictor.hpp"

///including conio ,so work only in windows OS , not on Linux and MACos
#include "conio.h"


int main(){

    std::string line;
    std::string word;

    while(true){
        

        char ch=getche();
        
        //for safe exit
        if(ch=='.'){
            break;
        }
        
        if(ch==' '){
            
            word.clear();
            continue;
        }


        //if pressed = , the previous input letter will be erased
        if(ch=='='){
            if(!word.empty()){
                word.pop_back();
            }
            
            if(!line.empty()){
                line.pop_back();
            }
            
        }
        
        if(ch!=' ' && ch!='='){
            word.push_back(ch);
        }
        
        if(ch!='=')
        line.push_back(ch);

        system("cls");
        std::cout<<"Typed: "<<word<<'\n';
        std::cout<<"predicted: "<<dict.get_closest_word(word);
        
        std::cout<<"\n\n"<<"sentence: "<<line;
        
        
    }

    return 0;
}