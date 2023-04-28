################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include util/subdir.mk
-include process/subdir.mk
-include parse/subdir.mk
-include io/subdir.mk
-include init/subdir.mk
-include file/subdir.mk
-include excutor/subdir.mk
-include cache/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: MiniSQL

# Tool invocations
MiniSQL: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: GCC C Linker'
	gcc  -o "MiniSQL" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) MiniSQL
	-@echo ' '

.PHONY: all clean dependents

-include ../makefile.targets
