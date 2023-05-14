################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../process/analyze.c \
../process/analyzeCreateIndexStmt.c \
../process/analyzeDeleteStmt.c \
../process/analyzeSelectStmt.c \
../process/analyzeUpdateStmt.c \
../process/portal.c \
../process/portalCreateIndexStmt.c \
../process/portalDeleteStmt.c \
../process/portalSelectStmt.c \
../process/portalUpdateStmt.c \
../process/process.c \
../process/util.c \
../process/writeSelectStmt.c 

OBJS += \
./process/analyze.o \
./process/analyzeCreateIndexStmt.o \
./process/analyzeDeleteStmt.o \
./process/analyzeSelectStmt.o \
./process/analyzeUpdateStmt.o \
./process/portal.o \
./process/portalCreateIndexStmt.o \
./process/portalDeleteStmt.o \
./process/portalSelectStmt.o \
./process/portalUpdateStmt.o \
./process/process.o \
./process/util.o \
./process/writeSelectStmt.o 

C_DEPS += \
./process/analyze.d \
./process/analyzeCreateIndexStmt.d \
./process/analyzeDeleteStmt.d \
./process/analyzeSelectStmt.d \
./process/analyzeUpdateStmt.d \
./process/portal.d \
./process/portalCreateIndexStmt.d \
./process/portalDeleteStmt.d \
./process/portalSelectStmt.d \
./process/portalUpdateStmt.d \
./process/process.d \
./process/util.d \
./process/writeSelectStmt.d 


# Each subdirectory must supply rules for building sources it contributes
process/%.o: ../process/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


