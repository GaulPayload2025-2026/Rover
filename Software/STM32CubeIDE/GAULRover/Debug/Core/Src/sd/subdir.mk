################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/sd/sd.c 

OBJS += \
./Core/Src/sd/sd.o 

C_DEPS += \
./Core/Src/sd/sd.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/sd/%.o Core/Src/sd/%.su Core/Src/sd/%.cyclo: ../Core/Src/sd/%.c Core/Src/sd/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Core/Src -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-sd

clean-Core-2f-Src-2f-sd:
	-$(RM) ./Core/Src/sd/sd.cyclo ./Core/Src/sd/sd.d ./Core/Src/sd/sd.o ./Core/Src/sd/sd.su

.PHONY: clean-Core-2f-Src-2f-sd

