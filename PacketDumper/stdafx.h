// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files
#include <WinSock2.h>
#include <windows.h>
#include <stdio.h>
#include <fstream>
#include <ctime>
#include <algorithm>
#include <string>

// Link with ws2_32.lib
#pragma comment(lib, "Ws2_32.lib")

// reference additional headers your program requires here
#pragma comment (lib, "detours.lib")
#include "detours.h"

typedef int(__stdcall* hSend)(SOCKET s, const char *buf, int len, int flagst);
typedef int(__stdcall* hRecv)(SOCKET s, char *buf, int len, int flagst);

void logPacket(const char *buf, int len, std::string context);
int WSAAPI mSend(SOCKET socket, const char *buf, int len, int flagst);
int WSAAPI mRecv(SOCKET socket, char *buf, int len, int flagst);
void WINAPI DllThread();
