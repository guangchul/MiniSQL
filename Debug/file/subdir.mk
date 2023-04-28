################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../file/file.c \
../file/fileNode.c \
../file/table.c 

OBJS += \
./file/file.o \
./file/fileNode.o \
./file/table.o 

C_DEPS += \
./file/file.d \
./file/fileNode.d \
./file/table.d 


# Each subdirectory must supply rules for building sources it contributes
file/%.o: ../file/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


