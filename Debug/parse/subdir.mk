################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../parse/bison.c \
../parse/flex.c \
../parse/parser.c 

OBJS += \
./parse/bison.o \
./parse/flex.o \
./parse/parser.o 

C_DEPS += \
./parse/bison.d \
./parse/flex.d \
./parse/parser.d 


# Each subdirectory must supply rules for building sources it contributes
parse/%.o: ../parse/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


