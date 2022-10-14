#include <iostream>
#include <map>
#include <vector>
#include <string>
#include "../idklang/idklang.hpp"

class Transpiler {        
  public:   
    std::string transpile(std::vector<std::map<std::string,std::string>>  text);   
};

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


    for(int i=0;i<vec.size();i++){
      
        std::string syn=get(vec,i);
        std::string before=get(vec,i - 1);
        std::string next=get(vec,i+1);
        std::string realnext=get(vec,i+1,true);
        std::string realbefore=get(vec,i - 1,true);
      

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
          if(syn=="SPACE"){
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
        else if(syn=="SPACE"){
            output+=" ";
        } else if(syn=="LINE"){
            output+="\n";
        } else if(syn=="start"){
            output+="int main()";
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
          
        }else {
          output+=syn;
        }


   
    }
    return output;
}