declare i32 @printf(i8*, ...)
@.special_printf_format_str = constant [2 x i8] c"%c"

define void @set_zeroes(i32* %pole, i32 %size) nounwind uwtable {
entry:
        %i = alloca i32
        store i32 0, i32* %i
        br label %L0

L0:
        %t0 = load i32, i32* %i
        %t1 = icmp slt i32 %t0, %size
        br i1 %t1, label %L1, label %L2

L1:
        %t3 = load i32, i32* %i
        %t2 = add i32 %t3, 1
        store i32 %t2, i32* %i
        %idx = alloca i32
        %t5 = load i32, i32* %i
        %t4 = sub i32 %t5, 1
        store i32 %t4, i32* %idx
        %temp = alloca i32
        %t7 = load i32, i32* %idx
        %t6 = mul i32 32, %t7
        store i32 %t6, i32* %temp
        %field = alloca i32*
        %t9 = load i32, i32* %pole
        %t10 = load i32, i32* %temp
        %t8 = add i32 %t9, %t10
        store i32 %t8, i32* %field
        store i32 0, i32** %field
        br label %L0

L2:
        ret void
}

define void @copy_array(i32* %from, i32* %to, i32 %size) nounwind uwtable {
entry:
        %i = alloca i32
        store i32 0, i32* %i
        br label %L0

L0:
        %t0 = load i32, i32* %i
        %t1 = icmp slt i32 %t0, %size
        br i1 %t1, label %L1, label %L2

L1:
        %t3 = load i32, i32* %i
        %t2 = add i32 %t3, 1
        store i32 %t2, i32* %i
        %idx = alloca i32
        %t5 = load i32, i32* %i
        %t4 = sub i32 %t5, 1
        store i32 %t4, i32* %idx
        %temp = alloca i32
        %t7 = load i32, i32* %idx
        %t6 = mul i32 32, %t7
        store i32 %t6, i32* %temp
        %field1 = alloca i32*
        %t9 = load i32, i32* %from
        %t10 = load i32, i32* %temp
        %t8 = add i32 %t9, %t10
        store i32 %t8, i32* %field1
        %field2 = alloca i32*
        %t12 = load i32, i32* %to
        %t13 = load i32, i32* %temp
        %t11 = add i32 %t12, %t13
        store i32 %t11, i32* %field2
        %t14 = load i32, i32* %field1
        store i32 %t14, i32** %field2
        br label %L0

L2:
        ret void
}

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

define void @make_iteration(i32* %pole, i32 %size) nounwind uwtable {
entry:
        %new_pole = alloca [256 x i32]
        %i = alloca i32
        store i32 0, i32* %i
        br label %L0

L0:
        %t0 = load i32, i32* %i
        %t1 = icmp slt i32 %t0, %size
        br i1 %t1, label %L1, label %L2

L1:
        %t3 = load i32, i32* %i
        %t2 = add i32 %t3, 1
        store i32 %t2, i32* %i
        %idx = alloca i32
        %t5 = load i32, i32* %i
        %t4 = sub i32 %t5, 1
        store i32 %t4, i32* %idx
        %temp = alloca i32
        %t7 = load i32, i32* %idx
        %t6 = mul i32 32, %t7
        store i32 %t6, i32* %temp
        %left = alloca i32
        %right = alloca i32
        %center_index = alloca i32*
        %t9 = load i32, i32* %pole
        %t10 = load i32, i32* %temp
        %t8 = add i32 %t9, %t10
        store i32 %t8, i32* %center_index
        %center = alloca i32
        %t11 = load i32, i32* %center_index
        store i32 %t11, i32* %center
        %left_index = alloca i32*
        %t12 = load i32, i32* %idx
        %t13 = icmp eq i32 %t12, 0
        br i1 %t13, label %L3, label %L4

L3:
        %byte_size = alloca i32
        %t14 = mul i32 32, %size
        store i32 %t14, i32* %byte_size
        %t16 = load i32, i32* %byte_size
        %t15 = sub i32 %t16, 32
        %t18 = load i32, i32* %pole
        %t17 = add i32 %t18, %t15
        store i32 %t17, i32* %left_index
        %t20 = load i32, i32* %left_index
        store i32 %t20, i32* %left
        br label %L5

L4:
        %byte_idx = alloca i32
        %t22 = load i32, i32* %idx
        %t21 = mul i32 32, %t22
        store i32 %t21, i32* %byte_idx
        %t24 = load i32, i32* %byte_idx
        %t23 = sub i32 %t24, 32
        %t26 = load i32, i32* %pole
        %t25 = add i32 %t26, %t23
        store i32 %t25, i32* %left_index
        %t28 = load i32, i32* %left_index
        store i32 %t28, i32* %left
        br label %L5

L5:
        %t29 = sub i32 %size, 1
        %t30 = load i32, i32* %idx
        %t31 = icmp eq i32 %t30, %t29
        br i1 %t31, label %L6, label %L7

L6:
        %t32 = load i32, i32* %pole
        store i32 %t32, i32* %right
        br label %L8

L7:
        %right_index = alloca i32*
        %t34 = load i32, i32* %temp
        %t33 = add i32 %t34, 32
        %t36 = load i32, i32* %pole
        %t35 = add i32 %t36, %t33
        store i32 %t35, i32* %right_index
        %t38 = load i32, i32* %right_index
        store i32 %t38, i32* %right
        br label %L8

L8:
        %res = alloca i32
        %t39 = load i32, i32* %left
        %t40 = load i32, i32* %center
        %t41 = load i32, i32* %right
        %super = call i32 @rule_application(i32 %t39, i32 %t40, i32 %t41)
        store i32 %super, i32* %res
        %res_index = alloca i32*
        %t43 = load i32, i32* %new_pole
        %t44 = load i32, i32* %temp
        %t42 = add i32 %t43, %t44
        store i32 %t42, i32* %res_index
        store i32* %res, i32** %res_index
        br label %L0

L2:
        %t45 = load i32, i32* %new_pole
        %t46 = load i32, i32* %pole
        call void @copy_array(i32 %t45, i32 %t46, i32 %size)
        ret void
}

define void @print_pole(i32* %pole, i32 %size) nounwind uwtable {
entry:
        %i = alloca i32
        store i32 0, i32* %i
        br label %L0

L0:
        %t0 = load i32, i32* %i
        %t1 = icmp slt i32 %t0, %size
        br i1 %t1, label %L1, label %L2

L1:
        %t3 = load i32, i32* %i
        %t2 = add i32 %t3, 1
        store i32 %t2, i32* %i
        %idx = alloca i32
        %t5 = load i32, i32* %i
        %t4 = sub i32 %t5, 1
        store i32 %t4, i32* %idx
        %temp = alloca i32
        %t7 = load i32, i32* %idx
        %t6 = mul i32 32, %t7
        store i32 %t6, i32* %temp
        %current_index = alloca i32*
        %t9 = load i32, i32* %pole
        %t10 = load i32, i32* %temp
        %t8 = add i32 %t9, %t10
        store i32 %t8, i32* %current_index
        %current = alloca i32
        %t11 = load i32, i32* %current_index
        store i32 %t11, i32* %current
        %t12 = load i32, i32* %current
        %t13 = icmp eq i32 %t12, 0
        br i1 %t13, label %L3, label %L4

L3:
        %t14 = getelementptr inbounds [4 x i8], [4 x i8]* @.special_printf_format_str, i32 0, i32 0
        call i32 (i8*, ...) @printf(i8* %t14, i8 32)
        br label %L5

L4:
        %t15 = getelementptr inbounds [4 x i8], [4 x i8]* @.special_printf_format_str, i32 0, i32 0
        call i32 (i8*, ...) @printf(i8* %t15, i8 88)
        br label %L5

L5:
        br label %L0

L2:
        %t16 = getelementptr inbounds [4 x i8], [4 x i8]* @.special_printf_format_str, i32 0, i32 0
        call i32 (i8*, ...) @printf(i8* %t16, i8 92)
        ret void
}

define i32 @main() nounwind uwtable {
entry:
        %pole_size = alloca i32
        store i32 256, i32* %pole_size
        %pole = alloca [256 x i32]
        %iteration_count = alloca i32
        store i32 256, i32* %iteration_count
        %t0 = load i32, i32* %pole
        %t1 = load i32, i32* %pole_size
        call void @set_zeroes(i32 %t0, i32 %t1)
        %byte_pole_size = alloca i32
        %t3 = load i32, i32* %pole_size
        %t2 = mul i32 32, %t3
        store i32 %t2, i32* %byte_pole_size
        %last_index = alloca i32*
        %t5 = load i32, i32* %byte_pole_size
        %t4 = sub i32 %t5, 32
        %t7 = load i32, i32* %pole
        %t6 = add i32 %t7, %t4
        store i32 %t6, i32* %last_index
        store i32 1, i32** %last_index
        %t9 = load i32, i32* %pole
        %t10 = load i32, i32* %pole_size
        call void @print_pole(i32 %t9, i32 %t10)
        %i = alloca i32
        store i32 0, i32* %i
        br label %L0

L0:
        %t11 = load i32, i32* %i
        %t12 = load i32, i32* %iteration_count
        %t13 = icmp slt i32 %t11, %t12
        br i1 %t13, label %L1, label %L2

L1:
        %t15 = load i32, i32* %i
        %t14 = add i32 %t15, 1
        store i32 %t14, i32* %i
        %idx = alloca i32
        %t17 = load i32, i32* %i
        %t16 = sub i32 %t17, 1
        store i32 %t16, i32* %idx
        %t18 = load i32, i32* %pole
        %t19 = load i32, i32* %pole_size
        call void @make_iteration(i32 %t18, i32 %t19)
        %t20 = load i32, i32* %pole
        %t21 = load i32, i32* %pole_size
        call void @print_pole(i32 %t20, i32 %t21)
        br label %L0

L2:
        ret i32 0
}
