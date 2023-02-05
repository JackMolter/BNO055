// code for accelerometer 

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/i2c.h"

#include "bno.h"

void bno055_init() {
    sleep_ms(1000);
    uint8_t data[2];

    // I2C setup
    i2c_init(BNO055_PORT, BNO055_BAUD); // set baud
    gpio_set_function(BNO055_SDA, GPIO_FUNC_I2C);
    gpio_set_function(BNO055_SCK, GPIO_FUNC_I2C);
    gpio_pull_up(BNO055_SDA);
    gpio_pull_up(BNO055_SCK);

    // IMU reset 
    data[0] = BNO055_SYS_TRIGGER;
    data[1] = BNO055_RST_INT;
    i2c_write_blocking(BNO055_PORT,BNO055_ID, data, 2, true);
    sleep_ms(30);


    // set operational mode
    data[0] = BNO055_OPR_MODE;
    data[1] = BNO055_ACCONLY;
    i2c_write_blocking(BNO055_PORT,BNO055_ID, data, 2, true);
    sleep_ms(30);

}

void bno055_read_acc() {
    uint8_t val = BNO055_ACC_DATA_X_LSB;
    uint8_t acc[6];
    int16_t accelX;
    int16_t accelY;
    int16_t accelZ;
    float x;
    float y;
    float z;
    
    while(1) { // here it is, the while loop I forgot, hehe 
        i2c_write_blocking(BNO055_PORT, BNO055_ID, &val, 1, true);
        i2c_read_blocking(BNO055_PORT, BNO055_ID, acc, 6, false);

        accelX = (int16_t)((acc[1]<<8) | acc[0]);   // x axis
        accelY = (int16_t)((acc[3]<<8) | acc[2]);   // y
        accelZ = (int16_t)((acc[5]<<8) | acc[4]);   // z

        x = accelX; // in the video I accidentally defined these variables twice, delete the first one
        y = accelY;
        z = accelZ;

        // print to serial aka minicom
        printf("X axis: %.2f | Y axis: %.2f | Z axis: %.2f |\r\n", x, y, z); // slight change to increase readbility 
        sleep_ms(300);
    }
}

void main() {
    stdio_init_all();

    // initilize the IMU
    bno055_init();
    sleep_ms(50);   // IMU is tired from initilizing

    // read data in loop, display to serial
    bno055_read_acc();

}
