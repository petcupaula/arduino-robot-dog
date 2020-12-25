# arduino-robot-dog

## Components

* Adafruit Feather Huzzah ESP8266 (https://www.adafruit.com/product/2821)
* Micro Servo MG90S
* Grove Buzzer (Piezo speaker) (https://wiki.seeedstudio.com/Grove-Buzzer/)
* Sound Detector (https://www.aliexpress.com/item/32569653599.html)
* FSR (Force Sensitive Resistor) 
* IC 4051

## Circuit

![Schematics](robot_dog_schematics_bb.png?raw=true "Schematics")

## Current functionality

* When the dog is being petted, the tail will move and it will bark. The dog is happy. 
* When there's complete silence for a duration of time, the dog will start making high-pitch sounds requesting attention. The dog is sad.

## Ideas for further development

Customize your dog!

* There are 4 force sensors in the dog, and you can read the value of each of them individually. Currently, the actions for when the dog is being petted (i.e. there is some force applied on the sensors) is the same. An idea for further development is to apply customized actions depending on *where* the dog is being petted. 
* Customize the sounds that the dog makes. 
* Add additional sensors, for examples a gas sensor, or a distance sensor. 
* Replace the micro-USB power supply with a Lithium polymer battery (see the documentation for the Adafruit Feather Huzzah board) which will make the dog a bit less heavy. 
* The Adafruit Feather Huzzah board has Wi-Fi on board! So you could control remotely your dog, as well as log the data from its sensors. For example, you could make the dog bark whenever you want (or when the others the least expect it), or you can track how much it has been petted over time. You can have a look at the Adafruit.io platform if you need inspiration for how to store sensor data. 
