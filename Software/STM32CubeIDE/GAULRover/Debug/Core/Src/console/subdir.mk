################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/console/console.c 

OBJS += \
./Core/Src/console/console.o 

C_DEPS += \
./Core/Src/console/console.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/console/%.o Core/Src/console/%.su Core/Src/console/%.cyclo: ../Core/Src/console/%.c Core/Src/console/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Core/Src -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-console

clean-Core-2f-Src-2f-console:
	-$(RM) ./Core/Src/console/console.cyclo ./Core/Src/console/console.d ./Core/Src/console/console.o ./Core/Src/console/console.su

.PHONY: clean-Core-2f-Src-2f-console

