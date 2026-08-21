rem   *** validation ***
call scripts\run-validator-tests.bat
call scripts\run-checker-tests.bat

rem    *** tests ***
md tests
call scripts\gen-input-via-stdout.bat "files\generator.exe -sub=0 -max=0 -seed=1" "tests\02" 2
call scripts\gen-input-via-stdout.bat "files\generator.exe -sub=0 -max=0 -seed=2" "tests\03" 3
call scripts\gen-input-via-stdout.bat "files\generator.exe -sub=1 -max=0 -seed=1" "tests\04" 4
call scripts\gen-input-via-stdout.bat "files\generator.exe -sub=1 -max=1 -seed=1" "tests\05" 5
call scripts\gen-input-via-stdout.bat "files\generator.exe -sub=1 -max=0 -seed=2" "tests\06" 6
call scripts\gen-input-via-stdout.bat "files\generator.exe -sub=1 -max=1 -seed=2" "tests\07" 7
call scripts\gen-input-via-stdout.bat "files\generator.exe -sub=2 -max=0 -seed=1" "tests\08" 8
call scripts\gen-input-via-stdout.bat "files\generator.exe -sub=2 -max=1 -seed=1" "tests\09" 9
call scripts\gen-input-via-stdout.bat "files\generator.exe -sub=2 -max=0 -seed=2" "tests\10" 10
call scripts\gen-input-via-stdout.bat "files\generator.exe -sub=2 -max=1 -seed=2" "tests\11" 11
call scripts\gen-input-via-stdout.bat "files\generator.exe -sub=3 -max=0 -seed=1" "tests\12" 12
call scripts\gen-input-via-stdout.bat "files\generator.exe -sub=3 -max=1 -seed=1" "tests\13" 13
call scripts\gen-input-via-stdout.bat "files\generator.exe -sub=3 -max=0 -seed=2" "tests\14" 14
call scripts\gen-input-via-stdout.bat "files\generator.exe -sub=3 -max=1 -seed=2" "tests\15" 15
call scripts\gen-input-via-stdout.bat "files\generator.exe -sub=3 -max=0 -seed=3" "tests\16" 16
call scripts\gen-input-via-stdout.bat "files\generator.exe -sub=3 -max=1 -seed=3" "tests\17" 17
call scripts\gen-input-via-stdout.bat "files\generator.exe -sub=3 -max=0 -seed=4" "tests\18" 18
call scripts\gen-input-via-stdout.bat "files\generator.exe -sub=3 -max=1 -seed=4" "tests\19" 19
call scripts\gen-input-via-stdout.bat "files\generator.exe -sub=4 -max=0 -seed=1" "tests\20" 20
call scripts\gen-input-via-stdout.bat "files\generator.exe -sub=4 -max=1 -seed=1" "tests\21" 21
call scripts\gen-input-via-stdout.bat "files\generator.exe -sub=4 -max=0 -seed=2" "tests\22" 22
call scripts\gen-input-via-stdout.bat "files\generator.exe -sub=4 -max=1 -seed=2" "tests\23" 23
call scripts\gen-input-via-stdout.bat "files\generator.exe -sub=4 -max=0 -seed=3" "tests\24" 24
call scripts\gen-input-via-stdout.bat "files\generator.exe -sub=4 -max=1 -seed=3" "tests\25" 25
call scripts\gen-input-via-stdout.bat "files\generator.exe -sub=4 -max=0 -seed=4" "tests\26" 26
call scripts\gen-input-via-stdout.bat "files\generator.exe -sub=4 -max=1 -seed=4" "tests\27" 27
call scripts\gen-input-via-stdout.bat "files\generator.exe -sub=4 -max=0 -seed=5" "tests\28" 28
call scripts\gen-input-via-stdout.bat "files\generator.exe -sub=4 -max=1 -seed=5" "tests\29" 29
call scripts\gen-input-via-stdout.bat "files\generator.exe -sub=4 -max=0 -seed=6" "tests\30" 30
call scripts\gen-input-via-stdout.bat "files\generator.exe -sub=4 -max=1 -seed=6" "tests\31" 31
call scripts\gen-input-via-stdout.bat "files\generator.exe -sub=4 -max=0 -seed=7" "tests\32" 32
call scripts\gen-input-via-stdout.bat "files\generator.exe -sub=4 -max=1 -seed=7" "tests\33" 33
call scripts\gen-input-via-stdout.bat "files\generator.exe -sub=4 -max=0 -seed=8" "tests\34" 34
call scripts\gen-input-via-stdout.bat "files\generator.exe -sub=4 -max=1 -seed=8" "tests\35" 35
call scripts\gen-input-via-stdout.bat "files\generator.exe -sub=4 -max=0 -seed=9" "tests\36" 36
call scripts\gen-input-via-stdout.bat "files\generator.exe -sub=4 -max=1 -seed=9" "tests\37" 37
call scripts\gen-input-via-stdout.bat "files\generator.exe -sub=4 -max=0 -seed=10" "tests\38" 38
call scripts\gen-input-via-stdout.bat "files\generator.exe -sub=4 -max=1 -seed=10" "tests\39" 39
call scripts\gen-input-via-stdout.bat "files\generator.exe -sub=4 -max=0 -seed=11" "tests\40" 40
call scripts\gen-input-via-stdout.bat "files\generator.exe -sub=4 -max=1 -seed=11" "tests\41" 41
call scripts\gen-answer.bat tests\01 tests\01.a "tests" "0"
call scripts\gen-answer.bat tests\02 tests\02.a "tests" "1"
call scripts\gen-answer.bat tests\03 tests\03.a "tests" "1"
call scripts\gen-answer.bat tests\04 tests\04.a "tests" "2"
call scripts\gen-answer.bat tests\05 tests\05.a "tests" "2"
call scripts\gen-answer.bat tests\06 tests\06.a "tests" "2"
call scripts\gen-answer.bat tests\07 tests\07.a "tests" "2"
call scripts\gen-answer.bat tests\08 tests\08.a "tests" "3"
call scripts\gen-answer.bat tests\09 tests\09.a "tests" "3"
call scripts\gen-answer.bat tests\10 tests\10.a "tests" "3"
call scripts\gen-answer.bat tests\11 tests\11.a "tests" "3"
call scripts\gen-answer.bat tests\12 tests\12.a "tests" "4"
call scripts\gen-answer.bat tests\13 tests\13.a "tests" "4"
call scripts\gen-answer.bat tests\14 tests\14.a "tests" "4"
call scripts\gen-answer.bat tests\15 tests\15.a "tests" "4"
call scripts\gen-answer.bat tests\16 tests\16.a "tests" "4"
call scripts\gen-answer.bat tests\17 tests\17.a "tests" "4"
call scripts\gen-answer.bat tests\18 tests\18.a "tests" "4"
call scripts\gen-answer.bat tests\19 tests\19.a "tests" "4"
call scripts\gen-answer.bat tests\20 tests\20.a "tests" "5"
call scripts\gen-answer.bat tests\21 tests\21.a "tests" "5"
call scripts\gen-answer.bat tests\22 tests\22.a "tests" "5"
call scripts\gen-answer.bat tests\23 tests\23.a "tests" "5"
call scripts\gen-answer.bat tests\24 tests\24.a "tests" "5"
call scripts\gen-answer.bat tests\25 tests\25.a "tests" "5"
call scripts\gen-answer.bat tests\26 tests\26.a "tests" "5"
call scripts\gen-answer.bat tests\27 tests\27.a "tests" "5"
call scripts\gen-answer.bat tests\28 tests\28.a "tests" "5"
call scripts\gen-answer.bat tests\29 tests\29.a "tests" "5"
call scripts\gen-answer.bat tests\30 tests\30.a "tests" "5"
call scripts\gen-answer.bat tests\31 tests\31.a "tests" "5"
call scripts\gen-answer.bat tests\32 tests\32.a "tests" "5"
call scripts\gen-answer.bat tests\33 tests\33.a "tests" "5"
call scripts\gen-answer.bat tests\34 tests\34.a "tests" "5"
call scripts\gen-answer.bat tests\35 tests\35.a "tests" "5"
call scripts\gen-answer.bat tests\36 tests\36.a "tests" "5"
call scripts\gen-answer.bat tests\37 tests\37.a "tests" "5"
call scripts\gen-answer.bat tests\38 tests\38.a "tests" "5"
call scripts\gen-answer.bat tests\39 tests\39.a "tests" "5"
call scripts\gen-answer.bat tests\40 tests\40.a "tests" "5"
call scripts\gen-answer.bat tests\41 tests\41.a "tests" "5"

