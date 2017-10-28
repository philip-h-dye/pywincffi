%WITH_COMPILER% %PYTHON%\Scripts\pip.exe install -r dev_requirements.txt --upgrade --quiet || EXIT 1
%WITH_COMPILER% %PYTHON%\Scripts\py.test.exe --strict --verbose --cov pywincffi --cov-report=xml || EXIT 1
%PYTHON%\Scripts\codecov.exe -X gcov -f coverage.xml --required || EXIT 1
