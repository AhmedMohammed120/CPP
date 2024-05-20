/****************************************************************
 FILE DESCRIPTION
----------------------------------------------------------------
*        File     :  Printer.hpp
*        Brief    :  Defines interfaces and classes related to printing documents.
*        Details  :  This file declares the Printer interface, LegacyPrinter class, and LegacyPrinterAdapter class.
*                     It also includes a client interface function for printing documents.
*
****************************************************************/
#ifndef PRINTER_HPP
#define PRINTER_HPP

/****************************************************************
* INCLUDES
****************************************************************/
#include <iostream>

/****************************************************************
*    GLOBAL DATA TYPE AND INSTRUCTIONS Union, Enum & Struct
****************************************************************/

// Target Interface for printers
class Printer
{   
public:
    virtual ~Printer(){} // Virtual destructor
    /*
      Brief    : Prints a document.
	  Details  : This pure virtual function must be implemented by derived classes.
                 It takes a document string as a parameter and defines the interface for printing documents.
	  param[in]: Document - Document string to be printed.
    */
    virtual void printDocument(std::string Document) = 0;
};

// Legacy Printer class
class LegacyPrinter
{
public:
    /*
      Brief    : Prints a document using a legacy printer.
	  Details  : This function simulates printing a document using a legacy printer.
                 It takes a document string as a parameter and prints it to the console.
	  param[in]: Document - Document string to be printed.
    */
    void Print(std::string Document);
};

// Legacy Printer Adapter class
class LegacyPrinterAdapter: public Printer
{
    LegacyPrinter PrinterObj; // Legacy printer object
public:
    /*
      Brief    : Prints a document using a legacy printer adapter.
	  Details  : This function adapts the printing functionality of a LegacyPrinter object to be compatible with the Printer interface.
                 It takes a document string as a parameter and invokes the Print method of the LegacyPrinter object.
	  param[in]: Document - Document string to be printed.
    */
    void printDocument(std::string Document);
};

/*
      Brief    : Client interface function for printing documents.
	  Details  : This function serves as an interface for printing documents using a Printer object.
                 It takes a Printer object and a document string as parameters and invokes the printDocument method of the Printer object.
	  param[in]: Obj - Printer object.
                 Document - Document string to be printed.
*/
void ClientInterface(Printer& Obj, std::string Document);

/****************************************************************
*    GLOBAL CONSTANT MACROS
****************************************************************/

 
/****************************************************************
*    GLOBAL DATA PROTOTYPES
****************************************************************/

#endif // End of PRINTER_HPP

/****************************************************************
*  END OF  FILE: Printer.hpp
****************************************************************/
