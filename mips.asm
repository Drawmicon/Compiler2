.data
lie: .byte '_'  #character variable
x: .space 40 #integer array
y: .word 0  #integer variable
coal: .space 5 #character array
litString0: .asciiz "FoundError:StringsCannotHaveSpaces\nPrintingCharacter:"
litString1: .asciiz "\n"
litString2: .asciiz "Entercharacter:"
litString3: .asciiz "\nInputtedCharacter:"
litString4: .asciiz "\nEnterNumber:"
litString5: .asciiz "InputtedNumber:"
.text
.globl main
.ent main
main:


li $v0, 4
la $a0, litString0   #Print statment
syscall


li $a0,'a'
li $v0, 11    # print_character
syscall



li $v0, 4
la $a0, litString1   #Print statment
syscall



li $v0, 4
la $a0, litString2   #Print statment
syscall


li   $v0, 8   #Read 1 Character
la $a0, lie
li $a1, 2
 syscall


li $v0, 4
la $a0, litString3   #Print statment
syscall

li $v0, 4 #printing character variable
la $a0, lie
syscall



li $v0, 4
la $a0, litString4   #Print statment
syscall


li   $v0, 5
syscall# Read Integer
move $t0, $v0
sw $t0, y


li $v0, 4
la $a0, litString5   #Print statment
syscall

li $v0, 1 #printing int variable
lw $a0, y
syscall


li $v0, 10 			# parameter call code for terminate
syscall
.end main