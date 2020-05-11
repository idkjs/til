open Core;

/* 型変数を使用した任意の型の値を格納できるスタッククラス */
class stack ('a) = {
  as self;
  val mutable stack: list('a) = [];
  pub push = x => stack = [x, ...stack];
  pub pop = {
    let res = List.hd_exn(stack);
    stack = (
      switch (List.tl(stack)) {
      | Some(x) => x
      | None => []
      }
    );
    res;
  };
  pub size = List.length(stack);
};

let () = {
  let int_stack = new stack;
  int_stack#push(13);
  int_stack#push(1);
  printf("%d\n", int_stack#pop);
  printf("%d\n", int_stack#pop);

  let float_stack = new stack;
  float_stack#push(0.13);
  float_stack#push(3.14);
  printf("%F\n", float_stack#pop);
  printf("%F\n", float_stack#pop);
};
