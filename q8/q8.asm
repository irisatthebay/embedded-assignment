        ORG 0000H
        MOV TMOD,#20H
        MOV TH1,#0F3H
        ORL PCON,#80H
        MOV SCON,#50H
        SETB TR1
AGAIN:  MOV DPTR,#MSG
NEXT:   CLR A
        MOVC A,@A+DPTR
        JZ AGAIN
        MOV SBUF,A
        JNB TI,$
        CLR TI
        INC DPTR
        SJMP NEXT
MSG:    DB 47H,4EH,32H,39H,30H,34H,0
        END
