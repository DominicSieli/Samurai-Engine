@echo off
call Utilities\premake\premake5.exe vs2019
IF %ERRORLEVEL% NEQ 0
(
  PAUSE
)