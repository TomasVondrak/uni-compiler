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
	%a = alloca i32
	%pole = alloca [10 x i32]
	%var1 = alloca i32
	%i = alloca i32
	store i32 0, i32* %i

L3:
	if NOT (%i slt 20) GOTO %L4
	t1 = %i + 1
	store i32 t1, i32* %i
	call void @ahoj(%i, 97)
	br label %L3

L4:
	%var = alloca i32
	store i32 %pole, i32* %var
	%var2 = alloca i32
	store i32 %var1.addr, i32* %var2
	%var2 = alloca i32
	var1 = 0 - %var1
	store i32 %var1, i32* %var2
	%var2 = alloca i32
	store i32 *%var1, i32* %var2
	store i32 2, i32** %%var
	%var3 = alloca i32*
	store i32 %var2.addr, i32* %var3
	ret 0
}
