################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../cache/blocksCache.c \
../cache/hashmap.c 

OBJS += \
./cache/blocksCache.o \
./cache/hashmap.o 

C_DEPS += \
./cache/blocksCache.d \
./cache/hashmap.d 


# Each subdirectory must supply rules for building sources it contributes
cache/%.o: ../cache/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


