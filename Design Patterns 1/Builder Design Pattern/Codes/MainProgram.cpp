/****************************************************************
 FILE DESCRIPTION
-----------------------------------------------------------------
*        File     :  MainProgram.cpp
*        Brief    :  Main program to demonstrate the Builder pattern
*                    
*        Details  :  This file contains the main function to demonstrate
*                    the use of the Builder pattern in building cars.
*                    It creates a PWM car using the PWM builder, then
*                    constructs the car using the CarManufacturer. Finally,
*                    it displays the details of the constructed car.
*
*****************************************************************
* INCLUDES
****************************************************************/
#include <iostream>
#include "CarProduct.hpp"

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
    PWM PWMCar; // Create a PWM car object
    CarManufacturer SetCar; // Create a CarManufacturer object
    Product Car = PWMCar.GetCar(); // Get the initial product from the PWM car
    Car = SetCar.setCar(&PWMCar); // Build the car using the CarManufacturer
    Car.showCar(); // Display the details of the constructed car
    /*End of function*/ 
    return 0;
}
/****************************************************************
*  END OF  FILE: MainProgram.cpp
****************************************************************/
