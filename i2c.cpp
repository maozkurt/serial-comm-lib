#include "i2c.hpp"

i2c::device::device(int i2cdeviceno,int deviceaddress){
    i2cfilepath.append(std::to_string(i2cdeviceno));
    this->deviceaddress = deviceaddress;
    // Using open to be async-signal-safe
    this->fileno = open(i2cfilepath.c_str(), O_RDWR);
    if(fileno < 0){
        std::cerr << "Error while opening " <<  i2cfilepath << std::endl;
        exit(1);
    }
    if(ioctl(this->fileno, I2C_SLAVE, deviceaddress) < 0){
        std::cerr << "Error" << std::endl;
    }
}

i2c::device::~device(){

}

