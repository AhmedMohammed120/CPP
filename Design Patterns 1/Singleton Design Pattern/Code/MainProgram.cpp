/****************************************************************
 FILE DESCRIPTION
-----------------------------------------------------------------
*        File     :  MainProgram.cpp
*        Brief    :  This file contains the implementation of a 
*                    simple program demonstrating the usage of 
*                    a singleton class for managing colleague names.
*                    
*        Details  :  The program defines a class `DataBase` that 
*                    manages colleague names using a singleton 
*                    design pattern. It provides a static member 
*                    function `GetInstance` to retrieve the 
*                    singleton instance. Colleague names can be 
*                    added using the `AddColleagues` method, and 
*                    the list of names can be printed using 
*                    `PrintColleagues`.
*
*****************************************************************
* INCLUDES
****************************************************************/
#include <iostream>
#include <string>
#include <vector>
#include <memory>
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
class DataBase
{
private:
    std::vector<std::string> ColleaguesNames;
    
public:
    DataBase(){}
    DataBase(DataBase& DataBase)=delete; // Delete Copy Constructor
    DataBase& operator=(DataBase DataBase)=delete; // Delete Assignment Operator

    static std::unique_ptr<DataBase> GetInstance()
    {
        static std::unique_ptr<DataBase> Instance = std::make_unique<DataBase>();
        return std::move(Instance);
    }

    void AddColleagues(std::string NameCpy)
    {
        ColleaguesNames.push_back(NameCpy);
    }

    void PrintColleagues(void)
    {
        for(std::string It: ColleaguesNames)
        {
            std::cout<<"Name: "<<It<<std::endl;
        }
    }
};

/****************************************************************
*    LOCAL FUNCTIONS
****************************************************************/

/****************************************************************
*   GLOBAL FUNCTIONS
****************************************************************/
/*
      Brief    : Main function.
	  Details  : Initializes a singleton instance of the 
	             `DataBase` class and demonstrates adding 
	             colleague names and printing them.
	  param[in]: None.
*/
int main(void)
{
    /*1. Init Variables*/
    std::unique_ptr<DataBase> DB{DataBase::GetInstance()};
    // DB and DB2 share the same instance of DataBase
    
    DB->AddColleagues("Ahmed");
    DB->AddColleagues("Mohammed");
    DB->AddColleagues("Mohanad");
    
    std::cout << "Colleagues of DB:" << std::endl;
    DB->PrintColleagues();
    
    /*End of function*/ 
    return 0;
}
/****************************************************************
*  END OF  FILE: MainProgram.cpp
****************************************************************/
