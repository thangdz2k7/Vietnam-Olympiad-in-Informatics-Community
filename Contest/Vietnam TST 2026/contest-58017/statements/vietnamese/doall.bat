pushd ..\..\problems\vnm-tst-26-cstation\statements\vietnamese
for %%i in (*.mp) do (
	mpost %%i || goto error
)
del /F /Q *.log
popd

pushd ..\..\problems\vnm-tst-26-colorful\statements\vietnamese
for %%i in (*.mp) do (
	mpost %%i || goto error
)
del /F /Q *.log
popd

pushd ..\..\problems\vnm-tst-26-magician\statements\vietnamese
for %%i in (*.mp) do (
	mpost %%i || goto error
)
del /F /Q *.log
popd

pushd ..\..\problems\vnm-tst-26-sgame\statements\vietnamese
for %%i in (*.mp) do (
	mpost %%i || goto error
)
del /F /Q *.log
popd

pushd ..\..\problems\vnm-tst-26-vmachine\statements\vietnamese
for %%i in (*.mp) do (
	mpost %%i || goto error
)
del /F /Q *.log
popd

pushd ..\..\problems\vnm-tst-26-festival\statements\vietnamese
for %%i in (*.mp) do (
	mpost %%i || goto error
)
del /F /Q *.log
popd

latex statements.tex
latex statements.tex || goto error
dvips statements.dvi || goto error
dvipdfmx -p a4 statements.dvi || goto error

latex tutorials.tex
latex tutorials.tex || goto error
dvips tutorials.dvi || goto error
dvipdfmx -p a4 tutorials.dvi || goto error

del /F /Q *.log
del /F /Q *.aux
del /F /Q *.dvi
del /F /Q *.ps

goto ok

:error
echo [ERROR]: Can't compile/build statements/tutorials.
exit 1

:ok
echo [INFO]: Statements/tutorials have been compiled/build.
