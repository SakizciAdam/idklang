extern "C"
{

    #ifdef _WIN32
        #include <windows.h>
    #endif
}
#ifndef COLOR_H_  

#define COLOR_H_

bool enableWindowsColors(){
    #ifdef _WIN32
        SetConsoleMode(GetStdHandle(STD_OUTPUT_HANDLE), ENABLE_VIRTUAL_TERMINAL_PROCESSING);
        return true;
    #endif
    return false;
}



// Foreground colors
const char* blackFGColor = "\x1B[30m";
const char* redFGColor = "\x1B[31m";
const char* greenFGColor = "\x1B[32m";
const char* yellowFGColor = "\x1B[33m";
const char* blueFGColor = "\x1B[34m";
const char* magentaFGColor = "\x1B[35m";
const char* cyanFGColor = "\x1B[36m";
const char* whiteFGColor = "\x1B[37m";
const char* brightBlackFGColor = "\x1B[90m";
const char* brightRedFGColor = "\x1B[91m";
const char* brightGreenFGColor = "\x1B[92m";
const char* brightYellowFGColor = "\x1B[93m";
const char* brightBlueFGColor = "\x1B[94m";
const char* brightMagentaFGColor = "\x1B[95m";
const char* brightCyanFGColor = "\x1B[96m";
const char* brightWhiteFGColor = "\x1B[97m";
//Background colors
const char* blackBGColor = "\x1B[40m";
const char* redBGColor = "\x1B[41m";
const char* greenBGColor = "\x1B[42m";
const char* yellowBGColor = "\x1B[43m";
const char* blueBGColor = "\x1B[44m";
const char* magentaBGColor = "\x1B[45m";
const char* cyanBGColor = "\x1B[46m";
const char* whiteBGColor = "\x1B[47m";
const char* brightBlackBGColor = "\x1B[100m";
const char* brightRedBGColor = "\x1B[101m";
const char* brightGreenBGColor = "\x1B[102m";
const char* brightYellowBGColor = "\x1B[103m";
const char* brightBlueBGColor = "\x1B[104m";
const char* brightMagentaBGColor = "\x1B[105m";
const char* brightCyanBGColor = "\x1B[106m";
const char* brightWhiteBGColor = "\x1B[107m";
// Reset color
const char* resetColor = "\033[0m";



#endif 