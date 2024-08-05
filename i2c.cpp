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

int i2c::device::read(uint8_t registerno){
    int ret = i2c_smbus_read_word_data(getfileno(), registerno);
    if(ret < 0){
        std::cerr << "Error in i2c read transaction" << std::endl;
    }
    return ret;
}

int i2c::device::write(uint8_t registerno, int data){
    int status = i2c_smbus_write_word_data(getfileno(), registerno, data);
    if(status < 0){
        std::cerr << "Error in i2c write transaction" << std::endl;
    }
    return status;
}