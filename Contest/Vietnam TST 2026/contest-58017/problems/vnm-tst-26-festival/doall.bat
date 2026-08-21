rem   *** validation ***
call scripts\run-validator-tests.bat
call scripts\run-checker-tests.bat

rem    *** tests ***
md tests
call scripts\gen-input-via-stdout.bat "files\generator.exe mzbmweyydi --subtask 2 --testId 1 --N 197 --S 4 --flipped 0 --type layer" "tests\06" 6
call scripts\gen-input-via-stdout.bat "files\generator.exe uegmdbyfwu --subtask 2 --testId 2 --N 197 --S 17 --flipped 0 --type chain_layer" "tests\07" 7
call scripts\gen-input-via-stdout.bat "files\generator.exe vhifnuapwy --subtask 2 --testId 3 --N 195 --S 6 --flipped 0 --type chain_layer" "tests\08" 8
call scripts\gen-input-via-stdout.bat "files\generator.exe vkgkbhtyts --subtask 2 --testId 4 --N 190 --S 3 --flipped 0 --type layer" "tests\09" 9
call scripts\gen-input-via-stdout.bat "files\generator.exe egsjzzszfw --subtask 2 --testId 5 --N 193 --S 9 --flipped 0 --type chain_layer" "tests\10" 10
call scripts\gen-input-via-stdout.bat "files\generator.exe cguemwrczq --subtask 2 --testId 6 --N 200 --S 10 --flipped 0 --type chain" "tests\11" 11
call scripts\gen-input-via-stdout.bat "files\generator.exe qnkypnxnnp --subtask 2 --testId 7 --N 199 --S 11 --flipped 0 --type layer" "tests\12" 12
call scripts\gen-input-via-stdout.bat "files\generator.exe noaquudhav --subtask 2 --testId 8 --N 195 --S 3 --flipped 0 --type layer" "tests\13" 13
call scripts\gen-input-via-stdout.bat "files\generator.exe ujpcmiggjm --subtask 2 --testId 9 --N 199 --S 20 --flipped 0 --type chain_layer" "tests\14" 14
call scripts\gen-input-via-stdout.bat "files\generator.exe jfeodxkgjg --subtask 2 --testId 10 --N 190 --S 8 --flipped 0 --type chain_layer" "tests\15" 15
call scripts\gen-input-via-stdout.bat "files\generator.exe mzbmweyydi --subtask 3 --testId 1 --N 197 --S 2 --flipped 0 --type chain" "tests\16" 16
call scripts\gen-input-via-stdout.bat "files\generator.exe couegmdbyf --subtask 3 --testId 2 --N 198 --S 2 --flipped 0 --type chain_layer" "tests\17" 17
call scripts\gen-input-via-stdout.bat "files\generator.exe wbpuvhifnu --subtask 3 --testId 3 --N 190 --S 2 --flipped 0 --type chain_layer" "tests\18" 18
call scripts\gen-input-via-stdout.bat "files\generator.exe ndmhtqvkgk --subtask 3 --testId 4 --N 194 --S 2 --flipped 0 --type layer" "tests\19" 19
call scripts\gen-input-via-stdout.bat "files\generator.exe tszotwfleg --subtask 3 --testId 5 --N 198 --S 2 --flipped 0 --type chain" "tests\20" 20
call scripts\gen-input-via-stdout.bat "files\generator.exe szfwtzfpns --subtask 3 --testId 6 --N 199 --S 2 --flipped 0 --type chain_layer" "tests\21" 21
call scripts\gen-input-via-stdout.bat "files\generator.exe mwrczqxyci --subtask 3 --testId 7 --N 191 --S 2 --flipped 0 --type chain" "tests\22" 22
call scripts\gen-input-via-stdout.bat "files\generator.exe kypnxnnpmu --subtask 3 --testId 8 --N 192 --S 2 --flipped 0 --type layer" "tests\23" 23
call scripts\gen-input-via-stdout.bat "files\generator.exe noaquudhav --subtask 3 --testId 9 --N 195 --S 2 --flipped 1 --type chain_layer" "tests\24" 24
call scripts\gen-input-via-stdout.bat "files\generator.exe fwujpcmigg --subtask 3 --testId 10 --N 196 --S 2 --flipped 1 --type chain" "tests\25" 25
call scripts\gen-input-via-stdout.bat "files\generator.exe mzbmweyydi --subtask 4 --testId 1 --N 197 --S 4 --flipped 0 --type layer" "tests\26" 26
call scripts\gen-input-via-stdout.bat "files\generator.exe uegmdbyfwu --subtask 4 --testId 2 --N 197 --S 17 --flipped 0 --type chain_layer" "tests\27" 27
call scripts\gen-input-via-stdout.bat "files\generator.exe vhifnuapwy --subtask 4 --testId 3 --N 195 --S 6 --flipped 0 --type chain_layer" "tests\28" 28
call scripts\gen-input-via-stdout.bat "files\generator.exe vkgkbhtyts --subtask 4 --testId 4 --N 190 --S 3 --flipped 0 --type layer" "tests\29" 29
call scripts\gen-input-via-stdout.bat "files\generator.exe egsjzzszfw --subtask 4 --testId 5 --N 193 --S 9 --flipped 0 --type chain_layer" "tests\30" 30
call scripts\gen-input-via-stdout.bat "files\generator.exe cguemwrczq --subtask 4 --testId 6 --N 200 --S 10 --flipped 0 --type chain" "tests\31" 31
call scripts\gen-input-via-stdout.bat "files\generator.exe qnkypnxnnp --subtask 4 --testId 7 --N 199 --S 11 --flipped 0 --type layer" "tests\32" 32
call scripts\gen-input-via-stdout.bat "files\generator.exe noaquudhav --subtask 4 --testId 8 --N 195 --S 3 --flipped 0 --type layer" "tests\33" 33
call scripts\gen-input-via-stdout.bat "files\generator.exe ujpcmiggjm --subtask 4 --testId 9 --N 199 --S 20 --flipped 0 --type chain_layer" "tests\34" 34
call scripts\gen-input-via-stdout.bat "files\generator.exe jfeodxkgjg --subtask 4 --testId 10 --N 190 --S 8 --flipped 0 --type chain_layer" "tests\35" 35
call scripts\gen-input-via-stdout.bat "files\generator.exe ngiqquhuwq --subtask 4 --testId 11 --N 194 --S 5 --flipped 0 --type chain" "tests\36" 36
call scripts\gen-input-via-stdout.bat "files\generator.exe rxuzzfhkpl --subtask 4 --testId 12 --N 192 --S 19 --flipped 0 --type chain_layer" "tests\37" 37
call scripts\gen-input-via-stdout.bat "files\generator.exe ppcoildagk --subtask 4 --testId 13 --N 197 --S 11 --flipped 0 --type layer" "tests\38" 38
call scripts\gen-input-via-stdout.bat "files\generator.exe eusjuqfist --subtask 4 --testId 14 --N 194 --S 4 --flipped 0 --type chain" "tests\39" 39
call scripts\gen-input-via-stdout.bat "files\generator.exe wmfgzrnyxr --subtask 4 --testId 15 --N 190 --S 5 --flipped 0 --type layer" "tests\40" 40
call scripts\gen-input-via-stdout.bat "files\generator.exe lnfewczmno --subtask 4 --testId 16 --N 196 --S 15 --flipped 0 --type chain" "tests\41" 41
call scripts\gen-input-via-stdout.bat "files\generator.exe ugmdjwgzcf --subtask 4 --testId 17 --N 199 --S 17 --flipped 0 --type chain_layer" "tests\42" 42
call scripts\gen-input-via-stdout.bat "files\generator.exe yjxkatjmpp --subtask 4 --testId 18 --N 195 --S 15 --flipped 0 --type chain_layer" "tests\43" 43
call scripts\gen-input-via-stdout.bat "files\generator.exe obdagwdwxs --subtask 4 --testId 19 --N 197 --S 11 --flipped 0 --type chain_layer" "tests\44" 44
call scripts\gen-input-via-stdout.bat "files\generator.exe vncbszcepi --subtask 4 --testId 20 --N 195 --S 13 --flipped 1 --type chain_layer" "tests\45" 45
call scripts\gen-input-via-stdout.bat "files\generator.exe oootorzfsk --subtask 4 --testId 21 --N 196 --S 9 --flipped 1 --type layer" "tests\46" 46
call scripts\gen-input-via-stdout.bat "files\generator.exe vwdrmklfdc --subtask 4 --testId 22 --N 197 --S 4 --flipped 1 --type chain" "tests\47" 47
call scripts\gen-input-via-stdout.bat "files\generator.exe qdkelalxzx --subtask 4 --testId 23 --N 192 --S 23 --flipped 1 --type layer" "tests\48" 48
call scripts\gen-input-via-stdout.bat "files\generator.exe vpfpxabqln --subtask 4 --testId 24 --N 190 --S 7 --flipped 1 --type layer" "tests\49" 49
call scripts\gen-input-via-stdout.bat "files\generator.exe ntzamztvvc --subtask 4 --testId 25 --N 195 --S 8 --flipped 1 --type chain" "tests\50" 50
call scripts\gen-answer.bat tests\01 tests\01.a "tests" "subtask1"
call scripts\gen-answer.bat tests\02 tests\02.a "tests" "subtask1"
call scripts\gen-answer.bat tests\03 tests\03.a "tests" "subtask1"
call scripts\gen-answer.bat tests\04 tests\04.a "tests" "subtask1"
call scripts\gen-answer.bat tests\05 tests\05.a "tests" "subtask1"
call scripts\gen-answer.bat tests\06 tests\06.a "tests" "subtask2"
call scripts\gen-answer.bat tests\07 tests\07.a "tests" "subtask2"
call scripts\gen-answer.bat tests\08 tests\08.a "tests" "subtask2"
call scripts\gen-answer.bat tests\09 tests\09.a "tests" "subtask2"
call scripts\gen-answer.bat tests\10 tests\10.a "tests" "subtask2"
call scripts\gen-answer.bat tests\11 tests\11.a "tests" "subtask2"
call scripts\gen-answer.bat tests\12 tests\12.a "tests" "subtask2"
call scripts\gen-answer.bat tests\13 tests\13.a "tests" "subtask2"
call scripts\gen-answer.bat tests\14 tests\14.a "tests" "subtask2"
call scripts\gen-answer.bat tests\15 tests\15.a "tests" "subtask2"
call scripts\gen-answer.bat tests\16 tests\16.a "tests" "subtask3"
call scripts\gen-answer.bat tests\17 tests\17.a "tests" "subtask3"
call scripts\gen-answer.bat tests\18 tests\18.a "tests" "subtask3"
call scripts\gen-answer.bat tests\19 tests\19.a "tests" "subtask3"
call scripts\gen-answer.bat tests\20 tests\20.a "tests" "subtask3"
call scripts\gen-answer.bat tests\21 tests\21.a "tests" "subtask3"
call scripts\gen-answer.bat tests\22 tests\22.a "tests" "subtask3"
call scripts\gen-answer.bat tests\23 tests\23.a "tests" "subtask3"
call scripts\gen-answer.bat tests\24 tests\24.a "tests" "subtask3"
call scripts\gen-answer.bat tests\25 tests\25.a "tests" "subtask3"
call scripts\gen-answer.bat tests\26 tests\26.a "tests" "subtask4"
call scripts\gen-answer.bat tests\27 tests\27.a "tests" "subtask4"
call scripts\gen-answer.bat tests\28 tests\28.a "tests" "subtask4"
call scripts\gen-answer.bat tests\29 tests\29.a "tests" "subtask4"
call scripts\gen-answer.bat tests\30 tests\30.a "tests" "subtask4"
call scripts\gen-answer.bat tests\31 tests\31.a "tests" "subtask4"
call scripts\gen-answer.bat tests\32 tests\32.a "tests" "subtask4"
call scripts\gen-answer.bat tests\33 tests\33.a "tests" "subtask4"
call scripts\gen-answer.bat tests\34 tests\34.a "tests" "subtask4"
call scripts\gen-answer.bat tests\35 tests\35.a "tests" "subtask4"
call scripts\gen-answer.bat tests\36 tests\36.a "tests" "subtask4"
call scripts\gen-answer.bat tests\37 tests\37.a "tests" "subtask4"
call scripts\gen-answer.bat tests\38 tests\38.a "tests" "subtask4"
call scripts\gen-answer.bat tests\39 tests\39.a "tests" "subtask4"
call scripts\gen-answer.bat tests\40 tests\40.a "tests" "subtask4"
call scripts\gen-answer.bat tests\41 tests\41.a "tests" "subtask4"
call scripts\gen-answer.bat tests\42 tests\42.a "tests" "subtask4"
call scripts\gen-answer.bat tests\43 tests\43.a "tests" "subtask4"
call scripts\gen-answer.bat tests\44 tests\44.a "tests" "subtask4"
call scripts\gen-answer.bat tests\45 tests\45.a "tests" "subtask4"
call scripts\gen-answer.bat tests\46 tests\46.a "tests" "subtask4"
call scripts\gen-answer.bat tests\47 tests\47.a "tests" "subtask4"
call scripts\gen-answer.bat tests\48 tests\48.a "tests" "subtask4"
call scripts\gen-answer.bat tests\49 tests\49.a "tests" "subtask4"
call scripts\gen-answer.bat tests\50 tests\50.a "tests" "subtask4"

