echo [INFO]: Building problem 'vnm-tst-25-building'.
pushd problems\vnm-tst-25-building
call doall.bat
popd

echo [INFO]: Building problem 'vnm-tst-25-power'.
pushd problems\vnm-tst-25-power
call doall.bat
popd

echo [INFO]: Building problem 'vnm-tst-25-treasure'.
pushd problems\vnm-tst-25-treasure
call doall.bat
popd

echo [INFO]: Building problem 'vnm-tst-25-igraph'.
pushd problems\vnm-tst-25-igraph
call doall.bat
popd

echo [INFO]: Building problem 'vnm-tst-25-cpoint'.
pushd problems\vnm-tst-25-cpoint
call doall.bat
popd

echo [INFO]: Building problem 'vnm-tst-25-smatch'.
pushd problems\vnm-tst-25-smatch
call doall.bat
popd

echo [INFO]: Building vietnamese contest statement.
pushd statements\vietnamese
call doall.bat
popd

