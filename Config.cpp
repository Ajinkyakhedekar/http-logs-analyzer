#include "Config.h"
#include "Debug.h"
#include <iostream>
#include <sstream>

Config* Config::_instance = 0;

Config * Config::getInstance() {
    if (!_instance) {
        _instance = new Config();
    }
    return _instance;
}

Config::Config()
: logName("log.txt"), debugMode(0)
{}

void Config::parseArgs(int argc, char **argv) {
    int c;
    while ((c = getopt(argc, argv, "df:")) != -1) {
        switch(c) {
            case 'f':
                this->logName = optarg;
                break;
            case 'd':
                this->debugMode = 1;
                break;
            case '?':
                if (optopt == 'f') {
                    exit(1);
                }
                break;
        }
    }
}

void Config::debug() {
    if (this->debugMode == 1) {
        std::string debugString;
        std::stringstream sstm;
        sstm << "----> debugMode: " << this->debugMode;
        debugString = sstm.str();
        
        Debug::print("Options:");
        Debug::print(debugString);
        Debug::print("----> logName: " + this->logName);
    }
}