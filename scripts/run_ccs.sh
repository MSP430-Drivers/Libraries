#! /bin/bash

# verify if /dev/ttyACM0 and /dev/ttyACM1 exist
if [ ! -e "/dev/ttyACM0" ] || [ ! -e "/dev/ttyACM1" ]; then
    echo "Error: MSP /dev/ttyACM0 and /dev/ttyACM1 is not connected."
    exit 1
fi

# give all permision
sudo chmod 777 /dev/ttyACM0
sudo chmod 777 /dev/ttyACM1

# workspace dir
WORKSPACE_DIR="../ccs"

# Archivo de configuración
CONFIG_FILE="../ccs/Drivers.launch"

sleep 5

# open Code Composer Studio
~/Tools/CCS/ccs1230/ccs/eclipse/./ccstudio -data $WORKSPACE_DIR -launch "TI MSP430 USB1/MSP430"
