		ORG	$1000
		USE	Labdefs.s12

; MAIN +++++++++++++++++++++++++++++++++		
main:
		MOVB	#$00,DrillControl
		MOVB	#$00,DCShadow

main_loop:
		JSR	CheckKbdML15
		NOP
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

JUMPTAB		FDB	SUB0,SUB1,SUB2,SUB3,SUB4,SUB5,SUB6,SUB7

SUB0:		JSR	MotorStart
		RTS
SUB1:		JSR	MotorStop
		RTS
SUB2:		JSR	DrillDown
		RTS
SUB3:		JSR	DrillUp
		RTS
SUB4:		JSR	Step
		RTS
SUB5:		JSR	DrillHole
		RTS
SUB6:		JSR	RefPos
		RTS
SUB7:		JSR	DoAuto
		RTS

; CHECKKBDML15 ++++++++++++++++++++++++++
;CheckKbdML15:
;		LDAB	InPort
;		RTS
CheckKbdML15:	LDAB	InPort
		CMPB	#$80
		BLO	TangentNere ; Om mindre än 1000 0000, då är data available, hoppa till TangentNere
TangentUppe:	LDAB	#$FF
		JMP	return
TangentNere:	PSHB
TngentFortfNer:	LDAB	$9C0
		CMPB	#$80
		BLO	TngentFortfNer ; Tangenten är fortfarande nere, loopa tills den är uppe
		PULB
return:		RTS		
		
		
		USE	Subroutines.s12