EESchema Schematic File Version 4
LIBS:socket-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Device:R_US R1
U 1 1 5DC041F5
P 2400 1100
F 0 "R1" V 2195 1100 50  0000 C CNN
F 1 "R_US" V 2286 1100 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 2440 1090 50  0001 C CNN
F 3 "~" H 2400 1100 50  0001 C CNN
	1    2400 1100
	0    1    1    0   
$EndComp
$Comp
L Connector:Conn_01x01_Male J3
U 1 1 5DC042BE
P 3200 1100
F 0 "J3" H 3172 1030 50  0000 R CNN
F 1 "HV" H 3172 1121 50  0000 R CNN
F 2 "MountingHole:MountingHole_6.5mm" H 3200 1100 50  0001 C CNN
F 3 "~" H 3200 1100 50  0001 C CNN
	1    3200 1100
	-1   0    0    1   
$EndComp
Wire Wire Line
	3000 1100 2550 1100
Wire Wire Line
	2250 1100 2100 1100
Wire Wire Line
	2100 1100 2100 1350
Wire Wire Line
	2100 1350 2000 1350
$Comp
L Device:R_US R2
U 1 1 5DC04439
P 2400 2950
F 0 "R2" V 2195 2950 50  0000 C CNN
F 1 "R_US" V 2286 2950 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 2440 2940 50  0001 C CNN
F 3 "~" H 2400 2950 50  0001 C CNN
	1    2400 2950
	0    1    1    0   
$EndComp
Wire Wire Line
	3000 2950 2550 2950
Wire Wire Line
	2250 2950 2100 2950
Wire Wire Line
	2100 2950 2100 3200
Wire Wire Line
	2100 3200 2000 3400
Wire Wire Line
	3000 2950 3000 1100
Connection ~ 3000 1100
$Comp
L Connector_Generic:Conn_01x14 J2
U 1 1 5DC1775D
P 1800 1950
F 0 "J2" H 1720 2767 50  0000 C CNN
F 1 "Nixie" H 1720 2676 50  0000 C CNN
F 2 "nixie-8422:Nixie-8422-14pin" H 1800 1950 50  0001 C CNN
F 3 "~" H 1800 1950 50  0001 C CNN
	1    1800 1950
	-1   0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x14 J1
U 1 1 5DC185BB
P 1800 4000
F 0 "J1" H 1720 4817 50  0000 C CNN
F 1 "Nixie" H 1720 4726 50  0000 C CNN
F 2 "nixie-8422:Nixie-8422-14pin" H 1800 4000 50  0001 C CNN
F 3 "~" H 1800 4000 50  0001 C CNN
	1    1800 4000
	-1   0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_02x08_Odd_Even J4
U 1 1 5E40A24B
P 4575 3025
F 0 "J4" H 4625 3542 50  0000 C CNN
F 1 "Conn_02x08_Odd_Even" H 4625 3451 50  0000 C CNN
F 2 "Connector_IDC:IDC-Header_2x08_P2.54mm_Vertical" H 4575 3025 50  0001 C CNN
F 3 "~" H 4575 3025 50  0001 C CNN
	1    4575 3025
	1    0    0    -1  
$EndComp
Wire Wire Line
	2000 1950 3750 1950
Wire Wire Line
	3750 1950 3750 2725
Wire Wire Line
	3750 2725 4375 2725
Wire Wire Line
	2000 2050 5475 2050
Wire Wire Line
	5475 2050 5475 2725
Wire Wire Line
	5475 2725 4875 2725
Wire Wire Line
	2000 2250 3675 2250
Wire Wire Line
	3675 2250 3675 2825
Wire Wire Line
	3675 2825 4375 2825
Wire Wire Line
	5400 2150 5400 2825
Wire Wire Line
	5400 2825 4875 2825
Wire Wire Line
	2000 2150 5400 2150
Wire Wire Line
	2000 1450 3600 1450
Wire Wire Line
	3600 1450 3600 2925
Wire Wire Line
	3600 2925 4375 2925
Wire Wire Line
	2000 2350 5325 2350
Wire Wire Line
	5325 2350 5325 2925
Wire Wire Line
	5325 2925 4875 2925
Wire Wire Line
	2000 4300 3425 4300
Wire Wire Line
	3425 4300 3425 3025
Wire Wire Line
	3425 3025 4375 3025
Wire Wire Line
	2000 4200 5450 4200
Wire Wire Line
	5450 4200 5450 3025
Wire Wire Line
	5450 3025 4875 3025
Wire Wire Line
	2000 4100 3500 4100
Wire Wire Line
	3500 4100 3500 3125
Wire Wire Line
	3500 3125 4375 3125
Wire Wire Line
	2000 4000 5375 4000
Wire Wire Line
	5375 4000 5375 3125
Wire Wire Line
	5375 3125 4875 3125
Wire Wire Line
	2000 4400 3850 4400
Wire Wire Line
	3850 4400 3850 3225
Wire Wire Line
	3850 3225 4375 3225
Wire Wire Line
	2000 3900 5300 3900
Wire Wire Line
	5300 3900 5300 3225
Wire Wire Line
	5300 3225 4875 3225
Wire Wire Line
	2000 3500 3575 3500
Wire Wire Line
	3575 3500 3575 3325
Wire Wire Line
	3575 3325 4375 3325
Wire Wire Line
	2000 3800 5225 3800
Wire Wire Line
	5225 3800 5225 3325
Wire Wire Line
	5225 3325 4875 3325
Wire Wire Line
	4375 3600 4375 3425
Wire Wire Line
	2000 3600 4375 3600
Wire Wire Line
	2000 3700 4875 3700
Wire Wire Line
	4875 3700 4875 3425
Text Notes 1650 6000 0    80   ~ 0
Rev B:  2/9/2020\nswap J1, J2\nUnscramble wiring on layout
Text Notes 7225 6825 0    80   ~ 0
UPCO 2-digit nixie socket\n
$EndSCHEMATC
