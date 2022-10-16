#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <vector>

class Lexer {        
  public:   
    std::string toToken(std::string text);   
    std::vector<std::map<std::string,std::string>> toTokenVec(std::string text);   
};

const std::string VARIABLE="var"; 
const std::string CONST_VAR="const"; 
const std::string FUNCTION="func"; 
const std::string FOR_LOOP="for"; 
const std::string WHILE_LOOP="while"; 
const std::string RETURN="ret"; 
const std::string IMPORT="#include";
const std::string AND="and"; 
const std::string OR="or"; 
const std::string XOR="xor"; 
const std::string START="start"; 
const std::string EQUAL="="; 
const std::string SMALLER="<"; 
const std::string BIGGER=">"; 
const std::string EXC="!"; 
const std::string QMARK="?"; 
const std::string LS="&<<";
const std::string RS="&>>";
const std::string LINE="\n"; 
const std::string END_LINE=";"; 
const std::string COMMA=",";
const std::string ICOMMA="\'";
const std::string I2COMMA="\"";
const std::string DOT=".";
const std::string LPAREN="(";
const std::string RPAREN=")";
const std::string LCURLY="{";
const std::string RCURLY="}";
const std::string LSQ="[";
const std::string RSQ="]";
const std::string PLUS="+";
const std::string MINUS="-";
const std::string MULT="*";
const std::string DIVIDE="/";
const std::string COMMENT="//";



bool space(char c){
    switch (c) {
    case ' ':
    case '\t':
    case '\r':
    case '\n':
      return true;
    default:
      return false;
  }
}

bool spaceStr(std::string a){
    for(int i=0;i<a.length();i++){
        char c=a[i];

  
        if(!space(c)){
            return false;
        }
    }

    return true;
}

bool identifier(char c) noexcept {
  switch (c) {
    case 'a':
    case 'b':
    case 'c':
    case 'd':
    case 'e':
    case 'f':
    case 'g':
    case 'h':
    case 'i':
    case 'j':
    case 'k':
    case 'l':
    case 'm':
    case 'n':
    case 'o':
    case 'p':
    case 'q':
    case 'r':
    case 's':
    case 't':
    case 'u':
    case 'v':
    case 'w':
    case 'x':
    case 'y':
    case 'z':
    case 'A':
    case 'B':
    case 'C':
    case 'D':
    case 'E':
    case 'F':
    case 'G':
    case 'H':
    case 'I':
    case 'J':
    case 'K':
    case 'L':
    case 'M':
    case 'N':
    case 'O':
    case 'P':
    case 'Q':
    case 'R':
    case 'S':
    case 'T':
    case 'U':
    case 'V':
    case 'W':
    case 'X':
    case 'Y':
    case 'Z':
    case '_':
      return true;
    default:
      return false;
  }
}


bool identifierStr(std::string a){

    for(int i=0;i<a.length();i++){
        char c=a[i];

        
        if(!identifier(c)||space(c)){
            return false;
        }
    }
    return true;
}


bool digit(char c){
    return c=='0'||c=='1'||c=='2'||c=='3'||c=='4'||c=='5'||c=='6'||c=='7'||c=='8'||c=='9';
}

bool number(std::string a){
    if(spaceStr(a)) 
        return false;
    for(int i=0;i<a.length();i++){
        char c=a[i];

        if(c==DOT.c_str()[0]){
            continue;
        }

        if(!digit(c)){
            return false;
        }
    }

    return true;
}

std::map<std::string,std::string> add(std::string a,std::string b){
    std::map<std::string,std::string> x;
    x[a]=b;
    return x;
}

std::vector<std::map<std::string,std::string>> Lexer::toTokenVec(std::string text) {
    std::string token;
    std::vector<std::map<std::string,std::string>> output;  

    for(int i=0;i<text.length();i++){
        char c=text[i];
        char nextChar;

        if(i+1<text.length()){
            nextChar=text[i+1];
        }
        if(number(token)&&!number(token+c)){
            output.push_back(add("NUMBER",token));
            token="";
            
        } 
        
        
        
        if(space(c)){
            if(c=='\n'){
                
                output.push_back(add("SSIGN","LINE"));

                continue;
            }
            output.push_back(add("SSIGN","SPACE"));
            continue;
        }

        token+=c;
        if(token=="\\n"){
            
            output.push_back(add("SSIGN","\\n"));
            token="";
            continue;
        }
        else if(token==VARIABLE){
            output.push_back(add("SSIGN","var"));
            token="";
        } else if(token==CONST_VAR){
            output.push_back(add("SSIGN","const"));
            token="";
        } else if(token==FUNCTION){
            output.push_back(add("SSIGN","func"));
            token="";
        } else if(token==FOR_LOOP){
            output.push_back(add("SIGN","for"));
            token="";
        } else if(token==WHILE_LOOP){
            output.push_back(add("SSIGN","while"));
            token="";
        } else if(token==AND){
            output.push_back(add("SSIGN","and"));
            token=""; 
        } else if(token==OR){
            output.push_back(add("SSIGN","or"));
            token="";
        } else if(token==XOR){
            output.push_back(add("SSIGN","xor"));
            token="";
        } else if(token==RETURN){
            output.push_back(add("SSIGN","return"));
            token="";
        }else if(token==START){
            output.push_back(add("SSIGN","start"));
            token="";
        }else if(token==IMPORT){
            output.push_back(add("SSIGN","import"));
            token="";
        } else if(token==COMMENT){
            output.push_back(add("SIGN","//"));
            token="";
        }else if(!spaceStr(token)&&identifierStr(token)&&!identifierStr(token+nextChar)||space(nextChar)){
            output.push_back(add("ID",token));
      
            
            token="";
        } else if(token==EQUAL){
            output.push_back(add("SIGN","="));
 
            token="";
        } else if(token==PLUS){
            output.push_back(add("SIGN","+"));
 
            token="";
        } else if(token==MINUS){
            output.push_back(add("SIGN","-"));
 
            token="";
        } else if(token==QMARK){
            output.push_back(add("SIGN","?"));
 
            token="";
        } else if(token==EXC){
            output.push_back(add("SIGN","!"));
 
            token="";
        } else if(token==SMALLER){
            output.push_back(add("SIGN","<"));
       
            token="";
        } else if(token==BIGGER){
            output.push_back(add("SIGN",">"));
         
            token="";
        } else if(token==LS){
            output.push_back(add("SIGN",LS));
       
            token="";
        } else if(token==RS){
            output.push_back(add("SIGN",RS));
       
            token="";
        } else if(token==END_LINE){
            output.push_back(add("SIGN",";"));

            token="";
        } else if(token==LPAREN){
            output.push_back(add("SIGN","("));
    
            token="";
        } else if(token==RPAREN){
            output.push_back(add("SIGN",")"));
     
            token="";
        } else if(token==LCURLY){
            output.push_back(add("SIGN","{"));
       
            token="";
        } else if(token==RCURLY){
            output.push_back(add("SIGN","}"));

            token="";
        } else if(token==LSQ){
            output.push_back(add("SIGN","["));
   
            token="";
        } else if(token==RSQ){
            output.push_back(add("SIGN","]"));

            token="";
        } else if(token==MULT){
            output.push_back(add("SIGN","*"));
        
            token="";
        } else if(token==COMMA){
            output.push_back(add("SIGN",","));
        
            token="";
        } else if(token==DOT){
            output.push_back(add("SIGN","."));
        
            token="";
        }else if(token==ICOMMA){
            output.push_back(add("SIGN","\'"));
        
            token="";
        } else if(token==I2COMMA){
            output.push_back(add("SIGN","\""));

            token="";
        } else if(token==DIVIDE&&nextChar!=DIVIDE.at(0)){
            output.push_back(add("SIGN","/"));
            token="";
        } 



        

        

        
    }

    return output;
}


std::string Lexer::toToken(std::string text) {
   
    std::string output;  
    for(std::map<std::string,std::string> m : toTokenVec(text)){
        for ( const auto &p : m )
        {
            output+=p.first+" |"+p.second+"|\n";
        
        } 
    }

    return output;
}
