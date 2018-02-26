﻿#include "framework.h"


#ifndef CUBE

#ifdef METROWIN
[MTAThread]
#endif
WINBOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{

   UNREFERENCED_PARAMETER(hInstance);

   UNREFERENCED_PARAMETER(lpReserved);

   if (dwReason == DLL_PROCESS_ATTACH)
   {
      
      ::output_debug_string("scorpionilluminati_beatmapper.dll :: initializing!\n");

   }
   else if (dwReason == DLL_PROCESS_DETACH)
   {

      ::output_debug_string("scorpionilluminati_beatmapper.dll :: terminating!\n");

   }

   return 1;   // ok

}


#endif