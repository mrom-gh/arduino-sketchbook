#!/bin/bash

stty -F /dev/ttyUSB0 9600
stty -F /dev/ttyUSB0

printf "hello\nworld" > /dev/ttyUSB0

cat < /dev/ttyUSB0

