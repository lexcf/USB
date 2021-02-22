#include "USB.h"

USB::USB(){
    letter = '0';
    isExist = false;

}

USB::~USB(){

}

void USB::detect() {
    while(true) {
        char drive='0';

        char szLogicalDrives[MAX_PATH];
        DWORD dwResult = GetLogicalDriveStrings(MAX_PATH, szLogicalDrives);

        string currentDrives="";

        for(int i = 0; i <  dwResult; i++)
        {
            if(szLogicalDrives[i]>64 && szLogicalDrives[i]< 90) {
                currentDrives.append(1, szLogicalDrives[i]);

                if(allDrives.find(szLogicalDrives[i]) > 100) {
                    drive = szLogicalDrives[i];
                }
            }
        }

        this->allDrives = currentDrives;
        this->lastDwResult = dwResult;

        if(drive != '0' || drive == 'Y') {
            this->isExist = true;
            this->letter = drive;
            cout << letter;

            this->getTime();
            break;
        }
        Sleep(1000);
    }

    while(true) {
        char drive='0';

        char szLogicalDrives[MAX_PATH];
        DWORD dwResult = GetLogicalDriveStrings(MAX_PATH, szLogicalDrives);

        string currentDrives="";

        for(int i = 0; i <  dwResult; i++)
        {
            if(szLogicalDrives[i]>64 && szLogicalDrives[i]< 90) {
                currentDrives.append(1, szLogicalDrives[i]);

                if(allDrives.find(szLogicalDrives[i]) > 100) {
                    drive = szLogicalDrives[i];
                }
            }
        }

        this->allDrives = currentDrives;
        this->lastDwResult = dwResult;

        if(drive != '0' || drive == 'Y') {
            this->isExist = true;
            this->letter = drive;
            cout << letter;

            this->getTime();
            break;
        }
        Sleep(1000);
    }
}

void USB::getTime() {
    const time_t timeInSec = time(NULL);
    this->timeDetect = localtime(&timeInSec);
    this->timePath = to_string(this->timeDetect->tm_hour) + "-" + to_string(this->timeDetect->tm_min) + "-" + to_string(this->timeDetect->tm_sec) + "___" + to_string(this->timeDetect->tm_mday) + "-" + to_string(this->timeDetect->tm_mon + 1) + "-" + to_string(this->timeDetect->tm_year + 1900);
}

void USB::setPath(string copyTo) {
    this->path = "\"" + copyTo + "\\" + timePath + "\"";
}

void USB::copy() {
    string command = "mkdir \"";
    command += path;
    system(command.c_str());

    command = "xcopy \"";
    command += letter;
    command += ":\\\" ";
    command += path;
    command += " /s /f /d";
    system(command.c_str());
}
