cd ../../problems/vnm-tst-26-cstation/statements/vietnamese
for file in ./*.mp
do
    [ -e $file ] && mpost $file
done
rm -f *.log
cd -

cd ../../problems/vnm-tst-26-colorful/statements/vietnamese
for file in ./*.mp
do
    [ -e $file ] && mpost $file
done
rm -f *.log
cd -

cd ../../problems/vnm-tst-26-magician/statements/vietnamese
for file in ./*.mp
do
    [ -e $file ] && mpost $file
done
rm -f *.log
cd -

cd ../../problems/vnm-tst-26-sgame/statements/vietnamese
for file in ./*.mp
do
    [ -e $file ] && mpost $file
done
rm -f *.log
cd -

cd ../../problems/vnm-tst-26-vmachine/statements/vietnamese
for file in ./*.mp
do
    [ -e $file ] && mpost $file
done
rm -f *.log
cd -

cd ../../problems/vnm-tst-26-festival/statements/vietnamese
for file in ./*.mp
do
    [ -e $file ] && mpost $file
done
rm -f *.log
cd -

latex statements.tex
latex statements.tex
dvips statements.dvi
dvipdfmx -p a4 statements.dvi
latex tutorials.tex
latex tutorials.tex
dvips tutorials.dvi
dvipdfmx -p a4 tutorials.dvi
rm -f *.log
rm -f *.aux
rm -f *.dvi
rm -f *.ps
