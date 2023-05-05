################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../process/analyze.c \
../process/analyzeSelectStmt.c \
../process/analyzeUpdateStmt.c \
../process/portal.c \
../process/portalSelectStmt.c \
../process/portalUpdateStmt.c \
../process/process.c \
../process/util.c 

OBJS += \
./process/analyze.o \
./process/analyzeSelectStmt.o \
./process/analyzeUpdateStmt.o \
./process/portal.o \
./process/portalSelectStmt.o \
./process/portalUpdateStmt.o \
./process/process.o \
./process/util.o 

C_DEPS += \
./process/analyze.d \
./process/analyzeSelectStmt.d \
./process/analyzeUpdateStmt.d \
./process/portal.d \
./process/portalSelectStmt.d \
./process/portalUpdateStmt.d \
./process/process.d \
./process/util.d 


# Each subdirectory must supply rules for building sources it contributes
process/%.o: ../process/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


