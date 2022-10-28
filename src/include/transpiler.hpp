#include <iostream>
#include <map>
#include <vector>
#include <string>
#include "../../idklang/idklang.hpp"
#include "./lexer.hpp"


class Transpiler {        
  public:   
    std::string transpile(std::vector<std::map<std::string,std::string>>  text);   
};

std::string getKey(std::vector<std::map<std::string,std::string>> vec,int i,bool real=false){
  if(real){
      if(i<0){
        return "";
      }
      if(i>=vec.size()){
        return "";
      }
    }
    i=i<0 ? 0 : i;
    i= i>= vec.size() ? vec.size()-1 : i;

    return (vec[i]).begin()->first;
}

std::string get(std::vector<std::map<std::string,std::string>> vec,int i,bool real=false){
    if(real){
      if(i<0){
        return "";
      }
      if(i>=vec.size()){
        return "";
      }
    }
    i=i<0 ? 0 : i;
    i= i>= vec.size() ? vec.size()-1 : i;

    return (vec[i]).begin()->second;
}



std::string Transpiler::transpile(std::vector<std::map<std::string,std::string>> vec) {
    std::string output="#include <iostream>\n#include <string>\n";

    bool inString;
    int printStage=0;
    bool lineNew=false,import=false,def=false;
    std::string str="";
    std::vector<std::string> imports;


    int skip=0;
    
    std::map<std::string,std::string> defined;
    defined["ARGC"]="argc";
    defined["ARGV"]="argv";
    for(int i=0;i<vec.size();i++){
      
        std::string syn=get(vec,i);
        std::string before=get(vec,i - 1);
        std::string next=get(vec,i+1);
        std::string realnext=get(vec,i+1,true);
        std::string realbefore=get(vec,i - 1,true);
        bool sign=getKey(vec,i)=="SSIGN";

        if (skip>0){
          skip--;
          continue;
        }
      

        if(syn=="\""){
          inString=!inString;
          if(import&&!inString){
            output+="\"";

            if(def){
              output+="idklang/";
            }
            BetterString asda=BetterString(str);
            
            output+=asda.remove(0)+"\"";
            
            str="";
            
            
            def=false;
            import=false;
            
          }
          else if(!inString){
            output+="BetterString("+str+"\")";
  
            str="";
          } else {
            str+="\"";
          }
          
          continue;
        }

        if(inString){
          BetterString x=BetterString(syn);
          if(syn=="\\n"){
            str+="\\n";
            continue;
          }
          if(syn=="SPACE"&&sign){
            str+=" ";
            continue;
          }
          
     
          str+=syn;
          continue;
        }

        if(syn=="//"){
          
        }

        if(syn=="const"){
            output+="const auto";
        }
        else if(syn=="var"||syn=="func"){
            output+="auto";
        }
        else if(syn=="SPACE"&&sign){
            output+=" ";
        } else if(syn=="LINE"){
            output+="\n";
        } else if(syn=="start"){
            output+="int main(int "+defined["ARGC"]+", char **"+defined["ARGV"]+")";
        } else if(syn=="or"){
            output+="||";
        } else if(syn=="and"){
            output+="&&";
        } else if(syn==";"){
            inString=false;
            lineNew=false;
        
            printStage=0;

            output+=";\n";
            

            
        } else if(syn=="{"){
            output+="{\n";
        } else if(syn=="}"){
            output+="}\n";
        } else if(syn=="&>>"){
            output+=">>";
        } else if(syn=="&<<"){
            output+="<<";
        }  else if(syn=="import"){
            output+="#include";


         
            import = true;
        
        } else if(syn=="("){
            
            if(printStage==1){
              output+="<<";
              printStage=2;
            } else {
              output+="(";
            }
        } else if(syn==")"){
            if(printStage==2&&next==";"){
              output+=lineNew ? "<<std::endl" : "<<std::flush";
              printStage=0;
              lineNew=false;
            } else {
              output+=")";
            }
        } else if(syn==">"){
            output+=">";

        } else if(syn=="def"&&import){
          def=true;
          
        } else if(syn=="#"){
          if(next=="idefine"){
              std::string realKey="";
              std::string value="";
              int x=0;
              skip++;
              while(x<1024){
                std::string y=get(vec,i+2+x);
                std::cout << y << std::endl;
                if(identifierStr(y)&&y!="SPACE"){
                  if(realKey.length()>0){
                    value=y;
                    defined[realKey]=value;
                    skip++;
                    
                    break;
                  } else {
                    realKey=y;
                  }

                }
                skip++;
                x++;

              }


          }
          
        } else {
          output+=syn;
        }


   
    }
    return output;
}