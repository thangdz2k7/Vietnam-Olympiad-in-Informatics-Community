echo [INFO]: Building problem 'vnm-tst-26-cstation'.
pushd problems\vnm-tst-26-cstation
call doall.bat
popd

echo [INFO]: Building problem 'vnm-tst-26-colorful'.
pushd problems\vnm-tst-26-colorful
call doall.bat
popd

echo [INFO]: Building problem 'vnm-tst-26-magician'.
pushd problems\vnm-tst-26-magician
call doall.bat
popd

echo [INFO]: Building problem 'vnm-tst-26-sgame'.
pushd problems\vnm-tst-26-sgame
call doall.bat
popd

echo [INFO]: Building problem 'vnm-tst-26-vmachine'.
pushd problems\vnm-tst-26-vmachine
call doall.bat
popd

echo [INFO]: Building problem 'vnm-tst-26-festival'.
pushd problems\vnm-tst-26-festival
call doall.bat
popd

echo [INFO]: Building vietnamese contest statement.
pushd statements\vietnamese
call doall.bat
popd

