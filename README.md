## Thrust Vector Control 
#### and other aerocraft control algorithms (experimental).

Note: I'm using the arduino ide with espressif's board library added
76.2


### Inputs:
- MPU6050 6 axis (SPI i think, gyro: 3-axis, zoom-factor: 3-axis)
    - needs to be calibrated and de-noised before flights
- GPS (TX/RX NMEO or whatever protocol. primarily for telemetry)
- T/H: optional, might be helpful for high percision apps


Need to buy:
- barometric altimiter: BMP390
- magnometer/better MPU: MPU9250
- MG90 (metal geared sg90) or higher quality servo actuators
- higher quality gimble parts (STL files)[https://www.thingiverse.com/thing:3727207]
- dedicated 9V to 5V converters and 9V battery connector
- body (diameter TBD, id like to look at carbon fiber if thats practical. possibly with a thin skin layer then some sort of optimized internal support structure. diameter may be around 3 inches or 76.2mm possible just 100mm external)
s


---



### TVC 2 axis gimble

Outputs:
- sg90X : 0-180º / 1-2ms 
- sg90Y : 0-180º / 1-2ms

1.5ms center
50hz or 20ms cycles
PWM (Pulse Width Modulation)

Grid layout w/ (x,y) 2d coordinate Inverse kinematics (IK) control interface for demo/calibrating
or use circle display w/ degrees and distance to reprecent the reletive position of the nozzle

gimble easily 3d printable off thingiverse, look at manufacturing w/ appropriate metal or composite materials. currently using PLA
()[https://www.thingiverse.com/thing:3727207]
(bps.space)[https://www.thingiverse.com/thing:3657663]


---

### Fins direct

Outputs:
- sg90<n> : 0-180º / 1-2ms

would 2 make a rocket controlable in all axis? 
how could you make a rocket controlable with a single servo?


---

### TVC w/ fins in nozzle

All the materials i currently have access to will melt or burn

---

bendy rocket
- essentially traditional thrust vector controling but moving the pivot point of the motor up
- adds a single control surface (body of rocket acts as airfoil)

- flexible section
- pivot point design
- 2 axis gimble
- could use a spring/helxical antenna tuned for a specific frequency for telemetry and as the flexable structure/support
- use fishing wire to pull one side closer to actuate the movment

- would there be any benifit over full TVC or control surfaces? 

---


Boards
- ATtiny85
- esp32-c6
- arduino nano
- esp-wroom-32 dev board 



---
