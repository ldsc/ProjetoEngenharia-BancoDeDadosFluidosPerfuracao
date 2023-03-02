#include <iostream>

    #ifdef __linux__
	#elif _WIN32
#include <windows.h>
#include <stdlib.h>///<para system
	#else
	#endif

#include "CInterface.h"

using namespace std;

///int main(int argc, char** argv)
int main()
{

	///Inicia a interface do programa
	CInterface Interface;
	Interface.inicia();
return(0);
}
