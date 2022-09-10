## Using...
- Visual Studio Community 2022
- Dialog boxes in C++ MFC



-------
There are two ways to make a calculator.
## 1
1. Select the "MFC App" template.
2. Type in the project name, then click "Create."
3. Select "Dialog based" for the application type, and click "Finish."
4. Operate the Local Windows Debugger to check there is no error.
5. Close the window that popped up and start to modify the dialog box.
6. Remove "ICD_STATIC1 (Text Control)."
7. Select the dialog box and increase the font size for easy accessibility. Then, adjust the dialog box size.
8. Add 3 Edit Controls and 1 Button, then arrange them to let the audience understand the function intuitively.
9. Select the three edit controls and set "center" for the text align in properties.
10. Select the button and change its caption to "+," which means "add."
11. Double-click the button to see the code of the .cpp file.
12. Add some code referring to the Cal1.cpp.
13. Check if the function works well with Local Windows Debugger.

## 2
Start with the state that finished step 10.
<ol start="11">
  <li>Choose an edit control, and right-click it. Then, in "Add variable," change to "value" for the category, change to "int" for the variable type, and name it as vA(: Value A).</li>
  <p>- If you set wrong, you can correct directly with Cal2Dlg.cpp file and Cal2Dlg.h file</p>
  <li>Do "Step 11" for each edit control.</li> 
  <li>Add some code referring to the Cal2.cpp.</li>
  <li>Check if the function works well with Local Windows Debugger.</li>
</ol>
