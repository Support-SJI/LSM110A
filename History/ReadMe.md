## LSM100A Release Note

#### 08/JUN/2022
1. Fixed LoRa Default Key

#### 31/MAY/2022 
+ FW Ver 1.0.1

1. Fixed to store LoRa key data

2. Fixed to select Network type for LoRa

3. Add P2P Function
   a) Add P2P command in Sigfox AT Command
   b) Add P2P command in LoRa AT Command

4. Fixed to improve data transmition/recept for LoRa
    4-1. If receive confirmed data , transfer unconfirmed data

5. Add IAP(Bootloader) to process FW download by serial 
   5-1. Support FW downaload by Y-modem(Serial)
           Refer FW download guide document

6. Improvement of current value before LoRa joining (2.3 uA -> 1.8 uA)		   

7. Changing the storage location of User data for LoRa and Sigfox
   7.1 Location change to prevent user data area’s overflow from SDK support
		   
======================================================

#### 01/FEB/2022
+ FW Ver 1.0.0

1. First Release