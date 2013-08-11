@echo off
cls

set root=E:\Projects\c++\GarrysMod\gm_io
set project=%root%\project\windows\vs2010
set compiler=C:\Program Files (x86)\Microsoft Visual Studio 10.0\VC

cd "%root%"
premake4 --os=windows --platform=x32 --file=premake.lua vs2010

call "%compiler%/vcvarsall.bat" x86

cd "%project%"
devenv "%project%/io.sln" /rebuild "release|Win32"