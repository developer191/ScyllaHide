#pragma once


#define MAXIMUM_INSTRUCTION_SIZE (16) //maximum instruction size == 16

int GetDetourLen(const void * lpStart, const int minSize);
void WriteJumper(unsigned char * lpbFrom, unsigned char * lpbTo);
void * DetourCreate(void * lpFuncOrig, void * lpFuncDetour, bool createTramp);
void * DetourCreateRemote(void * hProcess, void * lpFuncOrig, void * lpFuncDetour, bool createTramp);


#ifdef _WIN64
#define DetourCreateRemoteNative DetourCreateRemote
#else
void * DetourCreateRemoteNative32(void * hProcess, void * lpFuncOrig, void * lpFuncDetour, bool notUsed);
void * DetourCreateRemoteNativeSysWow64(void * hProcess, void * lpFuncOrig, void * lpFuncDetour, bool notUsed);

#define DetourCreateRemoteNative DetourCreateRemoteNative32
#endif

int LengthDisassemble(void* DisassmAddress);
