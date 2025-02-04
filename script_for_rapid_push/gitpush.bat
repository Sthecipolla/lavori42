@echo off
echo Starting Git Rapid Push...

REM Navigate to the repository (Change to your repo path)
cd /d "C:\Users\himal\OneDrive\Desktop\lavori42"

REM Add all changes
git add *

REM Commit with a predefined message
git commit -m "rapid push"

REM Push to the remote repository
git push

echo Git push completed!
pause
