#pragma once
#include <windows.h>
#include <cmath>

#pragma comment(lib, "winmm.lib")

//typedef NTSTATUS(NTAPI* RtlAP)(ULONG, BOOLEAN, BOOLEAN, PBOOLEAN);
//typedef NTSTATUS(NTAPI* NtRHE)(NTSTATUS, ULONG, ULONG, PULONG_PTR, ULONG, PULONG);

static HWAVEOUT wave = 0;

void startPayloads();
