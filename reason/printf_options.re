/* string */

Printf.printf("%s\n", "string");

/* char */

Printf.printf("%c\n", 'c');

/* int */

Printf.printf("%d\n", 10);

/* float */

Printf.printf("%f", 9.912113);

Printf.printf("%.4f", 10.912113);

/*
 d、 i、 n、 l、 L、 N: 引数の整数を符号付き十進数に変換します。
 u: 引数の整数を符号なし十進数に変換します。
 x: 引数の整数を小文字の符号なし十六進数に変換します。
 X: 引数の整数を大文字の符号なし十六進数に変換します。
 o: 引数の整数を符号なし八進数に変換します。
 s: 引数文字列を挿入します。
 S: 引数文字列を Caml 構文で（二重引用符でくくり、エスケープして）挿入します。
 c: 引数文字を挿入します。
 C: 引数文字を Caml 構文で（単引用符でくくり、エスケープして）挿入します。
 f: 浮動小数点数引数を dddd.ddd 形式の十進表記に変換します。
 F: 浮動小数点数引数を dddd. か dddd.ddd か d.ddd e+-dd 形式の Caml 構文に変換します。
 e、 E: 浮動小数点数引数を d.ddd e+-dd （仮数部と指数部）形式の十進表記に変換します。
 g、 G: 浮動小数点数引数を f、 e、 E の形式のうち最も短かくなる形式に変換します。
 B: 真偽値の引数を文字列 true か false に変換します。
 b: 真偽値の引数を変換します（後方互換性のために残されています。新しいプログラムでは使わないでください）。
 ld、 li、 lu、 lx、 lX、 lo: int32 の引数を二文字目で表される形式（十進、十六進、……）に変換します。
 nd、 ni、 nu、 nx、 nX、 no: nativeint の引数を二文字目で表される形式に変換します。
 Ld、 Li、 Lu、 Lx、 LX、 Lo: int64 の引数を二文字目で表される形式に変換します
 a: ユーザー定義の表示器。書式指定としてはふたつの引数をとり、その第一引数に outchan （現在の出力チャネル）と第二引数を適用します。 第一引数はしたがって out_channel -> 'b -> unit 型で、第二引数は 'b 型でなければなりません。第一引数の出力が fprintf の現在の出力位置に挿入されます。
 t: %a と同じですが、引数として out_channel -> unit 型の引数だけを取り、それに outchan を適用します。
 { fmt %}: 書式指定文字列の変換。引数は fmt と同じ型を取る書式指定でなければなりません。
 ( fmt %): 書式指定文字列の置き換え。書式指定文字列を引数として受け取り、 fmt をそれで置き換えた上で残りの引数を出力します。引数は fmt と同じ型を取る書式指定でなければなりません。
 !: 引数を取らず、出力をフラッシュします。
 %: 引数を取らず、 % を出力します。
 ,: 変換指定子を区切るためだけに使い、何も出力しません。
 */
