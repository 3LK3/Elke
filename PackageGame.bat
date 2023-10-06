@echo off
pushd "%~dp0"

rem Command generated using the editor's project launcher. See https://docs.unrealengine.com/en-US/SharingAndReleasing/Deployment/ProjectLauncher
rem For arguments documentation see https://github.com/botman99/ue4-unreal-automation-tool.
rem Use `-nocompileeditor` for forcing the editor not to compile.
.\Engine\Build\BatchFiles\RunUAT.bat BuildCookRun -project=Elke.uproject -noP4 -clientconfig=Shipping -serverconfig=Shipping -nocompile -nocompileeditor -installed -unrealexe=F:\Programs\UE_5.3\Engine\Binaries\Win64\UnrealEditor-Cmd.exe -utf8output -platform=Win64 -build -cook -CookCultures=de+en -unversionedcookedcontent -distribution -prereqs -stage -package -stagingdirectory=./ReleaseBuilds -cmdline=" -Messaging" -addcmdline="-SessionId=E0197FF844710722BE59E2A8160FCB2E -SessionOwner='Soeren' -SessionName='Release'

popd