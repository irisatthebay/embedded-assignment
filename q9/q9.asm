        ORG 0000H
        MOV TMOD,#20H
        MOV TH1,#0F3H
        ORL PCON,#80H
        MOV SCON,#50H
        SETB TR1
LOOP:   JNB RI,$
        MOV A,SBUF
        CLR RI
        XRL P1,A
        SJMP LOOP
        END
