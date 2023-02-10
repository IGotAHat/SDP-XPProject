//test
#include <iostream>
#include <string>
#include <cmath>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include <cstdlib>
using namespace std;

int main()
{
    double age;
    double crea;
    double mayocrea;
    int cho;
    string gend = "";
    string skin = "";
    double out;
    double out2;
    double out3;
    double out4;
    std::cout << "Enter your Age" << std::endl; // User Enters Age
    std::cin >> age; // Get user input from the keyboard
    std::cout << "Enter your Creatinine in Micromol/l" << std::endl; // User Enters Creatinine
    std::cin >> crea;
    std::cout << "Enter your Birth Gender: F for Female, M for Male" << std::endl; // User Enters a W or a M based on gender
    std::cin >> gend;
    std::cout << "Are you Black? Y/N" << std::endl; // Type a number and press enter
    std::cin >> skin;
    std::cout << "What Calculation should be used?" << std::endl; // User Enters Age
    std::cout << "1: MDRD, 2: CKD-EPI, 3: Mayo, 4: All, 5: All + Avergae" << std::endl;
    std::cin >> cho;

    if(age < 18 || age > 100)
    {
        std::cout << "Users age is incompatible with the Calculation used by this calculator" << std::endl;// Calculation only works if user is over 18 and under 100
    } 
    else
    {
        crea = crea / 88.42;
        if((skin == "y" || skin == "Y") && (gend == "f" || gend == "F")){//check if Black
            out = 175 * pow(crea,-1.154) * pow(age, -0.203) * 0.742 * 1.212;
        }
        else if(gend == "F" || gend == "f"){//check if Female
            out = 175 * pow(crea,-1.154) * pow(age, -0.203) * 0.742;
        }
        else if(skin == "y" || skin == "Y"){//check if Black
            out = 175 * pow(crea,-1.154) * pow(age, -0.203) * 1.212;
        }
        else{
            out = 175 * pow(crea,-1.154) * pow(age, -0.203);
        }
        
        if((gend == "F" || gend == "f") && (skin == "y" || skin == "Y")){
	    out2 = 186 * pow(crea,-1.154) * pow(age, -0.203) * 0.742 * 1.210;
    	}
	    else if(gend == "F" || gend == "f"){//check if Female
            out2 = 186 * pow(crea,-1.154) * pow(age, -0.203) * 0.742;
        }
        else if(skin == "y" || skin == "Y"){//check if Black
            out2 = 186 * pow(crea,-1.154) * pow(age, -0.203) * 1.210;
        }
        else{
            out2 = 186 * pow(crea,-1.154) * pow(age, -0.203);
        }
        if(crea >= 80){
            mayocrea = 80;
            mayocrea = mayocrea/88.42;
        }else{
            mayocrea = crea;
        }
        if(gend == "f" || gend == "F"){
            out3 = 2.71828182845905*((1.911 + (5.249/mayocrea)) - (2.114/pow(mayocrea, 2)) - (0.00686 * age) - 0.205);
        }else{
            out3 = 2.71828182845905*((1.911 + (5.249/mayocrea)) - (2.114/pow(mayocrea, 2)) - (0.00686 * age));
        }
        //GFR = e(1.911 + 5.249/SCr - 2.114/SCr2 - 0.00686 x Age - (0.205 only if Female))
        //e = 2.71828182845905
        // if Crea >= 80, Crea = 80
        out4 = (out + out2)/2;
        if(cho == 1){
            std::cout << "Your eGFR with MDRD is : " + to_string(out2) + " mL/min/1.73 m²" << std::endl;
        }else if(cho == 2){
            std::cout << "Your eGFR with CKD-EPI is : " + to_string(out) + " mL/min/1.73 m²" << std::endl;
        }else if(cho == 3){
            std::cout << "Your eGFR with Mayo is : " + to_string(out3) + " mL/min/1.73 m²" << std::endl;
        }else if(cho == 4){
            std::cout << "Your eGFR with CKD-EPI is : " + to_string(out) + " mL/min/1.73 m²" << std::endl;
            std::cout << "Your eGFR with MDRD is : " + to_string(out2) + " mL/min/1.73 m²" << std::endl;
            std::cout << "Your eGFR with Mayo is : " + to_string(out3) + " mL/min/1.73 m²" << std::endl;
        }else if(cho == 5){
	        std::cout << "Your eGFR with CKD-EPI is : " + to_string(out) + " mL/min/1.73 m²" << std::endl;
            std::cout << "Your eGFR with MDRD is : " + to_string(out2) + " mL/min/1.73 m²" << std::endl;
            std::cout << "Your eGFR with Mayo is : " + to_string(out3) + " mL/min/1.73 m²" << std::endl;
            std::cout << "Your avergaed eGFR is " + to_string(out4) + " mL/min/1.73 m²" << std::endl;
        }
    }
    system("pause");
}