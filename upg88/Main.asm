		ORG	$1000
		USE	Labdefs.s12

; MAIN +++++++++++++++++++++++++++++++++		
main:
		MOVB	#$00,DrillControl
		MOVB	#$00,DCShadow

main_loop:
		JSR	CheckKbdML15
		JSR	Command
		BRA	main_loop

; COMMAND ++++++++++++++++++++++++++++++
Command:	
		CMPB	#7
		BHI	CommandExit
		LDX	#JUMPTAB
		ASLB
		LDX	B,X
		JSR	,X
CommandExit:	RTS

JUMPTAB		FDB	SUB9,SUB0,SUB1,SUB2,SUB3,SUB4,SUB5,SUB6,SUB7

SUB9:		RTS

SUB0:		MOVB	#0,OutPort
		JSR	MotorStart
		RTS
SUB1:		MOVB	#1,OutPort
		JSR	MotorStop
		RTS
SUB2:		MOVB	#2,OutPort
		JSR	DrillDown
		RTS
SUB3:		MOVB	#3,OutPort
		JSR	DrillUp
		RTS
SUB4:		MOVB	#4,OutPort
		LDAB	#3
		JSR	Alarm
		RTS
SUB5:		MOVB	#5,OutPort
		JSR	Step
		RTS
SUB6:		MOVB	#6,OutPort
		JSR	DrillHole
		RTS
SUB7:		MOVB	#7,OutPort
		RTS

; CHECKKBDML15 ++++++++++++++++++++++++++
CheckKbdML15:
		LDAB	InPort
		RTS
		
		
		
		USE	Subroutines.s12