declare i32 @printf(i8*, ...)
@.special_printf_format_str = constant [2 x i8] c"%c"

define void @ahoj(i32 %number, i8 %character) nounwind uwtable {
entry:
	%t0 = icmp slt i32 %number, 10
	br i1 %t0, label %L0, label %L1

L0:
	%t1 = getelementptr inbounds [4 x i8], [4 x i8]* @.special_printf_format_str, i32 0, i32 0
	call i32 (i8*, ...) @printf(i8* %t1, i8 97)
	br label %L2

L1:
	%t2 = getelementptr inbounds [4 x i8], [4 x i8]* @.special_printf_format_str, i32 0, i32 0
	call i32 (i8*, ...) @printf(i8* %t2, i8 98)
	br label %L2

L2:
	%t3 = getelementptr inbounds [4 x i8], [4 x i8]* @.special_printf_format_str, i32 0, i32 0
	call i32 (i8*, ...) @printf(i8* %t3, i8 99)
	ret void
}

define i32 @main() nounwind uwtable {
entry:
	%a = alloca i32
	%pole = alloca [10 x i32]
	%var1 = alloca i32
	%i = alloca i32
	store i32 0, i32* %i
	br label %L3

L3:
	%t4 = load i32, i32* %i
	%t5 = icmp slt i32 %t4, 20
	br i1 %t5, label %L4, label %L5

L4:
	%t7 = load i32, i32* %i
	%t6 = add i32 %t7, 1
	store i32 %t6, i32* %i
	%t8 = load i32, i32* %i
	call void @ahoj(i32 %t8, i8 97)
	br label %L3

L5:
	%var = alloca i32
	%t9 = load i32, i32* %pole
	store i32 %t9, i32* %var
	%var2 = alloca i32*
	store i32 * %var1, i32* %var2
	%var3 = alloca i32
	%t11 = load i32, i32* %var1
	%t10 = sub i32 0, %t11
	store i32 %t10, i32* %var3
	%var4 = alloca i32
	%t12 = load i32, i32* %var1
	store i32 %t12, i32* %var4
	store i32 2, i32** %var
	%var5 = alloca i32*
	store i32 * %var2, i32* %var5
	ret i32 0
}
