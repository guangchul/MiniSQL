################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../init/buffInit.c \
../init/dirInit.c \
../init/initDB.c \
../init/portInit.c 

OBJS += \
./init/buffInit.o \
./init/dirInit.o \
./init/initDB.o \
./init/portInit.o 

C_DEPS += \
./init/buffInit.d \
./init/dirInit.d \
./init/initDB.d \
./init/portInit.d 


# Each subdirectory must supply rules for building sources it contributes
init/%.o: ../init/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


