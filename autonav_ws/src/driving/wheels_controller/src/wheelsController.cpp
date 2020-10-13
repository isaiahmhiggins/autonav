//Joshua Kortje
//Wheel Controller Implimentation
//September 2020

#include "wheelsController.h"

<<<<<<< HEAD
//Control function
double wheelController::control(double desiredSpeed, double currSpeed)
{
    //make sure we don't exceed the max or min values
    double targetSpeed = desiredSpeed;
    if(targetSpeed > maxValue)
    {
        targetSpeed = maxValue;
    }
    else if(targetSpeed < minValue)
    {
        targetSpeed = minValue;
    }

    //get the error
    double error = targetSpeed - currSpeed;
    
    //calculate the I term
    double integralTerm = prevIntegral+error*iterationTime;
    
    //calculate the D term
    double derivativeTerm = (error - prevError)/iterationTime;

    //calculate the output
    double output = Kp*error + Ki*integralTerm + Kd*derivativeTerm;
    
    //Update all of the previous values
    prevError = error;
    prevIntegral = integralTerm;
    
    //Make sure we don't try to adjust too quickly
    if((output - currSpeed) > maxAdjustment)
    {
        //case 1: increasing speed
        output = currSpeed + maxAdjustment;
    }
    else if((currSpeed - output) > maxAdjustment)
    {
        //case 2: decreasing speed
        output = currSpeed - maxAdjustment;
    }
    
    return output;
}

//Fake Main for compilation
int main()
{
    return 0;
}
=======
>>>>>>> f89d0a8363994f9f77a2befcd2c8542dd3066511
