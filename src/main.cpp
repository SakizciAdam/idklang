#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <iterator>
#include <vector>
#ifdef _WIN32
    #include <windows.h>
#endif

#include "./include/lexer.hpp"
#include "./include/transpiler.hpp"
#include "./include/argparser.hpp"
#include "./include/reader.h"
#include "./include/error.hpp"

using namespace std;



int main(int argc,char** args){
    #ifdef _WIN32
        SetConsoleMode(GetStdHandle(STD_OUTPUT_HANDLE), ENABLE_VIRTUAL_TERMINAL_PROCESSING);
    #endif
    if(argc<=1){
        error("no file passed");
    }


    char* a=read(args[1]);

    if(a==NULL){
         error("could not read file");
    } 

    Lexer lexer;
    Transpiler trans;
    string out=(cmdOptionExists(args, args+argc,"-o") ? getCmdOption(args, args+argc,"-o") : "a");
    
    ofstream fw(out+".cpp");
    string x=trans.transpile(lexer.toTokenVec(a));


    fw << x;

    fw.close();

    if(!cmdOptionExists(args, args+argc,"--nocompile")){
         string b="g++ "+out+".cpp "+"-o "+out+" -L ./idklang/**";

        if(cmdOptionExists(args, args+argc,"-L")){
            b+=" ";
            b+=getCmdOption(args, args+argc,"-L");
        }
        if(cmdOptionExists(args, args+argc,"-I")){
            b+=" ";
            b+=getCmdOption(args, args+argc,"-I");
        }


    
        system(b.c_str());
    }

   if(!cmdOptionExists(args, args+argc,"--keep")){
         string asdasd=out+".cpp";
    
        int result = remove(asdasd.c_str());
   }

   

    return 0;
}