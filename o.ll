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
	%i = alloca i32
	%j = alloca i32
	%current = alloca i32
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

L24:
	%t15 = load i32, i32* %i
	%t14 = add i32 %t15, 1
	store i32 %t14, i32* %i
	br label %L21

L22:
	%t16 = load i32, i32* %i
	%t17 = getelementptr inbounds [150 x i32], [150 x i32]* %pole, i32 0, i32 %t16
	store i32 0, i32* %t17
	br label %L24

L23:
	%last_index = alloca i32
	%t20 = load i32, i32* %pole_size
	%t19 = sub i32 %t20, 1
	store i32 %t19, i32* %last_index
	%t21 = load i32, i32* %last_index
	%t22 = getelementptr inbounds [150 x i32], [150 x i32]* %pole, i32 0, i32 %t21
	store i32 1, i32* %t22
	store i32 0, i32* %i
	br label %L25

L25:
	%t24 = load i32, i32* %i
	%t25 = load i32, i32* %pole_size
	%t26 = icmp slt i32 %t24, %t25
	br i1 %t26, label %L26, label %L27

L28:
	%t28 = load i32, i32* %i
	%t27 = add i32 %t28, 1
	store i32 %t27, i32* %i
	br label %L25

L26:
	%t29 = load i32, i32* %i
	%t30 = getelementptr inbounds [150 x i32], [150 x i32]* %pole, i32 0, i32 %t29
	%t31 = load i32, i32* %t30
	store i32 %t31, i32* %current
	%t32 = load i32, i32* %current
	%t33 = icmp eq i32 %t32, 0
	br i1 %t33, label %L29, label %L30

L29:
	%t34 = getelementptr inbounds [2 x i8], [2 x i8]* @.special_printf_format_char, i32 0, i32 0
	call i32 (i8*, ...) @printf(i8* %t34, i8 32)
	br label %L31

L30:
	%t35 = getelementptr inbounds [2 x i8], [2 x i8]* @.special_printf_format_char, i32 0, i32 0
	call i32 (i8*, ...) @printf(i8* %t35, i8 88)
	br label %L31

L31:
	br label %L28

L27:
	%t36 = getelementptr inbounds [2 x i8], [2 x i8]* @.special_printf_format_char, i32 0, i32 0
	call i32 (i8*, ...) @printf(i8* %t36, i8 10)
	store i32 0, i32* %i
	br label %L32

L32:
	%t37 = load i32, i32* %i
	%t38 = load i32, i32* %iteration_count
	%t39 = icmp slt i32 %t37, %t38
	br i1 %t39, label %L33, label %L34

L35:
	%t41 = load i32, i32* %i
	%t40 = add i32 %t41, 1
	store i32 %t40, i32* %i
	br label %L32

L33:
	store i32 1, i32* %j
	br label %L36

L36:
	%t42 = load i32, i32* %j
	%t43 = load i32, i32* %pole_size
	%t44 = icmp slt i32 %t42, %t43
	br i1 %t44, label %L37, label %L38

L39:
	%t46 = load i32, i32* %j
	%t45 = add i32 %t46, 1
	store i32 %t45, i32* %j
	br label %L36

L37:
	%t47 = load i32, i32* %j
	%t48 = getelementptr inbounds [150 x i32], [150 x i32]* %pole, i32 0, i32 %t47
	%t49 = load i32, i32* %t48
	store i32 %t49, i32* %center
	%t50 = load i32, i32* %j
	%t51 = icmp eq i32 %t50, 0
	br i1 %t51, label %L40, label %L41

L40:
	%t52 = load i32, i32* %smaller_size
	%t53 = getelementptr inbounds [150 x i32], [150 x i32]* %pole, i32 0, i32 %t52
	%t54 = load i32, i32* %t53
	store i32 %t54, i32* %left
	br label %L42

L41:
	%t56 = load i32, i32* %j
	%t55 = sub i32 %t56, 1
	store i32 %t55, i32* %lefter
	%t57 = load i32, i32* %lefter
	%t58 = getelementptr inbounds [150 x i32], [150 x i32]* %pole, i32 0, i32 %t57
	%t59 = load i32, i32* %t58
	store i32 %t59, i32* %left
	br label %L42

L42:
	%t60 = load i32, i32* %j
	%t61 = load i32, i32* %smaller_size
	%t62 = icmp eq i32 %t60, %t61
	br i1 %t62, label %L43, label %L44

L43:
	%t63 = getelementptr inbounds [150 x i32], [150 x i32]* %pole, i32 0, i32 0
	%t64 = load i32, i32* %t63
	store i32 %t64, i32* %right
	br label %L45

L44:
	%t66 = load i32, i32* %j
	%t65 = add i32 %t66, 1
	store i32 %t65, i32* %righter
	%t67 = load i32, i32* %righter
	%t68 = getelementptr inbounds [150 x i32], [150 x i32]* %pole, i32 0, i32 %t67
	%t69 = load i32, i32* %t68
	store i32 %t69, i32* %right
	br label %L45

L45:
	%t70 = load i32, i32* %left
	%t71 = load i32, i32* %center
	%t72 = load i32, i32* %right
	%t73 = call i32 @rule_application(i32 %t70, i32 %t71, i32 %t72)	store i32 %t73, i32* %res
	%t74 = load i32, i32* %j
	%t75 = getelementptr inbounds [150 x i32], [150 x i32]* %new_pole, i32 0, i32 %t74
	%t76 = load i32, i32* %res
	store i32 %t76, i32* %t75
	br label %L39

L38:
	store i32 0, i32* %j
	br label %L46

L46:
	%t78 = load i32, i32* %j
	%t79 = load i32, i32* %pole_size
	%t80 = icmp slt i32 %t78, %t79
	br i1 %t80, label %L47, label %L48

L49:
	%t82 = load i32, i32* %j
	%t81 = add i32 %t82, 1
	store i32 %t81, i32* %j
	br label %L46

L47:
	%t83 = load i32, i32* %j
	%t84 = getelementptr inbounds [150 x i32], [150 x i32]* %new_pole, i32 0, i32 %t83
	%t85 = load i32, i32* %t84
	store i32 %t85, i32* %temp
	%t86 = load i32, i32* %j
	%t87 = getelementptr inbounds [150 x i32], [150 x i32]* %pole, i32 0, i32 %t86
	%t88 = load i32, i32* %temp
	store i32 %t88, i32* %t87
	br label %L49

L48:
	store i32 0, i32* %j
	br label %L50

L50:
	%t90 = load i32, i32* %j
	%t91 = load i32, i32* %pole_size
	%t92 = icmp slt i32 %t90, %t91
	br i1 %t92, label %L51, label %L52

L53:
	%t94 = load i32, i32* %j
	%t93 = add i32 %t94, 1
	store i32 %t93, i32* %j
	br label %L50

L51:
	%t95 = load i32, i32* %j
	%t96 = getelementptr inbounds [150 x i32], [150 x i32]* %pole, i32 0, i32 %t95
	%t97 = load i32, i32* %t96
	store i32 %t97, i32* %current
	%t98 = load i32, i32* %current
	%t99 = icmp eq i32 %t98, 0
	br i1 %t99, label %L54, label %L55

L54:
	%t100 = getelementptr inbounds [2 x i8], [2 x i8]* @.special_printf_format_char, i32 0, i32 0
	call i32 (i8*, ...) @printf(i8* %t100, i8 32)
	br label %L56

L55:
	%t101 = getelementptr inbounds [2 x i8], [2 x i8]* @.special_printf_format_char, i32 0, i32 0
	call i32 (i8*, ...) @printf(i8* %t101, i8 88)
	br label %L56

L56:
	br label %L53

L52:
	%t102 = getelementptr inbounds [2 x i8], [2 x i8]* @.special_printf_format_char, i32 0, i32 0
	call i32 (i8*, ...) @printf(i8* %t102, i8 10)
	br label %L35

L34:
	ret i32 0
}
