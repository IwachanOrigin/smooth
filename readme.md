
# smooth
画像を読み込み、RGB値を取得し、任意の比率を使用して平滑化を行います。  
入力画像と比べてみると、画像全体がぼやけているような効果を見ることができます。  
画像読み込み、GUIにはQtを使用しています。  

## Demo
元の画像  
![base](https://user-images.githubusercontent.com/12496951/185798199-e1fdbef6-7e07-483f-8d68-1260fdd723f0.PNG)  

平滑化  
![smooth](https://user-images.githubusercontent.com/12496951/185798203-367f2630-0cd4-4d2b-a59f-b6ac7cfc51e7.PNG)  

## Dependency
- MSVC 15+  
- Qt 5.13.1

## Build
CMakeLists.txtではQTDIRを環境変数から取得して使用しています。  
また、ここではWSL2とPowerShell、CMakeを使用したビルド方法を記述します。  
CMakeは環境変数のPATHへ追加しています。  

1. このリポジトリをクローンします。  
2. 以下のコマンドでビルドします。  
   ex. VS2017 の場合  
   powershell.exe cmake -S . -B build -G "\\"Visual Studio 15 2017 Win64\\""  
   powershell.exe cmake --build build  

   ex. VS2019以上の場合  
   powershell.exe cmake -S . -B build  
   powershell.exe cmake --build build  

3. 実行時に必要なDLL群はコピーしていません。実行の際には注意してください。


## License
This software is released under the MIT License, see LICENSE.

## References
[C言語で学ぶ実践CG・映像合成](https://www.ohmsha.co.jp/book/9784274500169/)  
[コンピュータ画像処理(改訂2版)](https://www.ohmsha.co.jp/book/9784274228193/)  
[ベッドの下で元カノの帰りを待っていたストーカー化する元カレの写真素材](https://www.pakutaso.com/20160432099post-7538.html)
