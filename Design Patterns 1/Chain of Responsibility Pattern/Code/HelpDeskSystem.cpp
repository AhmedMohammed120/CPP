/****************************************************************
 FILE DESCRIPTION
-----------------------------------------------------------------
*        File     :  MainProgram.cpp
*        Brief    :  Implementation of a Help Desk system using the Chain of Responsibility pattern.
*                    
*        Details  :  This program defines a simple Help Desk system where requests are handled
*                    by either a SoftwareHandler or a HardwareHandler. If the request cannot 
*                    be handled by the current handler, it is passed to the next handler in the chain.
*

*****************************************************************
* INCLUDES
****************************************************************/
#include <iostream>
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
class HelpDesk;
std::shared_ptr<HelpDesk> SoftwareHandlerObj;
std::shared_ptr<HelpDesk> HardwareHandlerObj;

/****************************************************************
*    LOCAL FUNCTION PROTOTYPES
****************************************************************/

/****************************************************************
*    LOCAL CLASSES
****************************************************************/
// Chain of Responsibility Design Pattern
/*
    Brief    : Abstract base class for HelpDesk.
    Details  : This class declares the interface for handling requests and 
               setting the next handler in the chain.
*/
class HelpDesk
{
public:
    virtual void RequestHandler(std::string Request) = 0;
    virtual void NextHandler(std::shared_ptr<HelpDesk> Handler) = 0;
};

/*
    Brief    : Concrete handler for software-related requests.
    Details  : This class handles software-related requests and passes 
               unhandled requests to the next handler in the chain.
*/
class SoftwareHandler : public HelpDesk
{
private:
    std::shared_ptr<HelpDesk> Handler;

public:
    void RequestHandler(std::string Request) override
    {
        if (Request == "Software")
        {
            std::cout << "Handling Issue" << std::endl;
            std::cout << "Issue is Handled Successfully by Software Handler" << std::endl;
        }
        else
        {
            if (Handler != nullptr)
            {
                Handler->RequestHandler(Request);
            }
        }
    }

    void NextHandler(std::shared_ptr<HelpDesk> NextHandler) override
    {
        Handler = NextHandler;
    }
};

/*
    Brief    : Concrete handler for hardware-related requests.
    Details  : This class handles hardware-related requests and passes 
               unhandled requests to the next handler in the chain.
*/
class HardwareHandler : public HelpDesk
{
private:
    std::shared_ptr<HelpDesk> Handler;

public:
    void RequestHandler(std::string Request) override
    {
        if (Request == "Hardware")
        {
            std::cout << "Handling Issue" << std::endl;
            std::cout << "Issue is Handled Successfully by Hardware Handler" << std::endl;
        }
        else
        {
            if (Handler != nullptr)
            {
                Handler->RequestHandler(Request);
            }
        }
    }

    void NextHandler(std::shared_ptr<HelpDesk> NextHandler) override
    {
        Handler = NextHandler;
    }
};

/****************************************************************
*    LOCAL FUNCTIONS
****************************************************************/

/*
    Brief    : Initializes the handler objects and sets up the chain of responsibility.
    Details  : This function creates instances of SoftwareHandler and HardwareHandler,
               and links them such that SoftwareHandler passes unhandled requests to HardwareHandler.
*/
void InitHandlers(void)
{
    SoftwareHandlerObj = std::make_shared<SoftwareHandler>();
    HardwareHandlerObj = std::make_shared<HardwareHandler>();
    SoftwareHandlerObj->NextHandler(HardwareHandlerObj);
    HardwareHandlerObj->NextHandler(nullptr);
}

/****************************************************************
*   GLOBAL FUNCTIONS
****************************************************************/

/*
    Brief    : Main function.
    Details  : The entry point of the program. It initializes the handlers and
               makes a series of requests to demonstrate the chain of responsibility.
    param[in]: None.
*/
int main(void)
{
    /* Initialize Handlers */
    InitHandlers();

    /* Make Requests */
    SoftwareHandlerObj->RequestHandler("Software");
    SoftwareHandlerObj->RequestHandler("Hardware");

    /* End of function */ 
    return 0;
}

/****************************************************************
*  END OF  FILE: MainProgram.cpp
****************************************************************/
