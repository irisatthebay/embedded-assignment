ORG 0000H

RS EQU P1.3
EN EQU P1.2

START:

    CLR RS
    CLR EN

    ; 4-bit mode

    MOV A,#02H
    ACALL LCD_NIBBLE

    ; 4-bit, 2-line, 5x8

    MOV A,#28H
    ACALL CMD

    MOV A,#0CH
    ACALL CMD

    MOV A,#06H
    ACALL CMD

    MOV A,#01H
    ACALL CMD


    ; ALIGARH

    MOV A,#80H
    ACALL CMD

    MOV A,#41H
    ACALL DATA

    MOV A,#4CH
    ACALL DATA

    MOV A,#49H
    ACALL DATA

    MOV A,#47H
    ACALL DATA

    MOV A,#41H
    ACALL DATA

    MOV A,#52H
    ACALL DATA

    MOV A,#48H
    ACALL DATA


    ; MUSLIM

    MOV A,#0C0H
    ACALL CMD

    MOV A,#4DH
    ACALL DATA

    MOV A,#55H
    ACALL DATA

    MOV A,#53H
    ACALL DATA

    MOV A,#4CH
    ACALL DATA

    MOV A,#49H
    ACALL DATA

    MOV A,#4DH
    ACALL DATA


HERE:
    SJMP HERE


LCD_NIBBLE:

    ANL P1,#0FH
    SWAP A
    ANL A,#0F0H
    ORL P1,A

    SETB EN
    CLR EN

    RET


CMD:

    CLR RS
    MOV R7,A

    MOV A,R7
    ANL A,#0F0H
    ANL P1,#0FH
    ORL P1,A

    SETB EN
    CLR EN

    MOV A,R7
    SWAP A
    ANL A,#0F0H
    ANL P1,#0FH
    ORL P1,A

    SETB EN
    CLR EN

    ACALL DELAY

    RET


DATA:

    SETB RS
    MOV R7,A

    MOV A,R7
    ANL A,#0F0H
    ANL P1,#0FH
    ORL P1,A

    SETB EN
    CLR EN

    MOV A,R7
    SWAP A
    ANL A,#0F0H
    ANL P1,#0FH
    ORL P1,A

    SETB EN
    CLR EN

    ACALL DELAY

    RET


DELAY:

    MOV R6,#20

D1:
    MOV R5,#255

D2:
    DJNZ R5,D2
    DJNZ R6,D1

    RET

END
