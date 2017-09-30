################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
C:\arduino-1.0.1\libraries\FastLED-3.1.3\FastLED.cpp \
C:\arduino-1.0.1\libraries\FastLED-3.1.3\bitswap.cpp \
C:\arduino-1.0.1\libraries\FastLED-3.1.3\colorpalettes.cpp \
C:\arduino-1.0.1\libraries\FastLED-3.1.3\colorutils.cpp \
C:\arduino-1.0.1\libraries\FastLED-3.1.3\hsv2rgb.cpp \
C:\arduino-1.0.1\libraries\FastLED-3.1.3\lib8tion.cpp \
C:\arduino-1.0.1\libraries\FastLED-3.1.3\noise.cpp \
C:\arduino-1.0.1\libraries\FastLED-3.1.3\power_mgt.cpp \
C:\arduino-1.0.1\libraries\FastLED-3.1.3\wiring.cpp 

LINK_OBJ += \
.\libraries\FastLED-3.1.3\FastLED.cpp.o \
.\libraries\FastLED-3.1.3\bitswap.cpp.o \
.\libraries\FastLED-3.1.3\colorpalettes.cpp.o \
.\libraries\FastLED-3.1.3\colorutils.cpp.o \
.\libraries\FastLED-3.1.3\hsv2rgb.cpp.o \
.\libraries\FastLED-3.1.3\lib8tion.cpp.o \
.\libraries\FastLED-3.1.3\noise.cpp.o \
.\libraries\FastLED-3.1.3\power_mgt.cpp.o \
.\libraries\FastLED-3.1.3\wiring.cpp.o 

CPP_DEPS += \
.\libraries\FastLED-3.1.3\FastLED.cpp.d \
.\libraries\FastLED-3.1.3\bitswap.cpp.d \
.\libraries\FastLED-3.1.3\colorpalettes.cpp.d \
.\libraries\FastLED-3.1.3\colorutils.cpp.d \
.\libraries\FastLED-3.1.3\hsv2rgb.cpp.d \
.\libraries\FastLED-3.1.3\lib8tion.cpp.d \
.\libraries\FastLED-3.1.3\noise.cpp.d \
.\libraries\FastLED-3.1.3\power_mgt.cpp.d \
.\libraries\FastLED-3.1.3\wiring.cpp.d 


# Each subdirectory must supply rules for building sources it contributes
libraries\FastLED-3.1.3\FastLED.cpp.o: C:\arduino-1.0.1\libraries\FastLED-3.1.3\FastLED.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\sloeber\/arduinoPlugin/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"C:\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.19\cores\arduino" -I"C:\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.19\variants\mega" -I"C:\arduino-1.0.1\libraries\FastLED-3.1.3" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

libraries\FastLED-3.1.3\bitswap.cpp.o: C:\arduino-1.0.1\libraries\FastLED-3.1.3\bitswap.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\sloeber\/arduinoPlugin/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"C:\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.19\cores\arduino" -I"C:\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.19\variants\mega" -I"C:\arduino-1.0.1\libraries\FastLED-3.1.3" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

libraries\FastLED-3.1.3\colorpalettes.cpp.o: C:\arduino-1.0.1\libraries\FastLED-3.1.3\colorpalettes.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\sloeber\/arduinoPlugin/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"C:\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.19\cores\arduino" -I"C:\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.19\variants\mega" -I"C:\arduino-1.0.1\libraries\FastLED-3.1.3" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

libraries\FastLED-3.1.3\colorutils.cpp.o: C:\arduino-1.0.1\libraries\FastLED-3.1.3\colorutils.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\sloeber\/arduinoPlugin/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"C:\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.19\cores\arduino" -I"C:\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.19\variants\mega" -I"C:\arduino-1.0.1\libraries\FastLED-3.1.3" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

libraries\FastLED-3.1.3\hsv2rgb.cpp.o: C:\arduino-1.0.1\libraries\FastLED-3.1.3\hsv2rgb.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\sloeber\/arduinoPlugin/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"C:\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.19\cores\arduino" -I"C:\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.19\variants\mega" -I"C:\arduino-1.0.1\libraries\FastLED-3.1.3" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

libraries\FastLED-3.1.3\lib8tion.cpp.o: C:\arduino-1.0.1\libraries\FastLED-3.1.3\lib8tion.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\sloeber\/arduinoPlugin/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"C:\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.19\cores\arduino" -I"C:\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.19\variants\mega" -I"C:\arduino-1.0.1\libraries\FastLED-3.1.3" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

libraries\FastLED-3.1.3\noise.cpp.o: C:\arduino-1.0.1\libraries\FastLED-3.1.3\noise.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\sloeber\/arduinoPlugin/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"C:\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.19\cores\arduino" -I"C:\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.19\variants\mega" -I"C:\arduino-1.0.1\libraries\FastLED-3.1.3" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

libraries\FastLED-3.1.3\power_mgt.cpp.o: C:\arduino-1.0.1\libraries\FastLED-3.1.3\power_mgt.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\sloeber\/arduinoPlugin/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"C:\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.19\cores\arduino" -I"C:\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.19\variants\mega" -I"C:\arduino-1.0.1\libraries\FastLED-3.1.3" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

libraries\FastLED-3.1.3\wiring.cpp.o: C:\arduino-1.0.1\libraries\FastLED-3.1.3\wiring.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\sloeber\/arduinoPlugin/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"C:\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.19\cores\arduino" -I"C:\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.19\variants\mega" -I"C:\arduino-1.0.1\libraries\FastLED-3.1.3" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '


