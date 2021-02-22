#include <time.h>
#include <string>
#include <windows.h>
#include <iostream>

using namespace std;

class USB
{
    public:
        USB();
        ~USB();

        void detect();
        void copy();
        void setPath(string copyTo);

    private:
        char letter;
        bool isExist;


        struct tm *timeDetect;
        string timePath;

        string path;

        string allDrives;
        DWORD lastDwResult;

        void getTime();
};
