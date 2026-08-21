#!/usr/bin/env bash
#   *** validation ***
scripts/run-validator-tests.sh
scripts/run-checker-tests.sh

#    *** tests ***
mkdir -p tests
echo "Generating test #6"
scripts/gen-input-via-stdout.sh "wine files/generator.exe '--testId' '1' '--subtask' '2' '--tree' 'line' '--light' 'on' '--flipped' '0' '--adaptive' '0' '--RATE_N' '0.975876' '--RATE_A' '0.230792' '--RATE_B' '0.502324' 'dtlcouegmd'" "tests/06" 6
echo "Generating test #7"
scripts/gen-input-via-stdout.sh "wine files/generator.exe '--testId' '2' '--subtask' '2' '--tree' 'line' '--light' 'on' '--flipped' '0' '--adaptive' '0' '--RATE_N' '0.966524' '--RATE_A' '0.795679' '--RATE_B' '0.64121' 'hifnuapwyn'" "tests/07" 7
echo "Generating test #8"
scripts/gen-input-via-stdout.sh "wine files/generator.exe '--testId' '3' '--subtask' '2' '--tree' 'line' '--light' 'on' '--flipped' '0' '--adaptive' '0' '--RATE_N' '0.950467' '--RATE_A' '0.0326184' '--RATE_B' '0.652001' 'ytszotwfle'" "tests/08" 8
echo "Generating test #9"
scripts/gen-input-via-stdout.sh "wine files/generator.exe '--testId' '4' '--subtask' '2' '--tree' 'line' '--light' 'off' '--flipped' '0' '--adaptive' '1' '--RATE_N' '0.910196' '--RATE_A' '0.757407' '--RATE_B' '0.166499' 'pnscguemwr'" "tests/09" 9
echo "Generating test #10"
scripts/gen-input-via-stdout.sh "wine files/generator.exe '--testId' '5' '--subtask' '2' '--tree' 'line' '--light' 'hard' '--flipped' '0' '--adaptive' '1' '--RATE_N' '0.916835' '--RATE_A' '0.674214' '--RATE_B' '0.512528' 'ypnxnnpmud'" "tests/10" 10
echo "Generating test #11"
scripts/gen-input-via-stdout.sh "wine files/generator.exe '--testId' '1' '--subtask' '3' '--tree' 'line' '--light' 'on' '--flipped' '0' '--adaptive' '1' '--RATE_N' '0.986011' '--RATE_A' '0.578466' '--RATE_B' '0.224957' 'tlcouegmdb'" "tests/11" 11
echo "Generating test #12"
scripts/gen-input-via-stdout.sh "wine files/generator.exe '--testId' '2' '--subtask' '3' '--tree' 'full_binary' '--light' 'off' '--flipped' '0' '--adaptive' '0' '--RATE_N' '0.966524' '--RATE_A' '0.64121' '--RATE_B' '0.675651' 'fnuapwyndm'" "tests/12" 12
echo "Generating test #13"
scripts/gen-input-via-stdout.sh "wine files/generator.exe '--testId' '3' '--subtask' '3' '--tree' 'random' '--light' 'random' '--flipped' '0' '--adaptive' '1' '--RATE_N' '0.947274' '--RATE_A' '0.209398' '--RATE_B' '0.133804' 'zotwflegsj'" "tests/13" 13
echo "Generating test #14"
scripts/gen-input-via-stdout.sh "wine files/generator.exe '--testId' '4' '--subtask' '3' '--tree' 'binary' '--light' 'hard' '--flipped' '0' '--adaptive' '1' '--RATE_N' '0.951481' '--RATE_A' '0.559081' '--RATE_B' '0.295375' 'guemwrczqx'" "tests/14" 14
echo "Generating test #15"
scripts/gen-input-via-stdout.sh "wine files/generator.exe '--testId' '5' '--subtask' '3' '--tree' 'recur' '--light' 'hard' '--flipped' '0' '--adaptive' '1' '--RATE_N' '0.924598' '--RATE_A' '0.209835' '--RATE_B' '0.497287' 'npmuduhzno'" "tests/15" 15
echo "Generating test #16"
scripts/gen-input-via-stdout.sh "wine files/generator.exe '--testId' '32' '--subtask' '3' '--tree' 'line' '--light' 'hard' '--flipped' '0' '--adaptive' '0' '--RATE_N' '0.996222' '--RATE_A' '0.00257379' '--RATE_B' '0.645397' 'mkxhaiafmv'" "tests/16" 16
echo "Generating test #17"
scripts/gen-input-via-stdout.sh "wine files/generator.exe '--testId' '92' '--subtask' '3' '--tree' 'line' '--light' 'hard' '--flipped' '1' '--adaptive' '0' '--RATE_N' '0.975488' '--RATE_A' '0.440391' '--RATE_B' '0.945274' 'vysyvgxlsp'" "tests/17" 17
echo "Generating test #18"
scripts/gen-input-via-stdout.sh "wine files/generator.exe '--testId' '100' '--subtask' '3' '--tree' 'line' '--light' 'hard' '--flipped' '1' '--adaptive' '0' '--RATE_N' '0.967187' '--RATE_A' '0.540539' '--RATE_B' '0.819906' 'ivtmpqzqts'" "tests/18" 18
echo "Generating test #19"
scripts/gen-input-via-stdout.sh "wine files/generator.exe '--testId' '101' '--subtask' '3' '--tree' 'line' '--light' 'hard' '--flipped' '1' '--adaptive' '0' '--RATE_N' '0.915483' '--RATE_A' '0.374358' '--RATE_B' '0.333928' 'saxgmoywdg'" "tests/19" 19
echo "Generating test #20"
scripts/gen-input-via-stdout.sh "wine files/generator.exe '--testId' '136' '--subtask' '3' '--tree' 'line' '--light' 'hard' '--flipped' '1' '--adaptive' '0' '--RATE_N' '0.985886' '--RATE_A' '0.00496638' '--RATE_B' '0.556973' 'hjsdaskqgl'" "tests/20" 20
echo "Generating test #21"
scripts/gen-input-via-stdout.sh "wine files/generator.exe '--testId' '153' '--subtask' '3' '--tree' 'line' '--light' 'hard' '--flipped' '0' '--adaptive' '0' '--RATE_N' '0.838661' '--RATE_A' '0.0723091' '--RATE_B' '0.300094' 'jzjmmyfmvx'" "tests/21" 21
echo "Generating test #22"
scripts/gen-input-via-stdout.sh "wine files/generator.exe '--testId' '245' '--subtask' '3' '--tree' 'recur' '--light' 'hard' '--flipped' '0' '--adaptive' '0' '--RATE_N' '0.968545' '--RATE_A' '0.821319' '--RATE_B' '0.260035' 'fewczmnooz'" "tests/22" 22
echo "Generating test #23"
scripts/gen-input-via-stdout.sh "wine files/generator.exe '--testId' '155' '--subtask' '3' '--tree' 'recur' '--light' 'hard' '--flipped' '0' '--adaptive' '0' '--RATE_N' '0.966524' '--RATE_A' '0.64121' '--RATE_B' '0.675651' 'fnuapwyndm'" "tests/23" 23
echo "Generating test #24"
scripts/gen-input-via-stdout.sh "wine files/generator.exe '--testId' '166' '--subtask' '3' '--tree' 'full_binary' '--light' 'hard' '--flipped' '0' '--adaptive' '0' '--RATE_N' '0.832581' '--RATE_A' '0.75443' '--RATE_B' '0.554794' 'obdagwdwxs'" "tests/24" 24
echo "Generating test #25"
scripts/gen-input-via-stdout.sh "wine files/generator.exe '--testId' '180' '--subtask' '3' '--tree' 'recur' '--light' 'hard' '--flipped' '0' '--adaptive' '0' '--RATE_N' '0.916028' '--RATE_A' '0.287688' '--RATE_B' '0.062487' 'xouyfjhnwp'" "tests/25" 25
echo "Generating test #26"
scripts/gen-input-via-stdout.sh "wine files/generator.exe '--testId' '222' '--subtask' '3' '--tree' 'line' '--light' 'hard' '--flipped' '0' '--adaptive' '0' '--RATE_N' '0.857412' '--RATE_A' '0.650376' '--RATE_B' '0.135021' 'alxzxillkf'" "tests/26" 26
echo "Generating test #27"
scripts/gen-input-via-stdout.sh "wine files/generator.exe '--testId' '234' '--subtask' '3' '--tree' 'full_binary' '--light' 'hard' '--flipped' '0' '--adaptive' '0' '--RATE_N' '0.916589' '--RATE_A' '0.640868' '--RATE_B' '0.243973' 'blpncetyht'" "tests/27" 27
echo "Generating test #28"
scripts/gen-input-via-stdout.sh "wine files/generator.exe '--testId' '164' '--subtask' '3' '--tree' 'recur' '--light' 'hard' '--flipped' '0' '--adaptive' '0' '--RATE_N' '0.968545' '--RATE_A' '0.821319' '--RATE_B' '0.260035' 'fewczmnooz'" "tests/28" 28
echo "Generating test #29"
scripts/gen-input-via-stdout.sh "wine files/generator.exe '--testId' '174' '--subtask' '3' '--tree' 'full_binary' '--light' 'hard' '--flipped' '0' '--adaptive' '0' '--RATE_N' '0.82514' '--RATE_A' '0.923124' '--RATE_B' '0.25026' 'ildlrkjoyr'" "tests/29" 29
echo "Generating test #30"
scripts/gen-input-via-stdout.sh "wine files/generator.exe '--testId' '179' '--subtask' '3' '--tree' 'full_binary' '--light' 'hard' '--flipped' '0' '--adaptive' '0' '--RATE_N' '0.901695' '--RATE_A' '0.0271911' '--RATE_B' '0.638725' 'swvtxganww'" "tests/30" 30
echo "Generating test #31"
scripts/gen-input-via-stdout.sh "wine files/generator.exe '--testId' '195' '--subtask' '3' '--tree' 'line' '--light' 'hard' '--flipped' '0' '--adaptive' '0' '--RATE_N' '0.857412' '--RATE_A' '0.650376' '--RATE_B' '0.135021' 'alxzxillkf'" "tests/31" 31
echo "Generating test #32"
scripts/gen-input-via-stdout.sh "wine files/generator.exe '--testId' '207' '--subtask' '3' '--tree' 'full_binary' '--light' 'hard' '--flipped' '0' '--adaptive' '0' '--RATE_N' '0.916589' '--RATE_A' '0.640868' '--RATE_B' '0.243973' 'blpncetyht'" "tests/32" 32
echo "Generating test #33"
scripts/gen-input-via-stdout.sh "wine files/generator.exe '--testId' '415' '--subtask' '3' '--tree' 'line' '--light' 'hard' '--flipped' '0' '--adaptive' '0' '--RATE_N' '0.857412' '--RATE_A' '0.650376' '--RATE_B' '0.135021' 'alxzxillkf'" "tests/33" 33
echo "Generating test #34"
scripts/gen-input-via-stdout.sh "wine files/generator.exe '--testId' '596' '--subtask' '3' '--tree' 'recur' '--light' 'hard' '--flipped' '1' '--adaptive' '0' '--RATE_N' '0.993476' '--RATE_A' '0.736505' '--RATE_B' '0.84064' 'rigjjtthzh'" "tests/34" 34
echo "Generating test #35"
scripts/gen-input-via-stdout.sh "wine files/generator.exe '--testId' '618' '--subtask' '3' '--tree' 'line' '--light' 'hard' '--flipped' '0' '--adaptive' '0' '--RATE_N' '0.994096' '--RATE_A' '0.400066' '--RATE_B' '0.985179' 'kwgtxnqxmu'" "tests/35" 35
echo "Generating test #36"
scripts/gen-input-via-stdout.sh "wine files/generator.exe '--testId' '635' '--subtask' '3' '--tree' 'recur' '--light' 'hard' '--flipped' '1' '--adaptive' '0' '--RATE_N' '0.941038' '--RATE_A' '0.11479' '--RATE_B' '0.142708' 'vzpqbxcqos'" "tests/36" 36
echo "Generating test #37"
scripts/gen-input-via-stdout.sh "wine files/generator.exe '--testId' '725' '--subtask' '3' '--tree' 'recur' '--light' 'hard' '--flipped' '1' '--adaptive' '0' '--RATE_N' '0.989666' '--RATE_A' '0.903665' '--RATE_B' '0.695118' 'qjokvncect'" "tests/37" 37
echo "Generating test #38"
scripts/gen-input-via-stdout.sh "wine files/generator.exe '--testId' '790' '--subtask' '3' '--tree' 'recur' '--light' 'hard' '--flipped' '0' '--adaptive' '0' '--RATE_N' '0.979875' '--RATE_A' '0.342412' '--RATE_B' '0.370096' 'dluubvwspa'" "tests/38" 38
echo "Generating test #39"
scripts/gen-input-via-stdout.sh "wine files/generator.exe '--testId' '851' '--subtask' '3' '--tree' 'recur' '--light' 'hard' '--flipped' '0' '--adaptive' '0' '--RATE_N' '0.932199' '--RATE_A' '0.468656' '--RATE_B' '0.813694' 'ejcjnoyvyr'" "tests/39" 39
echo "Generating test #40"
scripts/gen-input-via-stdout.sh "wine files/generator.exe '--testId' '864' '--subtask' '3' '--tree' 'recur' '--light' 'hard' '--flipped' '1' '--adaptive' '0' '--RATE_N' '0.872138' '--RATE_A' '0.466525' '--RATE_B' '0.438636' 'yqqdffioag'" "tests/40" 40
echo "Generating test #41"
scripts/gen-input-via-stdout.sh "wine files/generator.exe '--testId' '875' '--subtask' '3' '--tree' 'line' '--light' 'hard' '--flipped' '0' '--adaptive' '0' '--RATE_N' '0.825058' '--RATE_A' '0.214113' '--RATE_B' '0.519129' 'bntnumomgz'" "tests/41" 41
echo "Generating test #42"
scripts/gen-input-via-stdout.sh "wine files/generator.exe '--testId' '912' '--subtask' '3' '--tree' 'recur' '--light' 'hard' '--flipped' '1' '--adaptive' '0' '--RATE_N' '0.991776' '--RATE_A' '0.775066' '--RATE_B' '0.0967002' 'botkziuttj'" "tests/42" 42
echo "Generating test #43"
scripts/gen-input-via-stdout.sh "wine files/generator.exe '--testId' '928' '--subtask' '3' '--tree' 'line' '--light' 'hard' '--flipped' '0' '--adaptive' '0' '--RATE_N' '0.918711' '--RATE_A' '0.774512' '--RATE_B' '0.933941' 'etglthgour'" "tests/43" 43
echo "Generating test #44"
scripts/gen-input-via-stdout.sh "wine files/generator.exe '--testId' '955' '--subtask' '3' '--tree' 'line' '--light' 'hard' '--flipped' '0' '--adaptive' '0' '--RATE_N' '0.932259' '--RATE_A' '0.777408' '--RATE_B' '0.488206' 'kdgbrrkxwq'" "tests/44" 44
echo "Generating test #45"
scripts/gen-input-via-stdout.sh "wine files/generator.exe '--testId' '1046' '--subtask' '3' '--tree' 'recur' '--light' 'hard' '--flipped' '1' '--adaptive' '0' '--RATE_N' '1' '--RATE_A' '0.657886' '--RATE_B' '0.350796' 'ivudydgxws'" "tests/45" 45
echo "Generating test #46"
scripts/gen-input-via-stdout.sh "wine files/generator.exe '--testId' '1082' '--subtask' '3' '--tree' 'recur' '--light' 'hard' '--flipped' '1' '--adaptive' '0' '--RATE_N' '1' '--RATE_A' '0.999328' '--RATE_B' '0.016311' 'ouylqobsge'" "tests/46" 46
echo "Generating test #47"
scripts/gen-input-via-stdout.sh "wine files/generator.exe '--testId' '1244' '--subtask' '3' '--tree' 'recur' '--light' 'hard' '--flipped' '0' '--adaptive' '0' '--RATE_N' '1' '--RATE_A' '0.256854' '--RATE_B' '0.976298' 'gzwyfgdcbk'" "tests/47" 47
echo "Generating test #48"
scripts/gen-input-via-stdout.sh "wine files/generator.exe '--testId' '1265' '--subtask' '3' '--tree' 'recur' '--light' 'hard' '--flipped' '1' '--adaptive' '0' '--RATE_N' '1' '--RATE_A' '0.739567' '--RATE_B' '0.240359' 'whlwdygnno'" "tests/48" 48
echo "Generating test #49"
scripts/gen-input-via-stdout.sh "wine files/generator.exe '--testId' '1350' '--subtask' '3' '--tree' 'recur' '--light' 'hard' '--flipped' '1' '--adaptive' '0' '--RATE_N' '1' '--RATE_A' '0.203263' '--RATE_B' '0.758615' 'wzeualgfdm'" "tests/49" 49
echo "Generating test #50"
scripts/gen-input-via-stdout.sh "wine files/generator.exe '--testId' '1547' '--subtask' '3' '--tree' 'recur' '--light' 'hard' '--flipped' '1' '--adaptive' '0' '--RATE_N' '1' '--RATE_A' '0.690059' '--RATE_B' '0.828089' 'lltgafhvlc'" "tests/50" 50
echo ""
echo "Generating answer for test #1"
scripts/gen-answer.sh tests/01 tests/01.a "tests" "subtask1"
echo ""
echo "Generating answer for test #2"
scripts/gen-answer.sh tests/02 tests/02.a "tests" "subtask1"
echo ""
echo "Generating answer for test #3"
scripts/gen-answer.sh tests/03 tests/03.a "tests" "subtask1"
echo ""
echo "Generating answer for test #4"
scripts/gen-answer.sh tests/04 tests/04.a "tests" "subtask1"
echo ""
echo "Generating answer for test #5"
scripts/gen-answer.sh tests/05 tests/05.a "tests" "subtask1"
echo ""
echo "Generating answer for test #6"
scripts/gen-answer.sh tests/06 tests/06.a "tests" "subtask2"
echo ""
echo "Generating answer for test #7"
scripts/gen-answer.sh tests/07 tests/07.a "tests" "subtask2"
echo ""
echo "Generating answer for test #8"
scripts/gen-answer.sh tests/08 tests/08.a "tests" "subtask2"
echo ""
echo "Generating answer for test #9"
scripts/gen-answer.sh tests/09 tests/09.a "tests" "subtask2"
echo ""
echo "Generating answer for test #10"
scripts/gen-answer.sh tests/10 tests/10.a "tests" "subtask2"
echo ""
echo "Generating answer for test #11"
scripts/gen-answer.sh tests/11 tests/11.a "tests" "subtask3"
echo ""
echo "Generating answer for test #12"
scripts/gen-answer.sh tests/12 tests/12.a "tests" "subtask3"
echo ""
echo "Generating answer for test #13"
scripts/gen-answer.sh tests/13 tests/13.a "tests" "subtask3"
echo ""
echo "Generating answer for test #14"
scripts/gen-answer.sh tests/14 tests/14.a "tests" "subtask3"
echo ""
echo "Generating answer for test #15"
scripts/gen-answer.sh tests/15 tests/15.a "tests" "subtask3"
echo ""
echo "Generating answer for test #16"
scripts/gen-answer.sh tests/16 tests/16.a "tests" "subtask3"
echo ""
echo "Generating answer for test #17"
scripts/gen-answer.sh tests/17 tests/17.a "tests" "subtask3"
echo ""
echo "Generating answer for test #18"
scripts/gen-answer.sh tests/18 tests/18.a "tests" "subtask3"
echo ""
echo "Generating answer for test #19"
scripts/gen-answer.sh tests/19 tests/19.a "tests" "subtask3"
echo ""
echo "Generating answer for test #20"
scripts/gen-answer.sh tests/20 tests/20.a "tests" "subtask3"
echo ""
echo "Generating answer for test #21"
scripts/gen-answer.sh tests/21 tests/21.a "tests" "subtask3"
echo ""
echo "Generating answer for test #22"
scripts/gen-answer.sh tests/22 tests/22.a "tests" "subtask3"
echo ""
echo "Generating answer for test #23"
scripts/gen-answer.sh tests/23 tests/23.a "tests" "subtask3"
echo ""
echo "Generating answer for test #24"
scripts/gen-answer.sh tests/24 tests/24.a "tests" "subtask3"
echo ""
echo "Generating answer for test #25"
scripts/gen-answer.sh tests/25 tests/25.a "tests" "subtask3"
echo ""
echo "Generating answer for test #26"
scripts/gen-answer.sh tests/26 tests/26.a "tests" "subtask3"
echo ""
echo "Generating answer for test #27"
scripts/gen-answer.sh tests/27 tests/27.a "tests" "subtask3"
echo ""
echo "Generating answer for test #28"
scripts/gen-answer.sh tests/28 tests/28.a "tests" "subtask3"
echo ""
echo "Generating answer for test #29"
scripts/gen-answer.sh tests/29 tests/29.a "tests" "subtask3"
echo ""
echo "Generating answer for test #30"
scripts/gen-answer.sh tests/30 tests/30.a "tests" "subtask3"
echo ""
echo "Generating answer for test #31"
scripts/gen-answer.sh tests/31 tests/31.a "tests" "subtask3"
echo ""
echo "Generating answer for test #32"
scripts/gen-answer.sh tests/32 tests/32.a "tests" "subtask3"
echo ""
echo "Generating answer for test #33"
scripts/gen-answer.sh tests/33 tests/33.a "tests" "subtask3"
echo ""
echo "Generating answer for test #34"
scripts/gen-answer.sh tests/34 tests/34.a "tests" "subtask3"
echo ""
echo "Generating answer for test #35"
scripts/gen-answer.sh tests/35 tests/35.a "tests" "subtask3"
echo ""
echo "Generating answer for test #36"
scripts/gen-answer.sh tests/36 tests/36.a "tests" "subtask3"
echo ""
echo "Generating answer for test #37"
scripts/gen-answer.sh tests/37 tests/37.a "tests" "subtask3"
echo ""
echo "Generating answer for test #38"
scripts/gen-answer.sh tests/38 tests/38.a "tests" "subtask3"
echo ""
echo "Generating answer for test #39"
scripts/gen-answer.sh tests/39 tests/39.a "tests" "subtask3"
echo ""
echo "Generating answer for test #40"
scripts/gen-answer.sh tests/40 tests/40.a "tests" "subtask3"
echo ""
echo "Generating answer for test #41"
scripts/gen-answer.sh tests/41 tests/41.a "tests" "subtask3"
echo ""
echo "Generating answer for test #42"
scripts/gen-answer.sh tests/42 tests/42.a "tests" "subtask3"
echo ""
echo "Generating answer for test #43"
scripts/gen-answer.sh tests/43 tests/43.a "tests" "subtask3"
echo ""
echo "Generating answer for test #44"
scripts/gen-answer.sh tests/44 tests/44.a "tests" "subtask3"
echo ""
echo "Generating answer for test #45"
scripts/gen-answer.sh tests/45 tests/45.a "tests" "subtask3"
echo ""
echo "Generating answer for test #46"
scripts/gen-answer.sh tests/46 tests/46.a "tests" "subtask3"
echo ""
echo "Generating answer for test #47"
scripts/gen-answer.sh tests/47 tests/47.a "tests" "subtask3"
echo ""
echo "Generating answer for test #48"
scripts/gen-answer.sh tests/48 tests/48.a "tests" "subtask3"
echo ""
echo "Generating answer for test #49"
scripts/gen-answer.sh tests/49 tests/49.a "tests" "subtask3"
echo ""
echo "Generating answer for test #50"
scripts/gen-answer.sh tests/50 tests/50.a "tests" "subtask3"
echo ""

