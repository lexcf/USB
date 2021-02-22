#include <iostream>
#include <conio.h>
#include "USB.h"

using namespace std;

int main()
{
    //ShowWindow(GetConsoleWindow(), SW_HIDE);
    setlocale(0, "Russian");
    while(true) {
        USB *usb = new USB();
        usb->detect();
        usb->setPath("C:\\USBClass");
        usb->copy();
        delete usb;
    }
    return 0;
}
