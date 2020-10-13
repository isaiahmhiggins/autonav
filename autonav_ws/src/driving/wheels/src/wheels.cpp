//Joshua Kortje
//Sept. 2 2020


//Description: This file defins a set of functions that can be used to control the wheels of the robot. 


#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdio.h>
#include <fcntl.h>
#include <termios.h>
#include <unistd.h>
#include <memory.h>

using namespace std;

#define PORT "/dev/ttyUSB0"
//#define PORT "/dev/ttyTHS1"
#define CCW 0x40
#define RIGHT_WHEEL 0x80
#define BAUD_RATE B19200

class wheels
{
    public:
    wheels()
    {
        motorController.open(PORT, std::ofstream::binary);
        if(!motorController.is_open())
        {
<<<<<<< HEAD
            std::cout << "Error opening wheels output port." << std::endl;
=======
            std::cout << "Error opening output port. Exiting..." << std::endl;
>>>>>>> f89d0a8363994f9f77a2befcd2c8542dd3066511
        }
    }
    
    ~wheels()
    {
        motorController.close();
    }
    
    //This function takes a left and right speed and
    //controls each wheel independantly
    //The speeds are positive for forward and 
    //negative for backwards direction. The speeds are defined as
    //being a number with a magnitude less than or equal to 63.
    void CtrlWheels(int leftSpeed, int rightSpeed)
    {
        CtrlRightWheel(rightSpeed);
        CtrlLeftWheel(leftSpeed);
        return;
    }

    private:

    //Control the right wheel
    void CtrlRightWheel(int rightSpeed)
    {
        //build the command
        //the polarity of the right wheel must be reversed
        unsigned char rightCmd = ConvertToHexCmd((-1)*rightSpeed);
        rightCmd = rightCmd | RIGHT_WHEEL; //to select the right wheel
        
        //send the command
        motorController << rightCmd << flush;
        
        return;
    }

    //Control the left wheel
    void CtrlLeftWheel(int leftSpeed)
    {
        //build the command
        unsigned char leftCmd = ConvertToHexCmd(leftSpeed);
        
        //send the command
        motorController << leftCmd << flush;
        
        return;
    }
    
    //This function will take in an integer speed and convert it to 
    //a hexidecimal command that can be interpretted by the 
    //motor controller
    //Note: this function does not take care of the 
    //channel parameter
    unsigned char ConvertToHexCmd(int speed)
    {
        unsigned char cmd = 0x0;
        
        //get the magnitude of the speed (if needed)
        //and the direction
        //if the speed is negative
        //we are going CCW (otherwise CW)
        if(speed < 0)
        {
            int speedMagnitude = -1*speed;
            memcpy(&cmd, &speedMagnitude, sizeof(int)/4);
            cmd = cmd | CCW;
        }
        else
        {
            memcpy(&cmd, &speed, sizeof(int)/4);
        }
        
        return cmd;
    }

    //Hidden copy constructor and copy assignment operator
    wheels(const wheels&);
    wheels& operator=(const wheels&);
    
    //Variables
    ofstream motorController;
    
};





int main()
{
    unsigned char testValue = 0x0;
    int testValue1 = 0;
    int testValue2 = 0;
    
    wheels* wheelDriver = new wheels();
   
    for(int j = 0; j < 20; j++)
    { 
         for(int i = 0; i < 64; i++)
         {
             wheelDriver->CtrlWheels(i, i);
             sleep(1);
         }
         
         for(int i = 63; i > 0; i--)
         {
             wheelDriver->CtrlWheels(i, i);
             sleep(1);
         }
        sleep(3);
    }
    delete wheelDriver;
    
    return 0;
}
