/****************************************************************
 FILE DESCRIPTION
-----------------------------------------------------------------
*        File     :  Printer.cpp
*        Brief    :  Defines functions related to printing documents, including adapters for legacy printers.
*                    
*        Details  :  This file contains implementations for printing documents using modern printers and adapters for legacy printers.
*                     The main function provided is `ClientInterface`, which acts as an interface for printing documents using a Printer object.
*                     Additionally, it includes implementations for the LegacyPrinterAdapter class and the LegacyPrinter class, which allow compatibility with legacy printing systems.
*****************************************************************/

/****************************************************************
* INCLUDES
****************************************************************/
#include <iostream>
#include "Printer.hpp"

/****************************************************************
*    LOCAL MACROS CONSTANTS\FUNCTIONS
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
      Brief    : main function.
	  Details  : This function serves as an interface for printing documents using a Printer object.
                 It takes a Printer object and a document string as parameters and invokes the printDocument method of the Printer object.
	  param[in]: Obj - Printer object.
                 Document - Document string to be printed.
*/
void ClientInterface(Printer& Obj,std::string Document)
{
    Obj.printDocument(Document);
}

/*
      Brief    : Adapter function for legacy printers.
	  Details  : This function adapts the printing functionality of a LegacyPrinter object to be compatible with the Printer interface.
                 It takes a document string as a parameter and invokes the Print method of the LegacyPrinter object.
	  param[in]: Document - Document string to be printed.
*/
void LegacyPrinterAdapter::printDocument(std::string Document)
{
    PrinterObj.Print(Document);
}

/*
      Brief    : Prints a document using a legacy printer.
	  Details  : This function simulates printing a document using a legacy printer.
                 It takes a document string as a parameter and prints it to the console.
	  param[in]: Document - Document string to be printed.
*/
void LegacyPrinter::Print(std::string Document)
{
    std::cout<<"Legacy Printer"<<std::endl;
    std::cout<<"Document: "<<Document<<std::endl;
}
/****************************************************************
*  END OF  FILE: -
****************************************************************/
