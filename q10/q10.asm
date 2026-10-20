        ORG 0000H
        ACALL INIT
        MOV A,#80H          ; line 1
        ACALL WCMD
        MOV DPTR,#ENR
        ACALL PRINT
        MOV A,#0C0H         ; line 2
        ACALL WCMD
        MOV DPTR,#FAC
        ACALL PRINT
        SJMP $

INIT:   CLR P1.3
        MOV P1,#20H         ; 4-bit mode
        SETB P1.2
        CLR P1.2
        ACALL DELAY
        MOV A,#28H
        ACALL WCMD
        MOV A,#0CH
        ACALL WCMD
        MOV A,#06H
        ACALL WCMD
        MOV A,#01H
        ACALL WCMD
        RET

WCMD:   CLR P1.3
        SJMP SEND
WDAT:   SETB P1.3
SEND:   PUSH ACC
        ANL A,#0F0H
        MOV R0,A
        MOV A,P1
        ANL A,#0FH
        ORL A,R0
        MOV P1,A
        SETB P1.2
        CLR P1.2
        POP ACC
        SWAP A
        ANL A,#0F0H
        MOV R0,A
        MOV A,P1
        ANL A,#0FH
        ORL A,R0
        MOV P1,A
        SETB P1.2
        CLR P1.2
        ACALL DELAY
        RET

PRINT:  CLR A
        MOVC A,@A+DPTR
        JZ DONE
        ACALL WDAT
        INC DPTR
        SJMP PRINT
DONE:   RET

DELAY:  MOV R7,#50
D1:     MOV R6,#255
        DJNZ R6,$
        DJNZ R7,D1
        RET

ENR:    DB 'GN2904',0
FAC:    DB '24ELBEA184',0
        END
