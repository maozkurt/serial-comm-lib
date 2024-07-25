/*
    First implementation for i2c.
    Assumes i2c device is on /dev/i2c-0,
            device adress is 0x08,
            register to be read is 0x01.

*/
#include <iostream>
#include <cstdint>
extern "C"{
    #include <linux/i2c-dev.h>
    #include <i2c/smbus.h>
    #include <fcntl.h>
    #include <sys/ioctl.h>
}

char i2cdevice[] = "/dev/i2c-0";

int main(){
    // Using open to be async-signal-safe
    int fileno = open(i2cdevice, O_RDWR);
    if(fileno < 0){
        std::cerr << "Error while opening " <<  i2cdevice << std::endl;
        exit(1);
    }

    int32_t deviceaddress = 0x08;
    if(ioctl(fileno, I2C_SLAVE, deviceaddress) < 0){
        std::cerr << "Error" << std::endl;
    }

    uint8_t reg2access = 0x01;
    int64_t ret;
    ret = i2c_smbus_read_word_data(fileno, reg2access);
    std::cout  << (int)ret << std::endl;
    if(ret < 0){
        std::cerr << "Error in i2c transaction" << std::endl;
    }

}