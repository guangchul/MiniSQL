################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../util/hash.c \
../util/list.c \
../util/mem.c \
../util/string.c 

OBJS += \
./util/hash.o \
./util/list.o \
./util/mem.o \
./util/string.o 

C_DEPS += \
./util/hash.d \
./util/list.d \
./util/mem.d \
./util/string.d 


# Each subdirectory must supply rules for building sources it contributes
util/%.o: ../util/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


