################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../MultipleChoice.cpp \
../OpenQuestion.cpp \
../Question.cpp \
../Questionnaire.cpp \
../YesNoQuestion\ .cpp \
../main.cpp 

OBJS += \
./MultipleChoice.o \
./OpenQuestion.o \
./Question.o \
./Questionnaire.o \
./YesNoQuestion\ .o \
./main.o 

CPP_DEPS += \
./MultipleChoice.d \
./OpenQuestion.d \
./Question.d \
./Questionnaire.d \
./YesNoQuestion\ .d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

YesNoQuestion\ .o: ../YesNoQuestion\ .cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"YesNoQuestion .d" -MT"YesNoQuestion\ .d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


