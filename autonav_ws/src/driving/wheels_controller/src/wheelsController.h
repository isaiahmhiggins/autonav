//Joshua Kortje
//Wheel Controller Class
//September 2020

#ifndef WHEEL_CONTROLLER_H
#define WHEEL_CONTROLLER_H

<<<<<<< HEAD
#include <controller/controller.h>

class wheelController: public controller
{
    public:
    //Constructor
    //newKp -proportional gain
    //newKd -derivative gain
    //newKi -integral gain
    //newMax and newMin -max and min values for the controllered variable
    wheelController(double newKp, double newKd, double newKi, double newMax, double newMin, double newMaxAdjustment = 5.0, double newIterationTime = 1.0) : controller(newKp, newKd, newKi, newMax, newMin)
{
    iterationTime = newIterationTime;
    maxAdjustment = newMaxAdjustment;
}

    //Destructor
    ~wheelController();

    //Control function
    //This function takes in the desired value and the current value
    //and after doing some calculations, returns the
    //manipulated value.
    virtual double control(double desiredSpeed, double currSpeed);
    
    private:
    //parameter for limiting the speed the controller might change the output
    double maxAdjustment;
=======
#include <controller.h>

class wheelController: public controller
{


>>>>>>> f89d0a8363994f9f77a2befcd2c8542dd3066511
};

#endif //WHEEL_CONTROLLER_H
