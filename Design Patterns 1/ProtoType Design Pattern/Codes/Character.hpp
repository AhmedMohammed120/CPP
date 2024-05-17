/****************************************************************
 FILE DESCRIPTION
----------------------------------------------------------------
*        File     :  Character.hpp
*        Brief    :  -
*        Details  :  - 
*
****************************************************************/
#ifndef CHARACTER_HPP
#define CHARACTER_HPP
/****************************************************************
* INCLUDES
****************************************************************/
#include <iostream>
#include <memory>
/****************************************************************
*    GLOBAL DATA TYPE AND INSTRUCTIONS Union, Enum & Struct
****************************************************************/
/*
      Brief  : Bootloader send message. 
	  Details  : send message by USART.
	  param[in]: Pointer to char.
	  param[in]: Pin Led pin.  
*/
class Character
{
    public:
    virtual void Print()=0;
    virtual std::shared_ptr<Character> Clone()=0;
};

class Warrior :public Character
{
    public:
    void Print()override
    {
        std::cout<<"Warrior Class"<<std::endl;
    }

    virtual std::shared_ptr<Character> Clone()
    {
        return std::make_shared<Warrior>();
    }
};

class Mage :public Character
{
    public:
    void Print()override
    {
        std::cout<<"Mage Class"<<std::endl;
    }

    virtual std::shared_ptr<Character> Clone()
    {
        return std::make_shared<Mage>();
    }
};




/****************************************************************
*    GLOBAL CONSTANT MACROS
****************************************************************/

 
/****************************************************************
*    GLOBAL DATA PROTOTYPES
****************************************************************/



#endif
/****************************************************************
*  END OF  FILE: Character.hpp
****************************************************************/



