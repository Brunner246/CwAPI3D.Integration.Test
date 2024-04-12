@echo off
setlocal

REM Set the source and destination paths
set "sourceFolder=C:\cadwork.dir\exe_30\3d.x64\Api\"
set "destinationFolder=%cd%\CwApi3d"
set "zipFileName=CwApi30.zip"
set "password=CadworkAPIv30"

REM Copy the zip folder to the destination
xcopy /s /y "%sourceFolder%\%zipFileName%" "%destinationFolder%"

REM Unzip the file with 7-Zip and provide the password
"C:\Program Files\7-Zip\7z.exe" x "%destinationFolder%\%zipFileName%" -o"%destinationFolder%" -p"%password%"

echo Done.
pause
