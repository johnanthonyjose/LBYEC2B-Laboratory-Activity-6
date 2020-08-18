# Laboratory Actiivty 6 - UML Diagrams

## Online Shopping Inventory

You are provided with a working code for Tracking Inventory of products for online shop.

You are tasked now to draw its UML Class Diagram.

## How to Run the Program

1. Download this repository

   - Click on the "Code" Button, then click "Download Zip"
   - When the download is done, move the "Hangman-master" to your favorite directory.
   - Make sure to remember your favorite directory.

2. On Windows, open your Dev Cpp Project

   - Make sure to create Dev Cpp Project rather than just creating a new file
   - Navigate to the said directory on where you save "LBYEC2B-Laboratory-Activity-6-master"
   - That's where you will create your new project
   - Your Main File should be main.cpp

3. On MacOS, open your VSCode with CodeRunner
   - Press File > Open. Navigate to the folder on where you saved "LBYEC2B-Laboratory-Activity-6-master"
   - Afterwards, on the said folder, press open. Make sure that you can see ALL files on the left tab of the vscode.

### VSCode Code Runner Settings

If you are using VSCode with Code Runner plugin, there are some hacks created in this repository to make multiple cpp files work properly. If you follow the instructions above properly, the hacks will be automatically be applied on your PC.

Source: [compile multiple cpp files in vscode](https://stackoverflow.com/questions/59474537/code-runner-configuration-for-running-multiple-cpp-classes-in-vscode)

The code runner workspace settings is replaced from

```javascript
{
"cpp": "cd $dir && g++ -std=c++11 $fileName -o $fileNameWithoutExt && $dir$fileNameWithoutExt"
}
```

to

```javascript
"cpp": "cd $dir && g++ -std=c++11 *.cpp -o $fileNameWithoutExt && $dir$fileNameWithoutExt",
```
