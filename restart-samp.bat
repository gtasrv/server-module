@echo off
taskkill /f /im samp-server.exe >nul 2>&1
timeout /t 1 >nul
start "" "samp-server.exe"