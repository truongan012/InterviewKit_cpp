Interview Preparation Kit
Language: C++
Editor: Visual Studio Code
==================================================
Configuration Tasks (tasks.json):
{
	"version": "2.0.0",
	"tasks": [
		{
			"type": "shell",
			"label": "shell: cl.exe build active file",
			"command": "cl.exe",
			"args": [
				"/Zi",
				"/EHsc",
				"/Fe:",
				"${workspaceFolder}\\bin\\HackerRankTest.exe",
				"/Fo:",
				"${workspaceFolder}\\bin\\HackerRankTest.obj",
				"/Fd:",
				"${workspaceFolder}\\bin\\HackerRankTest.pdb",
				"${file}"
			],
			"problemMatcher": [
				"$msCompile"
			],
			"group": {
				"kind": "build",
				"isDefault": true
			}
		}
	]
}

==================================================
Debug Tasks (launch.json):
{
    // Use IntelliSense to learn about possible attributes.
    // Hover to view descriptions of existing attributes.
    // For more information, visit: https://go.microsoft.com/fwlink/?linkid=830387
    "version": "0.2.0",
    "configurations": [
        {
            "name": "(Windows) Launch",
            "type": "cppvsdbg",
            "request": "launch",
            "program": "${workspaceFolder}\\bin\\HackerRankTest.exe",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "environment": [],
            "externalConsole": false,
            "preLaunchTask": "shell: cl.exe build active file"
        }
    ]
}