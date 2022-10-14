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

using namespace std;


void error(string n,string error="fatal error"){
    cout << "\033[31m" << error << ": " << "\033[0m" << n << endl;

    
    exit(1);
}

int main(int argc,char** args){
    #ifdef _WIN32
        SetConsoleMode(GetStdHandle(STD_OUTPUT_HANDLE), ENABLE_VIRTUAL_TERMINAL_PROCESSING);
    #endif
    if(argc<=1){
        error("no file passed");
    }

    string t,a;

    ifstream f(args[1]);

    if(!f.is_open()){
        error("could not open file");
    }

    while (getline (f, t)) {
        a+=t+"\n";
    }

    f.close();

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