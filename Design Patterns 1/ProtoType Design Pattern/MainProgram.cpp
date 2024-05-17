/****************************************************************
 FILE DESCRIPTION
-----------------------------------------------------------------
*        File     :  MainProgram.cpp
*        Brief    :  Main program to demonstrate the Prototype pattern for game characters.
*                    
*        Details  :  This file contains the main function to demonstrate the use of the Prototype pattern
*                    for game characters. It creates instances of Warrior and Mage classes, clones them,
*                    and then prints the information of the cloned characters.
*
*****************************************************************
* INCLUDES
****************************************************************/
#include <iostream>
#include "Character.hpp"

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
      Brief    : main function.
	  Details  : Entry point of the program.
	  param[in]: None.
*/
int main(void)
{
    /*1. Init Variables*/
    Warrior Obj1; // Create a Warrior object
    Mage Obj2; // Create a Mage object
    std::shared_ptr<Character> Obj3 = Obj1.Clone(); // Clone the Warrior object
    std::shared_ptr<Character> Obj4 = Obj2.Clone(); // Clone the Mage object
    Obj3->Print(); // Print information of the cloned Warrior
    Obj4->Print(); // Print information of the cloned Mage
    
    /*End of function*/ 
    return 0;
}
/****************************************************************
*  END OF  FILE: MainProgram.cpp
****************************************************************/
