################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Control.c \
../DoorLockerMC2.c \
../PWM.c \
../external_eeprom.c \
../i2c.c \
../uart.c 

OBJS += \
./Control.o \
./DoorLockerMC2.o \
./PWM.o \
./external_eeprom.o \
./i2c.o \
./uart.o 

C_DEPS += \
./Control.d \
./DoorLockerMC2.d \
./PWM.d \
./external_eeprom.d \
./i2c.d \
./uart.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


