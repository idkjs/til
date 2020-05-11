class sample1 (x) = {
  as _;
  val mutable n = x;
  pub get_n = n;
  pub set_n = x => n = x;
  pub print = Printf.printf("%d\n", n);
};

class sample2 = {
  as _;
  pub print = Printf.printf("sample2");
};

class inherited (x) = {
  as _;
  /* 同名のメソッドを持つクラスを多重継承した場合後勝ち */
  /* スーパークラスの参照名を定義すればクラスを指定してメソッド呼び出し可能 */
  inherit (class sample1)(x) as super1;
  inherit class sample2;
  /* 本来sample2のprintがinheritedのprintメソッドになるが
     sample1のprintでオーバーライド */
  pub print = super1#print;
};

let () = {
  let inherited_class = (new inherited)(10);
  inherited_class#print;
  inherited_class#set_n(5);
  inherited_class#print;
};
