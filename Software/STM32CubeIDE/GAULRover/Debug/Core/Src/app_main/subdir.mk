################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/app_main/app_main.c 

OBJS += \
./Core/Src/app_main/app_main.o 

C_DEPS += \
./Core/Src/app_main/app_main.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/app_main/%.o Core/Src/app_main/%.su Core/Src/app_main/%.cyclo: ../Core/Src/app_main/%.c Core/Src/app_main/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Core/Src -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-app_main

clean-Core-2f-Src-2f-app_main:
	-$(RM) ./Core/Src/app_main/app_main.cyclo ./Core/Src/app_main/app_main.d ./Core/Src/app_main/app_main.o ./Core/Src/app_main/app_main.su

.PHONY: clean-Core-2f-Src-2f-app_main

