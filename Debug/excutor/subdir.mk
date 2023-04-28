################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../excutor/attrNode.c \
../excutor/column.c 

OBJS += \
./excutor/attrNode.o \
./excutor/column.o 

C_DEPS += \
./excutor/attrNode.d \
./excutor/column.d 


# Each subdirectory must supply rules for building sources it contributes
excutor/%.o: ../excutor/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


