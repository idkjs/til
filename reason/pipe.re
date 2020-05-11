open Str;
open Printf;

let l = [5, 4, 3, 2, 1];

/* |> : 'a -> ('a -> 'b) -> 'b */

/* pipe_sample: int list -> string list  */
let pipe_sample = list_ =>
  /* 全てにの要素に2を掛け */
  list_
  |> List.map(e => e * 2)
  /* 4で割り切れないもののみを残し */
  |> List.filter(e => e mod 4 != 0)
  /* 文字列化 */
  |> List.map(sprintf("%d"));

let div = (a, b) => a / b;
let abc = (a, b, c) => (a, b, c);

let () = {
  List.iter(e => printf("%S\n", e), pipe_sample(l));
  let li: list(int) = (
    "1 2 3 4 5" |> split(regexp(" ")) |> List.map(e => int_of_string(e)):
      list(int)
  );

  List.iter(s => Printf.printf("%d\n", s), li);
  /* pipeで渡されたものは最後の引数になる */
  printf("a / b = %d\n", 4 |> div(30));
  let (a, b, c) = 3 |> abc(1, 2);
  printf("a: %d, b: %d, c: %d\n", a, b, c);
};
