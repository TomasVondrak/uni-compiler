declare i32 @printf(i8*, ...)
@.special_printf_format_str = constant [4 x i8] c"%c\0A\00"

define void @ahoj(i32 %number, i8 %character) nounwind uwtable {
entry:
	%t0 = icmp slt i32 %number, 10
	br i1 %t0, label %L0, label %L1

L0:
	call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.special_printf_format_str, i32 0), i32 0, i8 97)
	br label %L2

L1:
	call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.special_printf_format_str, i32 0), i32 0, i8 98)
	br label %L2

L2:
	call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.special_printf_format_str, i32 0), i32 0, i8 99)
	ret void
}

define i32 @main() nounwind uwtable {
entry:
	%a = NULL
	%pole [10]
	%var1 = NULL
	%i = 0

L3:
	if NOT (%i slt 20) GOTO %L4
	t1 = %i + 1
	%i = t1
	call void @ahoj(%i, 97)
		br label %L3

L4:
	%var = %pole
	%var2 = %var1.addr
	var1 = 0 - %var1
	%var2 = %var1
	%var2 = *%var1
	*%var = 2
	*%var3 = %var2.addr
	ret 0
}
