@echo off
rem   *** validation ***
call scripts\run-validator-tests.bat
call scripts\run-checker-tests.bat

rem    *** tests ***
md tests
echo Generating test #2
call scripts\gen-input-via-stdout.bat "files\gen.exe ""1"" ""20"" ""20"" ""1000000000"" ""5"" ""0"" ""0""" "tests\02" 2
echo Generating test #3
call scripts\gen-input-via-stdout.bat "files\gen.exe ""1"" ""20"" ""20"" ""1000000000"" ""20"" ""0"" ""0""" "tests\03" 3
echo Generating test #4
call scripts\gen-input-via-stdout.bat "files\gen.exe ""10"" ""20"" ""20"" ""1000000000"" ""20"" ""0"" ""0""" "tests\04" 4
echo Generating test #5
call scripts\gen-input-via-stdout.bat "files\gen.exe ""10"" ""20"" ""20"" ""1000000000"" ""20"" ""0"" ""1""" "tests\05" 5
echo Generating test #6
call scripts\gen-input-via-stdout.bat "files\gen.exe ""1"" ""20"" ""20"" ""1000000000"" ""5"" ""1"" ""0""" "tests\06" 6
echo Generating test #7
call scripts\gen-input-via-stdout.bat "files\gen.exe ""1"" ""20"" ""20"" ""1000000000"" ""20"" ""1"" ""0""" "tests\07" 7
echo Generating test #8
call scripts\gen-input-via-stdout.bat "files\gen.exe ""25"" ""50"" ""2000"" ""1000000000"" ""50"" ""0"" ""0""" "tests\08" 8
echo Generating test #9
call scripts\gen-input-via-stdout.bat "files\gen.exe ""500"" ""1250"" ""2000"" ""1000000000"" ""50"" ""0"" ""0""" "tests\09" 9
echo Generating test #10
call scripts\gen-input-via-stdout.bat "files\gen.exe ""500"" ""1250"" ""2000"" ""1000000000"" ""2000"" ""0"" ""0""" "tests\10" 10
echo Generating test #11
call scripts\gen-input-via-stdout.bat "files\gen.exe ""1250"" ""2000"" ""2000"" ""1000000000"" ""50"" ""0"" ""0""" "tests\11" 11
echo Generating test #12
call scripts\gen-input-via-stdout.bat "files\gen.exe ""1250"" ""2000"" ""2000"" ""1000000000"" ""2000"" ""0"" ""0""" "tests\12" 12
echo Generating test #13
call scripts\gen-input-via-stdout.bat "files\gen.exe ""1250"" ""2000"" ""2000"" ""1000000000"" ""2000"" ""0"" ""1""" "tests\13" 13
echo Generating test #14
call scripts\gen-input-via-stdout.bat "files\gen.exe ""1250"" ""2000"" ""2000"" ""1000000000"" ""50"" ""1"" ""0""" "tests\14" 14
echo Generating test #15
call scripts\gen-input-via-stdout.bat "files\gen.exe ""1250"" ""2000"" ""2000"" ""1000000000"" ""2000"" ""1"" ""0""" "tests\15" 15
echo Generating test #16
call scripts\gen-input-via-stdout.bat "files\gen.exe ""1250"" ""2000"" ""2000"" ""1000000000"" ""2000"" ""1"" ""1""" "tests\16" 16
echo Generating test #17
call scripts\gen-input-via-stdout.bat "files\gen.exe ""75"" ""250"" ""50000"" ""1000000000"" ""250"" ""0"" ""0""" "tests\17" 17
echo Generating test #18
call scripts\gen-input-via-stdout.bat "files\gen.exe ""20000"" ""35000"" ""50000"" ""1000000000"" ""250"" ""0"" ""0""" "tests\18" 18
echo Generating test #19
call scripts\gen-input-via-stdout.bat "files\gen.exe ""20000"" ""35000"" ""50000"" ""1000000000"" ""50000"" ""0"" ""0""" "tests\19" 19
echo Generating test #20
call scripts\gen-input-via-stdout.bat "files\gen.exe ""35000"" ""50000"" ""50000"" ""1000000000"" ""250"" ""0"" ""0""" "tests\20" 20
echo Generating test #21
call scripts\gen-input-via-stdout.bat "files\gen.exe ""35000"" ""50000"" ""50000"" ""1000000000"" ""50000"" ""0"" ""0""" "tests\21" 21
echo Generating test #22
call scripts\gen-input-via-stdout.bat "files\gen.exe ""35000"" ""50000"" ""50000"" ""1000000000"" ""50000"" ""0"" ""1""" "tests\22" 22
echo Generating test #23
call scripts\gen-input-via-stdout.bat "files\gen.exe ""35000"" ""50000"" ""50000"" ""1000000000"" ""250"" ""1"" ""0""" "tests\23" 23
echo Generating test #24
call scripts\gen-input-via-stdout.bat "files\gen.exe ""35000"" ""50000"" ""50000"" ""1000000000"" ""50000"" ""1"" ""0""" "tests\24" 24
echo Generating test #25
call scripts\gen-input-via-stdout.bat "files\gen.exe ""35000"" ""50000"" ""50000"" ""1000000000"" ""50000"" ""1"" ""1""" "tests\25" 25
echo Generating test #26
call scripts\gen-input-via-stdout.bat "files\gen.exe ""300"" ""750"" ""400000"" ""100"" ""750"" ""0"" ""0""" "tests\26" 26
echo Generating test #27
call scripts\gen-input-via-stdout.bat "files\gen.exe ""100000"" ""200000"" ""400000"" ""100"" ""400000"" ""0"" ""0""" "tests\27" 27
echo Generating test #28
call scripts\gen-input-via-stdout.bat "files\gen.exe ""200000"" ""300000"" ""400000"" ""100"" ""400000"" ""0"" ""0""" "tests\28" 28
echo Generating test #29
call scripts\gen-input-via-stdout.bat "files\gen.exe ""300000"" ""400000"" ""400000"" ""100"" ""400000"" ""0"" ""0""" "tests\29" 29
echo Generating test #30
call scripts\gen-input-via-stdout.bat "files\gen.exe ""300000"" ""400000"" ""400000"" ""100"" ""400000"" ""0"" ""1""" "tests\30" 30
echo Generating test #31
call scripts\gen-input-via-stdout.bat "files\gen.exe ""300000"" ""400000"" ""400000"" ""100"" ""400000"" ""1"" ""0""" "tests\31" 31
echo Generating test #32
call scripts\gen-input-via-stdout.bat "files\gen.exe ""300000"" ""400000"" ""400000"" ""100"" ""400000"" ""1"" ""1""" "tests\32" 32
echo Generating test #33
call scripts\gen-input-via-stdout.bat "files\gen.exe ""200"" ""500"" ""150000"" ""1000000000"" ""500"" ""0"" ""0""" "tests\33" 33
echo Generating test #34
call scripts\gen-input-via-stdout.bat "files\gen.exe ""60000"" ""90000"" ""150000"" ""1000000000"" ""500"" ""0"" ""0""" "tests\34" 34
echo Generating test #35
call scripts\gen-input-via-stdout.bat "files\gen.exe ""60000"" ""90000"" ""150000"" ""1000000000"" ""150000"" ""0"" ""0""" "tests\35" 35
echo Generating test #36
call scripts\gen-input-via-stdout.bat "files\gen.exe ""90000"" ""120000"" ""150000"" ""1000000000"" ""500"" ""0"" ""0""" "tests\36" 36
echo Generating test #37
call scripts\gen-input-via-stdout.bat "files\gen.exe ""90000"" ""120000"" ""150000"" ""1000000000"" ""150000"" ""0"" ""0""" "tests\37" 37
echo Generating test #38
call scripts\gen-input-via-stdout.bat "files\gen.exe ""120000"" ""150000"" ""150000"" ""1000000000"" ""500"" ""0"" ""0""" "tests\38" 38
echo Generating test #39
call scripts\gen-input-via-stdout.bat "files\gen.exe ""120000"" ""150000"" ""150000"" ""1000000000"" ""150000"" ""0"" ""0""" "tests\39" 39
echo Generating test #40
call scripts\gen-input-via-stdout.bat "files\gen.exe ""120000"" ""150000"" ""150000"" ""1000000000"" ""500"" ""1"" ""0""" "tests\40" 40
echo Generating test #41
call scripts\gen-input-via-stdout.bat "files\gen.exe ""120000"" ""150000"" ""150000"" ""1000000000"" ""150000"" ""1"" ""0""" "tests\41" 41
echo Generating test #42
call scripts\gen-input-via-stdout.bat "files\gen.exe ""120000"" ""150000"" ""150000"" ""1000000000"" ""150000"" ""1"" ""1""" "tests\42" 42
echo Generating test #43
call scripts\gen-input-via-stdout.bat "files\gen.exe ""500"" ""1000"" ""400000"" ""1000000000"" ""1000"" ""0"" ""0""" "tests\43" 43
echo Generating test #44
call scripts\gen-input-via-stdout.bat "files\gen.exe ""150000"" ""225000"" ""400000"" ""1000000000"" ""400000"" ""0"" ""0""" "tests\44" 44
echo Generating test #45
call scripts\gen-input-via-stdout.bat "files\gen.exe ""225000"" ""300000"" ""400000"" ""1000000000"" ""1000"" ""0"" ""0""" "tests\45" 45
echo Generating test #46
call scripts\gen-input-via-stdout.bat "files\gen.exe ""225000"" ""300000"" ""400000"" ""1000000000"" ""400000"" ""0"" ""0""" "tests\46" 46
echo Generating test #47
call scripts\gen-input-via-stdout.bat "files\gen.exe ""300000"" ""400000"" ""400000"" ""1000000000"" ""1000"" ""0"" ""0""" "tests\47" 47
echo Generating test #48
call scripts\gen-input-via-stdout.bat "files\gen.exe ""300000"" ""400000"" ""400000"" ""1000000000"" ""400000"" ""0"" ""0""" "tests\48" 48
echo Generating test #49
call scripts\gen-input-via-stdout.bat "files\gen.exe ""300000"" ""400000"" ""400000"" ""1000000000"" ""1000"" ""1"" ""0""" "tests\49" 49
echo Generating test #50
call scripts\gen-input-via-stdout.bat "files\gen.exe ""300000"" ""400000"" ""400000"" ""1000000000"" ""400000"" ""1"" ""0""" "tests\50" 50
echo Generating test #51
call scripts\gen-input-via-stdout.bat "files\gen.exe ""300000"" ""400000"" ""400000"" ""1000000000"" ""400000"" ""1"" ""1""" "tests\51" 51
echo.
echo Generating answer for test #1
call scripts\gen-answer.bat tests\01 tests\01.a "tests" "0"
echo.
echo Generating answer for test #2
call scripts\gen-answer.bat tests\02 tests\02.a "tests" "1"
echo.
echo Generating answer for test #3
call scripts\gen-answer.bat tests\03 tests\03.a "tests" "1"
echo.
echo Generating answer for test #4
call scripts\gen-answer.bat tests\04 tests\04.a "tests" "1"
echo.
echo Generating answer for test #5
call scripts\gen-answer.bat tests\05 tests\05.a "tests" "1"
echo.
echo Generating answer for test #6
call scripts\gen-answer.bat tests\06 tests\06.a "tests" "1"
echo.
echo Generating answer for test #7
call scripts\gen-answer.bat tests\07 tests\07.a "tests" "1"
echo.
echo Generating answer for test #8
call scripts\gen-answer.bat tests\08 tests\08.a "tests" "2"
echo.
echo Generating answer for test #9
call scripts\gen-answer.bat tests\09 tests\09.a "tests" "2"
echo.
echo Generating answer for test #10
call scripts\gen-answer.bat tests\10 tests\10.a "tests" "2"
echo.
echo Generating answer for test #11
call scripts\gen-answer.bat tests\11 tests\11.a "tests" "2"
echo.
echo Generating answer for test #12
call scripts\gen-answer.bat tests\12 tests\12.a "tests" "2"
echo.
echo Generating answer for test #13
call scripts\gen-answer.bat tests\13 tests\13.a "tests" "2"
echo.
echo Generating answer for test #14
call scripts\gen-answer.bat tests\14 tests\14.a "tests" "2"
echo.
echo Generating answer for test #15
call scripts\gen-answer.bat tests\15 tests\15.a "tests" "2"
echo.
echo Generating answer for test #16
call scripts\gen-answer.bat tests\16 tests\16.a "tests" "2"
echo.
echo Generating answer for test #17
call scripts\gen-answer.bat tests\17 tests\17.a "tests" "3"
echo.
echo Generating answer for test #18
call scripts\gen-answer.bat tests\18 tests\18.a "tests" "3"
echo.
echo Generating answer for test #19
call scripts\gen-answer.bat tests\19 tests\19.a "tests" "3"
echo.
echo Generating answer for test #20
call scripts\gen-answer.bat tests\20 tests\20.a "tests" "3"
echo.
echo Generating answer for test #21
call scripts\gen-answer.bat tests\21 tests\21.a "tests" "3"
echo.
echo Generating answer for test #22
call scripts\gen-answer.bat tests\22 tests\22.a "tests" "3"
echo.
echo Generating answer for test #23
call scripts\gen-answer.bat tests\23 tests\23.a "tests" "3"
echo.
echo Generating answer for test #24
call scripts\gen-answer.bat tests\24 tests\24.a "tests" "3"
echo.
echo Generating answer for test #25
call scripts\gen-answer.bat tests\25 tests\25.a "tests" "3"
echo.
echo Generating answer for test #26
call scripts\gen-answer.bat tests\26 tests\26.a "tests" "4"
echo.
echo Generating answer for test #27
call scripts\gen-answer.bat tests\27 tests\27.a "tests" "4"
echo.
echo Generating answer for test #28
call scripts\gen-answer.bat tests\28 tests\28.a "tests" "4"
echo.
echo Generating answer for test #29
call scripts\gen-answer.bat tests\29 tests\29.a "tests" "4"
echo.
echo Generating answer for test #30
call scripts\gen-answer.bat tests\30 tests\30.a "tests" "4"
echo.
echo Generating answer for test #31
call scripts\gen-answer.bat tests\31 tests\31.a "tests" "4"
echo.
echo Generating answer for test #32
call scripts\gen-answer.bat tests\32 tests\32.a "tests" "4"
echo.
echo Generating answer for test #33
call scripts\gen-answer.bat tests\33 tests\33.a "tests" "5"
echo.
echo Generating answer for test #34
call scripts\gen-answer.bat tests\34 tests\34.a "tests" "5"
echo.
echo Generating answer for test #35
call scripts\gen-answer.bat tests\35 tests\35.a "tests" "5"
echo.
echo Generating answer for test #36
call scripts\gen-answer.bat tests\36 tests\36.a "tests" "5"
echo.
echo Generating answer for test #37
call scripts\gen-answer.bat tests\37 tests\37.a "tests" "5"
echo.
echo Generating answer for test #38
call scripts\gen-answer.bat tests\38 tests\38.a "tests" "5"
echo.
echo Generating answer for test #39
call scripts\gen-answer.bat tests\39 tests\39.a "tests" "5"
echo.
echo Generating answer for test #40
call scripts\gen-answer.bat tests\40 tests\40.a "tests" "5"
echo.
echo Generating answer for test #41
call scripts\gen-answer.bat tests\41 tests\41.a "tests" "5"
echo.
echo Generating answer for test #42
call scripts\gen-answer.bat tests\42 tests\42.a "tests" "5"
echo.
echo Generating answer for test #43
call scripts\gen-answer.bat tests\43 tests\43.a "tests" "6"
echo.
echo Generating answer for test #44
call scripts\gen-answer.bat tests\44 tests\44.a "tests" "6"
echo.
echo Generating answer for test #45
call scripts\gen-answer.bat tests\45 tests\45.a "tests" "6"
echo.
echo Generating answer for test #46
call scripts\gen-answer.bat tests\46 tests\46.a "tests" "6"
echo.
echo Generating answer for test #47
call scripts\gen-answer.bat tests\47 tests\47.a "tests" "6"
echo.
echo Generating answer for test #48
call scripts\gen-answer.bat tests\48 tests\48.a "tests" "6"
echo.
echo Generating answer for test #49
call scripts\gen-answer.bat tests\49 tests\49.a "tests" "6"
echo.
echo Generating answer for test #50
call scripts\gen-answer.bat tests\50 tests\50.a "tests" "6"
echo.
echo Generating answer for test #51
call scripts\gen-answer.bat tests\51 tests\51.a "tests" "6"
echo.

