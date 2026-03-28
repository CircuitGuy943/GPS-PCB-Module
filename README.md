# GPS-PCB-Module
I needed a simple, but effective GPS capable PCB to accompany my Flight Controller on my drone and I decided to use the large flat area on top to utilise as much ground area as I could, because more ground area means better reception. So I made this PCB which maximises that area and provides me with an FPC connector which I can then attach to the main FC PCB and so use the GPS functionality.

## Features:
- Powerful L80RE-M37 GPS module combined with a ginormous ground plane for good reception.
- CR2032 cell battery holder for keeping time and reducing setup configuration needed
- 6-pin FPC carrying 3.3V power and UART connection to the MCU (not on this board)

## PCB
This is the PCB, simple double sided with cool silkscreen designs on top.

<img src=Pictures/PCB_top.png alt="PCB Layer 1" width="300"/> <img src=Pictures/PCB_bottom.png alt="PCB Layer 2" width="300"/>

## Schematic
And here is the schematic too:

<img src=Pictures/schematic.png alt="Schematic" width="800"/>

## 3D renders
Here are also some 3D renders done in Fusion and KiCad to show off the PCB :)

<img src=Pictures/render1.png alt="Case render 1" width="300"/> <img src=Pictures/render2.png alt="Case render 2" width="300"/> <img src=Pictures/render3.png alt="Case render 3" width="300"/> 

## Firmware Overview
I've also included some basic firmware (**untested**) that should get the GPS module working with the UART connected to an MCU.

## BOM:
The BOM file with the prices is also found in the root directory.


