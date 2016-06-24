		USE	Labdefs.s12
		ORG	$1000
		
Start:		CLRA
DELAY:		LDX	#DelayConst
NEXT:		LEAX	-1,X
		LDY	#100
NEXT2:		LEAY	-1,Y
		CPY	#0
		BNE	NEXT2
		CPX	#0
		BNE	NEXT
		COMA
		STAA	$400
		BRA	DELAY
		
		USE	Subroutines.s12