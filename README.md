# atMEGA Adventure

To build a project just run `make`, connect USBasp to ICSP port and run `make flash`

## Project tree:
```
.
├── game.c
├── game.h
├── include
│   ├── drivers
│   │   ├── adc_buttons.h
│   │   └── lcd_screen.h
│   ├── drivers.h
│   ├── engine
│   │   ├── creatures_engine.h
│   │   ├── locations_engine.h
│   │   └── player_engine.h
│   ├── engine.h
│   ├── sprites
│   │   ├── creatures
│   │   │   └── player.h
│   │   ├── creatures.h
│   │   ├── locations
│   │   │   └── lobby.h
│   │   └── locations.h
│   └── sprites.h
├── lib
│   ├── drivers
│   │   ├── adc_buttons.c
│   │   └── lcd_screen.c
│   ├── drivers.c
│   ├── engine
│   │   ├── creatures_engine.c
│   │   ├── locations_engine.c
│   │   └── player_engine.c
│   └── engine.c
├── LICENSE
└── Makefile

```

## Creating custom locations and creatures

Comming soon!
