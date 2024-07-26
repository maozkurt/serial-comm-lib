#ifndef I2C_HPP
#define I2C_HPP

#include <iostream>
#include <cstdint>
#include <string>
extern "C"{
    #include <linux/i2c-dev.h>
    #include <i2c/smbus.h>
    #include <fcntl.h>
    #include <sys/ioctl.h>
}

namespace i2c {
    class device {
    private:
        std::string  i2cfilepath = "/dev/i2c-";
        int deviceaddress;
        int fileno;
    public:
        device(int i2cdeviceno, int deviceaddress);
        ~device();
        int getfileno(){return fileno;};
        void test(){
            std::cout << i2cfilepath << ' ' << deviceaddress << std::endl;
        }
        int read(uint8_t registerno);
        int write(uint8_t registerno, int data);
    };
}

#endif