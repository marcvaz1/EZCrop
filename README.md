# EZCrop

This repository contains the Arduino code for my senior capstone project, EZCrop. This project was an automated miniature greenhouse system that handled a moisture 
sensing watering system and a heat control mechanism. The system utilized 5 soil moisture sensors that were placed around the greenhouse that sent readings to the 
Arduino. If the sensors detected a low level of moisture, the Arduino activated the water pump to send water through the drip emitters. The other mechanism used a 
servo to control wooden louvre blinds that we built ourselves. The blinds had three settings: low, medium, and high, each of which corresponded to a different amount
of sunlight let into the greenhouse. We used a thermistor to send a reading on the temperature within the greenhouse to the Arduino, and the Arduino accordingly sent 
a signal to the servo to set the blinds to its corresponding state.
