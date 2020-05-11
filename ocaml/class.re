class stack_of_int = {
  as self;
  /* インスタンス変数 */
  val mutable list_: list(int) = [];
  pub push = x =>
    /* <- は割り当て演算子 */
    /* 変更可能なインスタンス変数の更新に用いる */
    list_ = [x, ...list_];
  pub pop = {
    let result = List.hd(list_);
    list_ = List.tl(list_);
    result;
  };
  pub peek = List.hd(list_);
  pub size = List.length(list_);
};

/* 任意の１つの型の要素を格納できるスタック */
class stack ('a) = {
  /* 実際には１つのクラスを定義しているのではなく、
     使用可能な型について全部のクラスのクラスを定義している */
  as self;
  val mutable list_: list('a) = [];
  pub push = x => list_ = [x, ...list_];
  pub pop = {
    let result = List.hd(list_);
    list_ = List.tl(list_);
    result;
  };
  pub peek = List.hd(list_);
  pub size = List.length(list_);
};

let () = {
  let s = new stack_of_int;
  for (i in 1 to 10) {
    s#push(i);
  };
  while (s#size > 0) {
    Printf.printf("Popped %d off from the stack_of_int\n", s#pop);
  };
  let s2 = new stack;
  s2#push(1.3);
  Printf.printf("%d\n", s2#size);
  Printf.printf("%F\n", s2#pop);
};
