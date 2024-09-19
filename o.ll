declare i32 @printf(i8*, ...)
@.special_printf_format_char = constant [2 x i8] c"%c"

define i32 @rule_application(i32 %left, i32 %center, i32 %right) nounwind uwtable {
entry:
	%t0 = icmp eq i32 %left, 1
	br i1 %t0, label %L0, label %L1

L0:
	%t1 = icmp eq i32 %center, 1
	br i1 %t1, label %L3, label %L4

L3:
	%t2 = icmp eq i32 %right, 1
	br i1 %t2, label %L6, label %L7

L6:
	ret i32 0
	br label %L8

L7:
	ret i32 1
	br label %L8

L8:
	br label %L5

L4:
	%t3 = icmp eq i32 %right, 1
	br i1 %t3, label %L9, label %L10

L9:
	ret i32 1
	br label %L11

L10:
	ret i32 0
	br label %L11

L11:
	br label %L5

L5:
	br label %L2

L1:
	%t4 = icmp eq i32 %center, 1
	br i1 %t4, label %L12, label %L13

L12:
	%t5 = icmp eq i32 %right, 1
	br i1 %t5, label %L15, label %L16

L15:
	ret i32 1
	br label %L17

L16:
	ret i32 1
	br label %L17

L17:
	br label %L14

L13:
	%t6 = icmp eq i32 %right, 1
	br i1 %t6, label %L18, label %L19

L18:
	ret i32 1
	br label %L20

L19:
	ret i32 0
	br label %L20

L20:
	br label %L14

L14:
	br label %L2

L2:
	ret i32 0
}

define i32 @main() nounwind uwtable {
entry:
	%pole_size = alloca i32
	store i32 150, i32* %pole_size
	%pole = alloca [150 x i32]
	%new_pole = alloca [150 x i32]
	%iteration_count = alloca i32
	%t8 = load i32, i32* %pole_size
	%t7 = sub i32 %t8, 0
	store i32 %t7, i32* %iteration_count
	%smaller_size = alloca i32
	%t10 = load i32, i32* %pole_size
	%t9 = sub i32 %t10, 1
	store i32 %t9, i32* %smaller_size
	%idx = alloca i32
	%i = alloca i32
	%j = alloca i32
	%current = alloca i32
	%jdx = alloca i32
	%res = alloca i32
	%left = alloca i32
	%right = alloca i32
	%center = alloca i32
	%lefter = alloca i32
	%righter = alloca i32
	%temp = alloca i32
	store i32 0, i32* %i
	br label %L21

L21:
	%t11 = load i32, i32* %i
	%t12 = load i32, i32* %pole_size
	%t13 = icmp slt i32 %t11, %t12
	br i1 %t13, label %L22, label %L23

L22:
	%t15 = load i32, i32* %i
	%t14 = add i32 %t15, 1
	store i32 %t14, i32* %i
	%t17 = load i32, i32* %i
	%t16 = sub i32 %t17, 1
	store i32 %t16, i32* %idx
	%t18 = load i32, i32* %idx
	%t19 = getelementptr inbounds [150 x i32], [150 x i32]* %pole, i32 0, i32 %t18
	store i32 0, i32* %t19
	br label %L21

L23:
	%last_index = alloca i32
	%t22 = load i32, i32* %pole_size
	%t21 = sub i32 %t22, 1
	store i32 %t21, i32* %last_index
	%t23 = load i32, i32* %last_index
	%t24 = getelementptr inbounds [150 x i32], [150 x i32]* %pole, i32 0, i32 %t23
	store i32 1, i32* %t24
	store i32 0, i32* %i
	br label %L24

L24:
	%t26 = load i32, i32* %i
	%t27 = load i32, i32* %pole_size
	%t28 = icmp slt i32 %t26, %t27
	br i1 %t28, label %L25, label %L26

L25:
	%t30 = load i32, i32* %i
	%t29 = add i32 %t30, 1
	store i32 %t29, i32* %i
	%t32 = load i32, i32* %i
	%t31 = sub i32 %t32, 1
	store i32 %t31, i32* %idx
	%t33 = load i32, i32* %idx
	%t34 = getelementptr inbounds [150 x i32], [150 x i32]* %pole, i32 0, i32 %t33
	%t35 = load i32, i32* %t34
	store i32 %t35, i32* %current
	%t36 = load i32, i32* %current
	%t37 = icmp eq i32 %t36, 0
	br i1 %t37, label %L27, label %L28

L27:
	%t38 = getelementptr inbounds [2 x i8], [2 x i8]* @.special_printf_format_char, i32 0, i32 0
	call i32 (i8*, ...) @printf(i8* %t38, i8 32)
	br label %L29

L28:
	%t39 = getelementptr inbounds [2 x i8], [2 x i8]* @.special_printf_format_char, i32 0, i32 0
	call i32 (i8*, ...) @printf(i8* %t39, i8 88)
	br label %L29

L29:
	br label %L24

L26:
	%t40 = getelementptr inbounds [2 x i8], [2 x i8]* @.special_printf_format_char, i32 0, i32 0
	call i32 (i8*, ...) @printf(i8* %t40, i8 10)
	store i32 0, i32* %i
	br label %L30

L30:
	%t41 = load i32, i32* %i
	%t42 = load i32, i32* %iteration_count
	%t43 = icmp slt i32 %t41, %t42
	br i1 %t43, label %L31, label %L32

L31:
	%t45 = load i32, i32* %i
	%t44 = add i32 %t45, 1
	store i32 %t44, i32* %i
	store i32 1, i32* %j
	br label %L33

L33:
	%t46 = load i32, i32* %j
	%t47 = load i32, i32* %smaller_size
	%t48 = icmp slt i32 %t46, %t47
	br i1 %t48, label %L34, label %L35

L34:
	%t50 = load i32, i32* %j
	%t49 = add i32 %t50, 1
	store i32 %t49, i32* %j
	%t52 = load i32, i32* %j
	%t51 = sub i32 %t52, 1
	store i32 %t51, i32* %jdx
	%t53 = load i32, i32* %jdx
	%t54 = getelementptr inbounds [150 x i32], [150 x i32]* %pole, i32 0, i32 %t53
	%t55 = load i32, i32* %t54
	store i32 %t55, i32* %center
	%t57 = load i32, i32* %jdx
	%t56 = sub i32 %t57, 1
	store i32 %t56, i32* %lefter
	%t58 = load i32, i32* %lefter
	%t59 = getelementptr inbounds [150 x i32], [150 x i32]* %pole, i32 0, i32 %t58
	%t60 = load i32, i32* %t59
	store i32 %t60, i32* %left
	%t62 = load i32, i32* %jdx
	%t61 = add i32 %t62, 1
	store i32 %t61, i32* %righter
	%t63 = load i32, i32* %righter
	%t64 = getelementptr inbounds [150 x i32], [150 x i32]* %pole, i32 0, i32 %t63
	%t65 = load i32, i32* %t64
	store i32 %t65, i32* %right
	%t66 = load i32, i32* %left
	%t67 = load i32, i32* %center
	%t68 = load i32, i32* %right
	%t69 = call i32 @rule_application(i32 %t66, i32 %t67, i32 %t68)	store i32 %t69, i32* %res
	%t70 = load i32, i32* %jdx
	%t71 = getelementptr inbounds [150 x i32], [150 x i32]* %new_pole, i32 0, i32 %t70
	%t72 = load i32, i32* %res
	store i32 %t72, i32* %t71
	br label %L33

L35:
	store i32 0, i32* %j
	br label %L36

L36:
	%t74 = load i32, i32* %j
	%t75 = load i32, i32* %pole_size
	%t76 = icmp slt i32 %t74, %t75
	br i1 %t76, label %L37, label %L38

L37:
	%t78 = load i32, i32* %j
	%t77 = add i32 %t78, 1
	store i32 %t77, i32* %j
	%t80 = load i32, i32* %j
	%t79 = sub i32 %t80, 1
	store i32 %t79, i32* %jdx
	%t81 = load i32, i32* %jdx
	%t82 = getelementptr inbounds [150 x i32], [150 x i32]* %new_pole, i32 0, i32 %t81
	%t83 = load i32, i32* %t82
	store i32 %t83, i32* %temp
	%t84 = load i32, i32* %jdx
	%t85 = getelementptr inbounds [150 x i32], [150 x i32]* %pole, i32 0, i32 %t84
	%t86 = load i32, i32* %temp
	store i32 %t86, i32* %t85
	br label %L36

L38:
	store i32 0, i32* %j
	br label %L39

L39:
	%t88 = load i32, i32* %j
	%t89 = load i32, i32* %pole_size
	%t90 = icmp slt i32 %t88, %t89
	br i1 %t90, label %L40, label %L41

L40:
	%t92 = load i32, i32* %j
	%t91 = add i32 %t92, 1
	store i32 %t91, i32* %j
	%t94 = load i32, i32* %j
	%t93 = sub i32 %t94, 1
	store i32 %t93, i32* %jdx
	%t95 = load i32, i32* %jdx
	%t96 = getelementptr inbounds [150 x i32], [150 x i32]* %pole, i32 0, i32 %t95
	%t97 = load i32, i32* %t96
	store i32 %t97, i32* %current
	%t98 = load i32, i32* %current
	%t99 = icmp eq i32 %t98, 0
	br i1 %t99, label %L42, label %L43

L42:
	%t100 = getelementptr inbounds [2 x i8], [2 x i8]* @.special_printf_format_char, i32 0, i32 0
	call i32 (i8*, ...) @printf(i8* %t100, i8 32)
	br label %L44

L43:
	%t101 = getelementptr inbounds [2 x i8], [2 x i8]* @.special_printf_format_char, i32 0, i32 0
	call i32 (i8*, ...) @printf(i8* %t101, i8 88)
	br label %L44

L44:
	br label %L39

L41:
	%t102 = getelementptr inbounds [2 x i8], [2 x i8]* @.special_printf_format_char, i32 0, i32 0
	call i32 (i8*, ...) @printf(i8* %t102, i8 10)
	br label %L30

L32:
	ret i32 0
}
