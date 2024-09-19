declare i32 @printf(i8*, ...)
@special_printf_format_char = constant [2 x i8] c"%c"
;@halo = constant [2 x i8] c"%d"

define i32 @main() nounwind uwtable {
entry:
        %t1 = getelementptr inbounds [2 x i8], [2 x i8]* @special_printf_format_char, i32 0, i32 0
        call i32 (i8*, ...) @printf(i8* %t1, i8 97)
        ret i32 0
}
