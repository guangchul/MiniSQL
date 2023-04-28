################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../test/test.c \
../test/testFile.c \
../test/testHashmap.c \
../test/testList.c \
../test/testTable.c 

OBJS += \
./test/test.o \
./test/testFile.o \
./test/testHashmap.o \
./test/testList.o \
./test/testTable.o 

C_DEPS += \
./test/test.d \
./test/testFile.d \
./test/testHashmap.d \
./test/testList.d \
./test/testTable.d 


# Each subdirectory must supply rules for building sources it contributes
test/%.o: ../test/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


