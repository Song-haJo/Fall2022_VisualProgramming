## Using...
- Visual Studio Community 2022
- Dialog boxes in C++ MFC



-------
## Requirements
- Green
- 8 px

## 1
1. Select the "MFC App" template.
2. Type in the project name, then click "Create."
3. Select "Dialog based" for the application type, and click "Finish."
4. Operate the Local Windows Debugger to check there is no error.
5. Close the window that popped up and start to modify the dialog box.
6. Remove "ICD_STATIC1 (Text Control)."
7. Select the dialog box and click "Messages" in properties. Then, choose "<Add> OnMouseMove" in the combo box of "WM_MOUSEMOVE".
8. Add some code referring to the Pen1.cpp.
9. Check if the function works well with Local Windows Debugger.

## 2
Start with the state that finished step 7.
<ol start="8">
  <li>Choose an edit control, and right-click it. Then, in "Add variable," change to "value" for the category, change to "CInt" for the variable type, and name it as aV.</li>
  <li>Do "Step 11" for each edit control.</li> 
  <li>Add some code referring to the Cal2.cpp.</li>
  <li>Check if the function works well with Local Windows Debugger.</li>
</ol>
