## Using...
- Visual Studio Community 2022
- Dialog boxes in C++ MFC



-------
### Requirements
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
Start with the state that finished step 6 of the guideline for Pen.
<ol start="7">
  <li>Add a Slider Control at the lower left. We will adjust the size of the ellipse with this slider.</li>
  <li>Choose the Slider Control, and right-click it. Then, in "Add variable," keep the category "control" and the variable type "CSliderCtrl," name it as sz_Slider(: Slider for sizing), and click "Finish."</li> 
  <li>Right-click the Slider Control again and click "Add Event Handler." Then, select "CEarthwormDlg" in the Class list, keep others(the message type must be "NM_CUSTOMDRAW"), and click "Ok."</li>
  <li>Add some code from the first part of Earthworm.cpp file in this folder to your EarthwormDlg.cpp file.</li>
  <li>Come back to the Earthworm.rc (Dialog file). Select the dialog box and click "Messages" in the properties window. Then, choose "<Add> OnMouseMove" in the combo box of "WM_MOUSEMOVE."</li>
  <li>Add some code, from the second part of Earthworm.cpp file in this folder, below the first part of your EarthwormDlg.cpp file.</li>
  <li>Check if the function works well with Local Windows Debugger.</li>
</ol>

  
## Customizable Pen
Start with the state that finished step 8 of the guideline for Earthworm.
<ol start="9">
  <li>Right-click the Slider Control again and click "Add Event Handler." Then, select "CCustomizablePenDlg" in the Class list, keep others(the message type must be "NM_CUSTOMDRAW"), and click "Ok."</li>
  <li>Add some code from the first part of Earthworm.cpp file in this folder to your "Customizable PenDlg.cpp" file.</li>
  <li>Come back to the "CustomizablePen.rc (Dialog)." Select the dialog box and click "Messages" in the properties window. Then, choose "<Add> OnMouseMove" in the combo box of "WM_MOUSEMOVE."</li>
  <li>Add some code, from the second part of "Customizable Pen.cpp" file in this folder, below the first part of your "Customizable PenDlg.cpp" file.</li>
  <li>Come back to the "CustomizablePen.rc (Dialog file)" and add a Button on the right of the slider. Then, select the button and change its caption to "Color."</li>
  <li>Double-click the button to see the code of the "Customizable Pen.cpp" file.</li>
  <li>Add some code, from the third part of "Customizable Pen.cpp" file in this folder, below the second part of your "Customizable PenDlg.cpp" file.</li>
  <li>Check if the function works well with Local Windows Debugger.</li>
</ol>
  
  
  

## +α How to make menus(Continued from step 16 of the guideline for Customizable Pen.
  1. To make menus, right-click the "Resource Files" folder on the "Solution Explorer". Then, click "Resource" among the "Add" options.
  2. Select "Menu" on the "Add Resource" window.
  3. In the "CustomizablePen.rc (Menu)," type "Size" and add "4," "8," and "16" as child items under "Size".
  4. In the "Customizable PenDlg.cpp" file, add some code from the fourth part of "Customizable Pen.cpp" file in this folder to the BEGIN/END_MESSAGE_MAP section.
  5. On the "Class View," right-click "CCustomizablePenDlg" and click the "Add Function" among "Add" options.
  6. Type the function name and set the Return type "void." Then, click "OK."
  7. Do "Step 6" for each function.
  8. Add some code, from the fifth part of "Customizable Pen.cpp" file in this folder, below the third part of your "Customizable PenDlg.cpp" file.
  9. Come back to the "CustomizablePen.rc (Dialog)." Select the dialog box and choose "IDR_MENU1" in the combo box of "Menu" under "Misc" category in the properties window.
  10. Check if the function works well with Local Windows Debugger.
  11. You can manage colors with menu by repeating Step 3-8.
    - You need to add menus by creating new category "Color" on the right of "Size."
    - You can add the code referring to the sixth part.
  
  
## Questions
  - How to update the window title when applying the menu function?
