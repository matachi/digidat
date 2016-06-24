		ORG	$1000
		USE	Labdefs.s12
		
main:


main_loop:
		JSR	CheckKbdML15
		JSR	Command
		BRA	main_loop

; COMMAND		
Command:	
		CMPB	#7
		BHI	CommandExit
		LDX	#JUMPTAB
		ASLB
		LDX	B,X
		JSR	,X
CommandExit:	RTS
JUMPTAB		FDB	SUB0,SUB1,SUB2	;,SUB3,SUB4,SUB5,SUB6,SUB7
SUB0:		MOVB	#0,OutPort
		RTS
SUB1:		MOVB	#1,OutPort
		RTS
SUB2:		MOVB	#3,OutPort
		RTS

; CHECKKBDML15
CheckKbdML15:
		
		
		
		USE	Subroutines.s12