# Code Runner

Please fix the configuration

[compile multiple cpp files in vscode](https://stackoverflow.com/questions/59474537/code-runner-configuration-for-running-multiple-cpp-classes-in-vscode)

Look for cpp
Make sure to replace it from

```javascript
{
"cpp": "cd $dir && g++ -std=c++11 $fileName -o $fileNameWithoutExt && $dir$fileNameWithoutExt"
}
```

to

```javascript
"cpp": "cd $dir && g++ -std=c++11 *.cpp -o $fileNameWithoutExt && $dir$fileNameWithoutExt",
```
