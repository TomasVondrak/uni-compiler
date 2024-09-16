
define void @ahoj(i32 %number, i8 %character) nounwind uwtable {
entry:
	%t0 = icmp slt i32 %number, 10
	br i1 %t0, label %L0, label %L1

L0:
	call i32 (i8*, ...)* @printf(i8* getelementptr inbounds (i8, i8 97))
	GOTO %L2

L1:
	putchar 'b'

L2:
	putchar 'c'
}

define i32 @main() nounwind uwtable {
entry:
	i32 %a = NULL
	i32 %pole [10]
	i32 %var1 = NULL
	i32 %i = 0

L3:
	if NOT (%i slt 20) GOTO %L4
	t1 = %i + 1
	%i = t1
	call void @ahoj(%i, 'a')
	JUMP to %L3

L4:
	i32 %var = %pole
	i32 %var2 = %var1.addr
	var1 = 0 - %var1
	i32 %var2 = %var1
	i32 %var2 = *%var1
	*%var = 2
	i32 *%var3 = %var2.addr
	ret 0
}
