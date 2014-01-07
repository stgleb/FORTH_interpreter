################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../Stack.cc \
../Stack_interface.cc \
../Stack_test.cc \
../logic.cc \
../main.cc \
../stoi.cc 

OBJS += \
./Stack.o \
./Stack_interface.o \
./Stack_test.o \
./logic.o \
./main.o \
./stoi.o 

CC_DEPS += \
./Stack.d \
./Stack_interface.d \
./Stack_test.d \
./logic.d \
./main.d \
./stoi.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/home/courses/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


