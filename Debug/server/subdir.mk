################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../server/receive.c \
../server/send.c \
../server/server.c \
../server/socket.c 

OBJS += \
./server/receive.o \
./server/send.o \
./server/server.o \
./server/socket.o 

C_DEPS += \
./server/receive.d \
./server/send.d \
./server/server.d \
./server/socket.d 


# Each subdirectory must supply rules for building sources it contributes
server/%.o: ../server/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


