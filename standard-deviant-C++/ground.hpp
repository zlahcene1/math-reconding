#ifndef GROUND_H_
#define GROUND_H_

#include <iostream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <iterator>
#include <ctime>
#include <cmath>
#include <fstream>

#define SUCCESS 0
#define FAILURE 84

class Ground {
    public:
        int _argument;
        std::string _cmd;
    
        float G;
        float R;
        float S;

        std::vector<std::string> _input;
        void meteo(int, Ground);
    private:

};

enum ARGS {
    STOP,
    CONTINUE,
    EXIT
};

#endif
