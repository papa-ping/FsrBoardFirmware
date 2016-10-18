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

#pragma once

#include "CircularBuffer.h"

class Thermistor
{
public:
  Thermistor();

  void update(unsigned long time);
  float getCurrentTemperature();
  float getRawResistance();

private:
  float calc(int rawAdc);

private:
  float currentTemp;
  float resistance;
  CircularBuffer<float, 16> longAverageBuffer;
  unsigned long lastTime;
  unsigned long timeAccu;  
};

