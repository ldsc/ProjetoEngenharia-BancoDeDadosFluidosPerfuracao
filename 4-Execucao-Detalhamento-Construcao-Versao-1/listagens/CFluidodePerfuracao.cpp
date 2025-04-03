#include <iostream>
#include <stdio.h>
///<verifica sistema operacional
#ifdef __linux

#include <cstdlib>

#elif _WIN32

#include <windows.h>
#include <stdlib.h>///<para system
#include <conio.h>

#else

#endif

#include <string>
#include "CFluidodePerfuracao.h"

