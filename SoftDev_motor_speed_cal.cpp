#include <iostream>
#include <math.h>
using namespace std;

int main() {
    
    double RobotArmSpeed, RobotArmTorque, MotorSpeed, MotorTorque;
    double driverGearSize, driverenGearSize;
    

    // asking the user to put the value for the motor
    cout << "THE DESIRE EFFECTOR SPEED ( in RPM) - between 30 and 150"<<endl;
    cout << "Robot arm desire speed : " << endl; //Robot arm speed 
    cin >> RobotArmSpeed;

    cout << "THE DESIRE EFFECTOR TORQUE ( in N/m) - between 5 and 20" <<endl;
    cout << " desired torque: "<<endl; //robot arm torque
    cin >> RobotArmTorque;

    cout << "THE DESIRE MOTOR SPEED ( in RPM) - between 1500 and 3000" << endl;
    cout << "Enter motor speed: "<<endl; //speed for motor
    cin >> MotorSpeed;

    cout << "ENTER MOTOR TORQUE (Nm, between 1 and 10): "<<endl;
    cout << "Enter motor torque : "<< endl;
    cin >> MotorTorque;

    cout << "Enter number of gears (integer greater than 0): ";
    cin >> numGears;


    // if they want to put below than 0, it will show error
    if (RobotArmSpeed <= 0 || RobotArmTorque <= 0 || MotorSpeed <= 0 || MotorTorque <= 0) {
        cout << "Invalid value. Try again. :( " << endl;
    }

    // formula
    double gearRatioSpeed = MotorSpeed / RobotArmSpeed; //formula for gear speed
    double gearRatioTorque = RobotArmTorque / MotorTorque; //formula for gear torque
    double overallGearRatio = gearRatioSpeed * gearRatioTorque;//formula for overall gear ratio

  
    // For gear ratio from the calculation
    cout << "\nRecommended Gear Ratios:" << endl;
    cout << "Speed Gear Ratio: " << gearRatioSpeed << endl;
    cout << "Torque Gear Ratio: " << gearRatioTorque << endl;
    cout << "Overall Gear Ratio: " << overallGearRatio << endl;

    // give warning when gear ratio >= 10
    if (overallGearRatio >= 10.0) {
        cout << "WARNING....Too much gear ratio.Set within the limit for safety purpose" << endl;
    }

    // checking motor status
    cout << "\nMotor Specifications:" << endl;
    cout << "Motor Speed: " << MotorSpeed << " RPM" << endl;
    cout << "Motor Torque: " << MotorTorque << " Nm" << endl;



    // Suggesting gear sizes based on gear ratio
    cout << "GEAR SIZE RECOMMENDATION :" << endl;
    if (overallGearRatio <= 2.0) {
        cout << "Recommend gear diameter of 20 mm for the drive gear and 40 mm for the driven gear." << endl;
    }
    else if (overallGearRatio <= 3.0) {
        cout << "Recommend gear diameter of 30 mm for the drive gear and 90 mm for the driven gear." << endl;
    }
    else {
        double driveGearSize = 10 * overallGearRatio;  
        double drivenGearSize = driveGearSize * overallGearRatio;
        cout << "For a ratio greater than 3:1, suggest " << driveGearSize<< " mm drive gear and " << drivenGearSize << " mm driven gear." << endl;
    }

    //lessssgooooooooooooooooooooooooooooooo

    return 0;
}

