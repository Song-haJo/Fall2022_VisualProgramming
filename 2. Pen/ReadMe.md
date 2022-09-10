## Using...
- Visual Studio Community 2022
- Dialog boxes in C++ MFC



-------
## Requirements
- Green
- 8 px

## Pen
1. Select the "MFC App" template.
2. Type in the project name, then click "Create."
3. Select "Dialog based" for the application type, and click "Finish."
4. Operate the Local Windows Debugger to check there is no error.
5. Close the window that popped up and start to modify the dialog box.
6. Remove "ICD_STATIC1 (Text Control)."
7. Select the dialog box and click "Messages" in properties. Then, choose "<Add> OnMouseMove" in the combo box of "WM_MOUSEMOVE."
8. Add some code referring to the Pen1.cpp.
9. Check if the function works well with Local Windows Debugger.

## Earthworm
Start with the state that finished step 6.
<ol start="7">
  <li>Add 1 Slider Control at lower left. We will adjust the size of the ellipse with this slider.</li>
  <li>Choose the Slider Control, and right-click it. Then, in "Add variable," keep the category "control" and the variable type "CSliderCtrl," name it as sz_Slider(: Slider for sizing), and click "Finish."</li> 
  <li>Right-click the Slider Control again and click "Add Event Handler." Then, select "CEarthwormDlg" in the Class list, keep others, and click "Ok."</li>
  <li>Check if the function works well with Local Windows Debugger.</li>
</ol>
