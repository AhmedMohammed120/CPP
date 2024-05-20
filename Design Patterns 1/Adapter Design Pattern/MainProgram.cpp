/****************************************************************
 FILE DESCRIPTION
-----------------------------------------------------------------
*        File     :  MainProgram.cpp
*        Brief    :  Entry point for the program.
*                    
*        Details  :  This file contains the main function, which serves as the entry point for the program.
*                     It initializes a LegacyPrinterAdapter object and prints a document using the ClientInterface function.
*
*****************************************************************/
#include <iostream>
#include "Printer.hpp"

/****************************************************************
*    LOCAL MACROS CONSTANTS/FUNCTIONS
****************************************************************/

/****************************************************************
*    LOCAL DATA
****************************************************************/


/****************************************************************
*    GLOBAL DATA
****************************************************************/

/****************************************************************
*    LOCAL FUNCTION PROTOTYPES
****************************************************************/

/****************************************************************
*    LOCAL FUNCTIONS
****************************************************************/

/****************************************************************
*   GLOBAL FUNCTIONS
****************************************************************/
/*
      Brief    : Main function.
	  Details  : Entry point for the program. Initializes a LegacyPrinterAdapter object and prints a document using the ClientInterface function.
	  param[in]: None.
	  return   : 0 indicating successful execution.
*/
int main(void)
{
    /*1. Init Variables*/
    LegacyPrinterAdapter Obj; // Create a LegacyPrinterAdapter object
    ClientInterface(Obj,"Success"); // Print a document using the LegacyPrinterAdapter object
    
    /*End of function*/ 
    return 0;
}
/****************************************************************
*  END OF  FILE: MainProgram.cpp
****************************************************************/
