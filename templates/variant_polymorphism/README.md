# std::variantで静的多態性を行うサンプル
std::variantを使ってみたくなったので作ってみたサンプル  

Boost::Variantの時はstatic_visitorを使わないといけなかったので面倒だったのが、
c++17の力によりかなり簡単に書けるようになっていて感動  
※色々間違っているかもしれないので注意  

## メモ
VC2017 15.7でstd::variantを使うには`/std:c++latest`が必要  
→プロジェクトのプロパティ＞C/C++＞コマンドライン＞追加のオプション

std::visitにはファンクタでもラムダ式でも入る  

ちゃんとするならBaseが継承されているかどうかをチェックする必要がある  
https://qiita.com/Riyaaaa_a/items/887f6190e710c6410994

std::variantを使うよりもvectorにunique_ptrを入れる方が難しかった…   
https://stackoverflow.com/questions/3283778/why-can-i-not-push-back-a-unique-ptr-into-a-vector

## 参考
https://faithandbrave.hateblo.jp/entry/2016/08/02/164531
