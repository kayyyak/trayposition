################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/nineholes.c 

OBJS += \
./Core/nineholes.o 

C_DEPS += \
./Core/nineholes.d 


# Each subdirectory must supply rules for building sources it contributes
Core/%.o Core/%.su: ../Core/%.c Core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/fibo/sophomore/semester 2/fra262/ActionPlan/trayposition/stm32/DSP/ComputeLibrary/Include" -I"D:/fibo/sophomore/semester 2/fra262/ActionPlan/trayposition/stm32/DSP/Include" -I"D:/fibo/sophomore/semester 2/fra262/ActionPlan/trayposition/stm32/DSP/PrivateInclude" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core

clean-Core:
	-$(RM) ./Core/nineholes.d ./Core/nineholes.o ./Core/nineholes.su

.PHONY: clean-Core

