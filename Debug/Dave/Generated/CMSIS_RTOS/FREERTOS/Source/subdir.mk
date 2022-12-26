################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Dave/Generated/CMSIS_RTOS/FREERTOS/Source/cmsis_os1.c \
../Dave/Generated/CMSIS_RTOS/FREERTOS/Source/cmsis_os2.c \
../Dave/Generated/CMSIS_RTOS/FREERTOS/Source/os_systick.c 

OBJS += \
./Dave/Generated/CMSIS_RTOS/FREERTOS/Source/cmsis_os1.o \
./Dave/Generated/CMSIS_RTOS/FREERTOS/Source/cmsis_os2.o \
./Dave/Generated/CMSIS_RTOS/FREERTOS/Source/os_systick.o 

C_DEPS += \
./Dave/Generated/CMSIS_RTOS/FREERTOS/Source/cmsis_os1.d \
./Dave/Generated/CMSIS_RTOS/FREERTOS/Source/cmsis_os2.d \
./Dave/Generated/CMSIS_RTOS/FREERTOS/Source/os_systick.d 


# Each subdirectory must supply rules for building sources it contributes
Dave/Generated/CMSIS_RTOS/FREERTOS/Source/%.o: ../Dave/Generated/CMSIS_RTOS/FREERTOS/Source/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM-GCC C Compiler'
	"$(TOOLCHAIN_ROOT)/bin/arm-none-eabi-gcc" -MMD -MT "$@" -DXMC4800_F100x2048 -I"$(PROJECT_LOC)/Libraries/XMCLib/inc" -I"$(PROJECT_LOC)/Libraries/CMSIS/Include" -I"$(PROJECT_LOC)/Libraries/CMSIS/Infineon/XMC4800_series/Include" -I"$(PROJECT_LOC)" -I"$(PROJECT_LOC)/Dave/Generated" -I"$(PROJECT_LOC)/Libraries" -O0 -ffunction-sections -fdata-sections -Wall -std=gnu99 -mfloat-abi=softfp -Wa,-adhlns="$@.lst" -pipe -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d) $@" -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mthumb -g -gdwarf-2 -o "$@" "$<" 
	@echo 'Finished building: $<'
	@echo.

