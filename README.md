# Smart-Gardening-Sys
This project implements an IoT-based garden irrigation system that remotely controls water pump operation and monitors soil moisture, temperature, and humidity through the Arduino Cloud platform.

Features

● A Moisture Sensor is installed, if the motor is set in automatic mode based on moisture
in the soil the motor is turned on and off.

● The level of moisture can be monitored through the dashboard created in Arduino cloud.
It is displayed in various formats like value. gauge, chart etc. which makes it user
friendly and readable.

● A temperature and humidity sensor is also installed which detects the temperature and
returns value to the dashboard

● The motor can also be set to manual mode and be controlled manually by using the
switch that can again be accessed using Arduino Cloud

We use NodeMCU (ESP 8266) microcontroller to integrate the entire module where sensors are
connected to it, and data is transferred via a Wi-Fi module that is available in the
microcontroller. The device is portable and requires charging after some time. The data is
transferred directly to the application. Proposed system diagram is a pictorial representation
which shows how every component plays a certain role in it. In this diagram, the device is
depicted in the centre with various components. The network part is an access point allotted for
operating the device. Temperature sensors are used to detect the current status of heat and soil
of air that can be useful for analysing the heat effect on garden plants. Similarly, the YL-69
sensor displays the current moisture levels of soil and the humidity sensor detects the
percentage of water vapours at the moment. All sensors provide the real-time data of plants,
which help us to get an exact situation of the environment.
Users can use this information to treat areas which are affected in the garden. The Charging
Unit consists of a battery that is connected to a power input chip and a circuit board that uses it
to transfer the DC power to sensors for functioning properly. The Display unit can generate
output, i.e., the parameters detected currently in the area along with the IP address.
Requirements of this system are categorised as functional and non-functional requirements
