#pragma once

// Includes:
#include <iostream>
#include <conio.h>
#include <fstream>
#include <iomanip>
#include "planet.h"
// Functions:
void Menu();
void edit();
Planet* ReadBase(const char*, Planet*, int&);
void WriteBase(const char*, const Planet*, const int&);
Planet* EditBase(Planet*, int&);