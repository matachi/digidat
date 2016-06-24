; Irq3.s12
	use	Labdefs.s12
Port1:	EQU	$0400
Port2:	EQU	$0401

	ORG	$1000
main:
;nollställ variabler
	CLR	Var1
	CLR	Var2
;initiera avbrottsvektor IRQ
	LDX	#IrqR
	STX	$3FF2
;Nollställ I-bit, tillåt avbrott
	CLI
	
main_loop:
	INC	Var1
	MOVB	Var1,Port1
	MOVB	Var2,Port2
	BRA	main_loop
	
;avbrottsrutin
;Ökar Var2 med 1 och kvittera avbrott
IrqR:	
	LDAB	ML19_Stat
	CMPB	#$81
	BEQ	event1
	CMPB	#$82
	BEQ	event2
	RTI
event1:	INC	Var2
	CLR	ML19_AckIrq_1
	BRA	IrqR
event2:	CLR	Var2
	CLR	ML19_AckIrq_2
	BRA	IrqR
	
; Variabler
Var1:	RMB	1
Var2:	RMB	1