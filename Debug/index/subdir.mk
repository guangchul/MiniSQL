################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../index/btree.c \
../index/index.c 

OBJS += \
./index/btree.o \
./index/index.o 

C_DEPS += \
./index/btree.d \
./index/index.d 


# Each subdirectory must supply rules for building sources it contributes
index/%.o: ../index/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


