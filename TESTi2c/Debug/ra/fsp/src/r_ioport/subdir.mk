################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ra/fsp/src/r_ioport/r_ioport.c 

C_DEPS += \
./ra/fsp/src/r_ioport/r_ioport.d 

OBJS += \
./ra/fsp/src/r_ioport/r_ioport.o 

SREC += \
TESTi2c.srec 

MAP += \
TESTi2c.map 


# Each subdirectory must supply rules for building sources it contributes
ra/fsp/src/r_ioport/%.o: ../ra/fsp/src/r_ioport/%.c
	$(file > $@.in,-mcpu=cortex-m23 -mthumb -O2 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-strict-aliasing -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Wlogical-op -Waggregate-return -Wfloat-equal -g -D_RENESAS_RA_ -D_RA_CORE=CM23 -D_RA_ORDINAL=1 -I"I:/work/TESTi2c/TESTi2c/src" -I"." -I"I:/work/TESTi2c/TESTi2c/ra/fsp/inc" -I"I:/work/TESTi2c/TESTi2c/ra/fsp/inc/api" -I"I:/work/TESTi2c/TESTi2c/ra/fsp/inc/instances" -I"I:/work/TESTi2c/TESTi2c/ra/arm/CMSIS_5/CMSIS/Core/Include" -I"I:/work/TESTi2c/TESTi2c/ra_gen" -I"I:/work/TESTi2c/TESTi2c/ra_cfg/fsp_cfg/bsp" -I"I:/work/TESTi2c/TESTi2c/ra_cfg/fsp_cfg" -std=c99 -Wno-stringop-overflow -Wno-format-truncation --param=min-pagesize=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" -x c "$<")
	@echo Building file: $< && arm-none-eabi-gcc @"$@.in"

