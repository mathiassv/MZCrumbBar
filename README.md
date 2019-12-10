# MZCrumbBar
Windows MFC/C++ Crumbbar Controller

MFC Controller to shows items in a field that is clickable.
Can be a path or other items needed to be shown in a Crumbbar way

Can easily be inherited to customize style and usage

![Alt text](Doc/MZCrumbBar1.png?raw=true "Image from DemoApp")

# History

v1.5  2019-11-05<br/>
Published on GitHub<br/>
<br/>
v1.5  2012-05-03<br/>
The in-place edit controller caused a crash if it lost focus before it was completely created.<br/>
<br/>
v1.4  2011-02-25<br/>
Added CRect MZCrumbBar::GetItemRect (CrumbBarItem* pItemChosen) - Provided by Iain Clarke<br/>
<br/>
v1.3  2010-11-13<br/>
Added flag CRU_DONOTSTRIPDELIMITER that will keep the double delimiter. <br/>
Double delimiter are use to tell MZCrumbarCtrl that it should not break a path when it sees a delimiter.<br/>
eg  "Main-Sub-Sub--Menu" -> last item is normal shown as "Sub-Menu" but with this flag <br/>
it is shown as "Sub--Menu" since the double delimiter is not stripped<br/>
or for example "\\Server\Share\Folder" -> first item will now be shown as "\\Server" and not as "\Server"<br/>
<br/>
v1.2  2010-04-15<br/>
* Added improvements/fixes provided by Iain Clarke<br/>
* 3 more BuildCrumbbar(...) function for special situations.<br/>
* Refactored how a path is parsed.<br/>
* Added CRU_LASTITEMNODELIMITER. If style is set the Delimiter will not be shown for last crumbbar item.<br/>
* Style can now be set using styleEx.<br/>
* Change Default hot color to COLOR_HOTLIGHT<br/>
* Added possibility to store custom data in a Crumbbar item.<br/>
* Added SetItemData/GetItemData of custom data to crumbbar items.<br/>
* Fixed so that if double delimiter now works again. Double delimiter should be part of the crumbpath name, not a splitter.<br/>
* Change so that items are added to m_vCrumbItems via the virtual function AddCrumbItem(...)<br/>
* Fixed so that empty path parts are not added to the path.<br/>

v1.1  2010-03-17<br/>
First Public Version (Publish on CodePoject), Fixed minor draw issue<br/>
<br/>
v1.0  2009-10-10 <br/>
First Version<br/>
