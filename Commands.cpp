/*
   FSR Board Firmware - Firmware for PCB doing FSR Sensor tests for
    reprap printers auto bed leveling.
    
    Copyright (C) 2015  Roland "Glatzemann" Rosenkranz

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "Global.h"

#include "Commands.h"
#include "Endstop.h"
#include "Sensor.h"
#include "Thermistor.h"
#include "Configuration.h"


#include <Arduino.h>

void Commands::printDiagnose(Sensor& s0, Sensor& s1, Sensor& s2, Thermistor& therm)
{
  outStream->println(F("INFO:diagnostic information"));
  
  outStream->println(F("INFO:sensor 0"));
  outStream->print(F("INFO:is_triggered: "));
  outStream->print(s0.is_triggered());
  outStream->print(F(" is_calibrating: "));
  outStream->println(s0.is_calibrating());
  outStream->print(F("INFO:short_average: "));
  outStream->print(s0.shortAverage());
  outStream->print(F(" long_average: "));
  outStream->println(s0.longAverage());
  
  outStream->println(F("INFO:sensor 1"));
  outStream->print(F("INFO:is_triggered: "));
  outStream->print(s1.is_triggered());
  outStream->print(F(" is_calibrating: "));
  outStream->println(s1.is_calibrating());
  outStream->print(F("INFO:short_average: "));
  outStream->print(s1.shortAverage());
  outStream->print(F(" long_average: "));
  outStream->println(s1.longAverage());

  outStream->println(F("INFO:sensor 2"));
  outStream->print(F("INFO:is_triggered: "));
  outStream->print(s2.is_triggered());
  outStream->print(F(" is_calibrating: "));
  outStream->println(s2.is_calibrating());
  outStream->print(F("INFO:short_average: "));
  outStream->print(s2.shortAverage());
  outStream->print(F(" long_average: "));
  outStream->println(s2.longAverage());

  outStream->println(F("INFO:thermistor"));
  outStream->print(F("INFO:raw resistance: "));
  outStream->println(therm.getRawResistance());
  outStream->print(F("INFO:temperature: "));
  outStream->println(therm.getCurrentTemperature());
}

void Commands::printFirmwareInfo()
{
  outStream->println(F("INFO:Welcome to FSR board Firmware v2 dev"));
}

void Commands::printEndstopStatus(Endstop endstop)
{
  outStream->print(F("INFO:endstop out status: "));
  outStream->println(endstop.is_triggered());
}

void Commands::factorySettings()
{
  Configuration::setDefaults();
  outStream->println(F("INFO:reverted to factory settings, but not stored in EEPROM"));
}

void Commands::storeSettings()
{
  Configuration::storeValues();
  outStream->println(F("INFO:stored settings to EEPROM"));
}

void Commands::printSettings()
{
  Configuration::printSettings();
}

void Commands::setConfigurationValue(const char* k, long v)
{
  outStream->print(F("INFO:set configuration key '"));
  outStream->print(k);
  outStream->print(F("' to value "));
  outStream->println(v);
  Configuration::setKeyValue(k, v);
}

void Commands::unknownCommand()
{
  outStream->println(F("WARN:don't know how to handle that command"));
}

