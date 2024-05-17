`/****************************************************************
 FILE DESCRIPTION
----------------------------------------------------------------
*        File     :  CarProduct.hpp
*        Brief    :  Defines classes and interfaces for building cars.
*        Details  :  This file contains the declarations of the Product, Builder,
*                    PWM, SedanBuilder, and CarManufacturer classes. The Product
*                    class represents the car being built, and it has methods to
*                    set its attributes (make, model, color, year) and to display
*                    its details. The Builder interface defines methods for
*                    setting the attributes of the car. The PWM and SedanBuilder
*                    classes are concrete implementations of the Builder interface
*                    for building specific types of cars. The CarManufacturer class
*                    acts as a director, coordinating the construction process
*                    using a specified builder.
*
****************************************************************/
#ifndef CAR_HPP
#define CAR_HPP

/****************************************************************
* INCLUDES
****************************************************************/
#include <iostream>
#include <string>

/****************************************************************
*    GLOBAL DATA TYPE AND INSTRUCTIONS Union, Enum & Struct
****************************************************************/
/*
      Brief  : Product class representing a car.
	  Details  : This class encapsulates the attributes of a car,
                 including its make, model, color, and year. It provides
                 methods to set these attributes and to display the car's
                 details.
	  param[in]: CarMake - The make of the car.
                 CarModel - The model of the car.
                 CarColor - The color of the car.
                 CarYear  - The year of the car.
*/
class Product
{
    private:
    std::string Make;
    std::string Model;
    std::string Color;
    int Year;

    public:
    void setMake(std::string CarMake)
    {
        Make = CarMake;
    }
    void setModel(std::string CarModel)
    {
        Model = CarModel;
    }
    void setColor(std::string CarColor)
    {
        Color = CarColor;
    }
    void setYear(int CarYear)
    {
        Year = CarYear;
    }
    void showCar()
    {
        std::cout<<"Car Make: "<<Make<<std::endl;
        std::cout<<"Car Model: "<<Model<<std::endl;
        std::cout<<"Car Color: "<<Color<<std::endl;
        std::cout<<"Car Year: "<<Year<<std::endl;
    }
};

/*
      Brief  : Builder interface for building cars.
	  Details  : This abstract class defines methods for setting
                 the make, model, color, and year of a car, as well
                 as getting the built car.
*/
class Builder
{
    public:
    virtual void SetMake()=0;
    virtual void SetModel()=0;
    virtual void SetColor()=0;
    virtual void SetYear()=0;
    virtual Product GetCar()=0;
};

/*
      Brief  : Concrete builder class for building PWM cars.
	  Details  : This class implements the Builder interface to
                 construct PWM cars. It sets the make, model, color,
                 and year of the car according to the PWM specifications.
*/
class PWM : public Builder
{
    private:
    Product PWMCar;
    public:
     void SetMake()override
     {
        PWMCar.setMake("PWM");
     }
     void SetModel()override
     {
        PWMCar.setModel("V20");
     }
     void SetColor()override
     {
        PWMCar.setColor("Black");
     }
     void SetYear()override
     {
        PWMCar.setYear(2024);
     }
     virtual Product GetCar()
     {
        return PWMCar;
     }
};

/*
      Brief  : Concrete builder class for building Sedan cars.
	  Details  : This class implements the Builder interface to
                 construct Sedan cars. It sets the make, model, color,
                 and year of the car according to Sedan specifications.
*/
class SedanBuilder : public Builder
{
    private:
    Product FordCar;
    public:
     void SetMake()override
     {
        FordCar.setMake("Ford");
     }
     void SetModel()override
     {
        FordCar.setModel("V35");
     }
     void SetColor()override
     {
        FordCar.setColor("Black");
     }
     void SetYear()override
     {
        FordCar.setYear(2024);
     }
     virtual Product GetCar()
     {
        return FordCar;
     }
};

/*
      Brief  : Class responsible for creating cars using a specified builder.
	  Details  : This class acts as a director in the Builder pattern. It
                 coordinates the construction process by calling the appropriate
                 methods on the provided builder object to set the make, model,
                 color, and year of the car. It then returns the constructed car.
*/
class CarManufacturer
{
    public:
    Product setCar(Builder* Model)
    {
        Model->SetMake();
        Model->SetModel();
        Model->SetColor();
        Model->SetYear();
    return Model->GetCar();
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
*  END OF  FILE: CarProduct.hpp
****************************************************************/
