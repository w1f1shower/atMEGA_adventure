#ifndef ENGINE_H
#define ENGINE_H

#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>

void engine_err(uint8_t id);

#include "engine/locations_engine.h"
#include "engine/creatures_engine.h"
#include "engine/objects_engine.h"
#include "engine/player_engine.h"

/*| Additional (creature/object)'s header files should be defined here |*/


#endif
