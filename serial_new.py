import serial
from threading import Timer

ser = serial.Serial('/dev/ttyUSB0', 9600, timeout=1)
voltage_est = 18
current_est = 3

def read_data():
    try:
        #There will be four voltage and current with temp and cv_volt
        
        # Read values from serial port
        line = ser.readline().decode().strip()
    
        
        # temp=0.00
        # voltage = 0.00
        # oc_voltage=0.00
        # current = 0.00
        tString=""
        if line != '':
            #print(line)
            
            #checks the len of the string if less than or equal 5
            if(len(line)<=5):
                for i in line:
                    #loops through until , is found and add all the charaters to make a comma less string
                    if(i!=","):
                        tString=tString+i
                temp=float(tString)
                #print(tString)
                print(temp)

            else:
                vString=""
                ocString=""
                cString=""
                fstComma=0
                secComma=0
                #trdComma=0

                for i in line:
                    #loops through until , is found and add all the charaters to make a comma less string
                    if(i!=","):
                        vString=vString+i
                        #gets the index of 1st comma
                        fstComma=fstComma+1
                        
                    else:
                        #fstComma=i
                        break
                #print(fstComma)
                voltage=float(vString)
                #print(vString)
                print(voltage)
                for i in line[fstComma+2:]:
                    if(i!=","):
                        ocString=ocString+i
                        #gets the index of 2nd comma
                        secComma=secComma+1
                        
                    else:
                        #fstComma=i
                        break
                #print(secComma)
                oc_voltage=float(ocString)
                #print(ocString)
                print(oc_voltage)
                for i in line[fstComma+2+secComma+2:]:
                    if(i!=","):
                        cString=cString+i
                        #secComma=secComma+1
                        
                    else:
                        #fstComma=i
                        break
                #print(secComma)
                current=float(cString)
                #print(cString)
                print(current)


                
            print("\n")
            # # print(line.split(','))
            # splitted = line.split(',')
            # if len(splitted) == 2:
            #     # print("Voltage:", splitted[0])
            #     voltage = float(splitted[0])
            #     if splitted[1] != '':
            #         # print("Current:", splitted[1])
            #         current = float(splitted[1])
            # elif len(splitted) == 1 :
            #     # print("Current:", splitted[0])
            #         current = float(splitted[0])
            
        # # Print the results
        # print("Voltage: " + str(voltage) +  "V" +  " Current: " + str(current) + "mA")
        # # print(f"Power: {power:.2f} W, Resistance: {resistance:.2f} Ohms")


    except KeyboardInterrupt:
        # Close the serial port on interrupt
        ser.close()

while True:
    read_data()
