let one_arg_function = (func, x) => func(x);

/* Same */
/* 二つの引数を取る関数 */
let f = (x, y) => x + y;
let f1 = (x, y) => x + y;

/* 一つの引数を取る関数を返す、一つの引数を取る関数 */
let f2 = (x, y) => x + y;

let f3 =
  fun
  | Some(x) => x
  | None => exit(2);

let () = Printf.printf("%d\n", one_arg_function(n => n * n, 10));
