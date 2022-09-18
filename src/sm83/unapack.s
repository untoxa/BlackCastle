; aPACK/aPLib decompressor
; Intel 8080 version by Ivan Gorodetsky, 2018-2020
; GBZ80 adaptation by Tony Pavlov, 2020
; No self-modifying code
; Based on z80 version by dwedit/utopian/Metalbrain

        .area _CODE

; void UNAPACK(const unsigned char * sour, unsigned char * dest) OLDCALL;

.MACRO GETBIT3 COND, ?LBL
        JR      COND,LBL
        LD      A,(DE)
        INC     DE
        ADC     A,A
LBL:
.ENDM

_UNAPACK::
        LDA     HL,2(SP)
        LD      A,(HL+)
        LD      E,A
        LD      A,(HL+)
        LD      D,A
        LD      A,(HL+)
        LD      C,A
        LD      A,(HL)
        LD      B,A

; de = source; bc = dest

UNAPACK::
        LD      A,#0x80
APBRANCH1:
        LD      (BITS),A
        LD      A,(DE)
        INC     DE
APLOOP0:
        LD      (BC),A
        INC     BC
        LD      A,#-1
APLOOP:
        LD      (DECR),A

        LD      A,(BITS)
        ADD     A,A
        GETBIT3 NZ
        JR      NC,APBRANCH1
        ADD     A,A
        GETBIT3 NZ
        JR      NC,APBRANCH2
        ADD     A,A
        GETBIT3 NZ
        JR      NC,APBRANCH3
        LD      L,A
        LD      H,#0x10
APGET4BITS:
        ADD     A,A
        JR      NZ,APGET4BITS1
        LD      A,(DE)
        INC     DE
        LD      L,A
        ADC     A,A
APGET4BITS1:
        ADD     HL,HL
        JR      NC,APGET4BITS
        LD      (BITS),A
        XOR     A
        OR      H
        JR      Z,APLOOP0
        LD      A,C
        SUB     H
        LD      L,A
        LD      A,B
        SBC     A,#0
        LD      H,A
        LD      A,(HL)
        JR      APLOOP0
APBRANCH3:
        LD      (BITS),A
        LD      H,#0
        LD      A,(DE)
        RRA
        LD      L,A
        RRA
        ADC     A,A
        RET     Z
        INC     DE
        LD      A,#2
        ADC     A,H
        PUSH    DE

        LD      E, A

        LD      A,L
        LD      (OFFSET), A
        LD      A,H
        LD      (OFFSET+1), A

        LD      D,H
        JR      AP_FINISHUP
APBRANCH2:
        LD      (BITS),A
        CALL    AP_GETGAMMA
        DEC     E
        LD      A,(DECR)
        ADD     A,E
        JR      Z,AP_R0_GAMMA
        DEC     A
        LD      D,A
        LD      E,(HL)

        LD      A,E
        LD      (OFFSET), A
        LD      A,D
        LD      (OFFSET+1), A

        PUSH    DE
        INC     HL

        LD      D,H
        LD      E,L

        CALL    AP_GETGAMMA_

        PUSH    DE
        LD      A,L
        LD      D,H
        LDA     HL,2(SP)
        LD      E,(HL)
        LD      (HL+),A
        LD      A,(HL)
        LD      (HL),D
        LD      H,A
        LD      L,E
        POP     DE

        LD      A,H
        CP      #32000/256
        JR      NC,APSKIP1
        CP      #5
        JR      C,APSKIP2
        INC     DE
APSKIP2:
        LD      A,#0x7F
        SUB     L
        LD      A,#0
        SBC     A,H
        JR      C,APSKIP3
APSKIP1:
        INC     DE
        INC     DE
APSKIP3:
AP_FINISHUP:
        LD      A,C
        SUB     L
        LD      L,A
        LD      A,B
        SBC     A,H
        LD      H,A
AP_FINISHUP2::   
        ; LDIR
        SRL     D
        RR      E
        INC     D
        INC     E
        JR      NC, LDIR_CHECK
        JR      LDIR_NEXT1
        .IRP    LBL,LDIR_NEXT2,LDIR_NEXT1
LBL:
                LD      A,(HL+)
                LD      (BC),A
                INC     BC
        .ENDM 
LDIR_CHECK:
        .IRP    REG,E,D
                DEC     REG
                JR      NZ, LDIR_NEXT2
        .ENDM 
        XOR     A
        POP     DE
        JP      APLOOP

AP_R0_GAMMA:
        LD      D,H
        LD      E,L

        CALL    AP_GETGAMMA_
        PUSH    HL

        LD      HL,#OFFSET
        LD      A,(HL+)
        LD      H,(HL)
        LD      L,A

        JR      AP_FINISHUP

AP_GETGAMMA_:
        LD      A,(BITS)
AP_GETGAMMA:
        LD      HL,#1
AP_GETGAMMALOOP:
        ADD     HL,HL
        ADD     A,A
        GETBIT3 NZ
        JR      NC,AP_GETGAMMALOOP1
        INC     L
AP_GETGAMMALOOP1:
        ADD     A,A
        GETBIT3 NZ
        JR      C,AP_GETGAMMALOOP

        LD      (BITS),A

        LD      A, H
        LD      H, D
        LD      D, A
        LD      A, L
        LD      L, E
        LD      E, A

        RET

        .area _DATA
OFFSET: 
        .DS 2
BITS:   
        .DS 1
DECR:   
        .DS 1
